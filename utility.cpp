
using namespace std;
#include <string>

#include "rpcstubhelper.h"
#include "rpcproxyhelper.h"
#include "utility.h"

#include <cstdio>
#include <cstring>
#include <string>
#include "c150debug.h"
#include <regex>
#include <typeinfo>

using namespace C150NETWORK;  // for all the comp150 utilities 

//
// TCP message utility functions
//

size_t read_message_size(C150StreamSocket *socket) {
  char buffer[30];
  char *buff_ptr = buffer;  // next char to read
  ssize_t readlen;          // amount of data read from socket

  for (unsigned int i = 0; i < sizeof(buffer); i++) {
    readlen = socket->read(buff_ptr, 1);  // read a byte

    if (*buff_ptr == '{') { return stoi(string(buffer)); }
    buff_ptr++;
    
    // error handling
    if (readlen == 0) {
      c150debug->printf(C150RPCDEBUG, "Read zero length message, checking EOF");
      if (socket-> eof()) {
        c150debug->printf(C150RPCDEBUG, "EOF signaled on input");
      } else {
        throw C150Exception("Unexpected zero length read without EOF");
      }
    }
  }

  // catchall exception
  throw C150Exception("Finding JSON size failed.");
} 

string read_message(C150StreamSocket *socket, size_t message_size) {
  char buffer[message_size];
  char *buff_ptr = buffer;  // next char to read
  ssize_t readlen;          // amount of data read from socket
  bool read_null;

  for (unsigned int i = 0; i < sizeof(buffer); i++) {
    readlen = socket->read(buff_ptr, 1);  // read a byte

    if (readlen == 0) {
      break;
    } else if (*buff_ptr++ == '\0') {
      read_null = true;
      break;
    }
  }

  // error handling 
  if (readlen == 0) {
    c150debug->printf(C150RPCDEBUG,"Read zero length message, checking EOF");
    if (socket-> eof()) {
      c150debug->printf(C150RPCDEBUG,"EOF signaled on input");
    } else {
      throw C150Exception("Unexpected zero length read without EOF");
    }
  } else if (!read_null) { // If we didn't get a null, input message was poorly formatted
    throw C150Exception("Method name not null terminated or too long");
  }

  // buffer to string
  string message(buffer);
  message = to_string(message_size) + "{" + message; // manually reformat message

  return message;
}

//
// JSON utility functions.
// 
// "extract_xxx" functions extract the value from key/value pairs from a JSON object.
//

string consume_object(string &json) {
  size_t obj_start = json.find('{');

  // check for empty array
  if (obj_start == json.npos) { return ""; }

  size_t obj_len = stoi(json.substr(json[0] == ',' ? 1 : 0, obj_start));

  // consume the object
  string obj = json.substr(obj_start, obj_len);
  json = json.substr(obj_start + obj_len, json.npos);
  
  return obj;
}

string extract_array(string json, string key) {
  regex pair_regex("\"(" + key + ")\":([0-9]+\\[[0-9]+\\{.+\\}\\])");
  smatch pair_matches;

  bool pair_exists = regex_search(json, pair_matches, pair_regex);
  if (!pair_exists) { throw runtime_error("Search for array belonging to key '" + key + "' failed."); }

  // use to the array length to truncate the string selection at the end of the array
  string arr = pair_matches[2];
  regex arr_regex("([0-9]+)\\[([0-9]+\\{.+\\})\\]");
  smatch arr_matches;

  bool arr_exists = regex_search(arr, arr_matches, arr_regex);
  if (!arr_exists) { throw runtime_error("Array belonging to key '" + key + "' not prepended with length."); }

  size_t arr_size = stoi(arr_matches[1]);
  size_t arr_start = arr.find('[');

  // select array, but remove outer brackets
  return arr.substr(arr_start + 1, arr_size - 2);
}

bool extract_bool(string json, string key) {
  regex pair_regex("\"(" + key + ")\":(true|false)[,}\\]]"); // "(my_key)":(true|false)[,}\]]
  smatch pair_matches;
  
  bool pair_exists = regex_search(json, pair_matches, pair_regex);
  if (!pair_exists) { throw runtime_error("Search for bool belonging to key '" + key + "' failed."); }
  
  return pair_matches[2] == "true";
}

float extract_float(string json, string key) {
  // Warning: regex requires at least one digit preceding the decimal
  regex pair_regex("\"(" + key + ")\":(-?[0-9]+[\\.][0-9]*)[,}\\]]"); // "(my_key)":(-?[0-9]+[\.][0-9]*)[,}\]]
  smatch pair_matches;
  
  bool pair_exists = regex_search(json, pair_matches, pair_regex);
  if (!pair_exists) { throw runtime_error("Search for float belonging to key '" + key + "' failed."); }
  
  return stof(pair_matches[2]);
}

int extract_int(string json, string key) {
  regex pair_regex("\"(" + key + ")\":(-?[0-9]+)[,}\\]]"); // "(my_key)":(-?[0-9]+)[,}\]]
  smatch pair_matches;
  
  bool pair_exists = regex_search(json, pair_matches, pair_regex);
  if (!pair_exists) { throw runtime_error("Search for int belonging to key '" + key + "' failed."); }
  
  return stoi(pair_matches[2]);
}

string extract_object(string json, string key) {
  // extract the object and everything following it in the json string
  regex pair_regex("\"(" + key + ")\":([0-9]+\\{.+\\})");
  smatch pair_matches;

  bool pair_exists = regex_search(json, pair_matches, pair_regex);
  if (!pair_exists) { throw runtime_error("Search for object belonging to key '" + key + "' failed."); }

  // use to the obj length to truncate the string selection at the end of the obj
  string obj = pair_matches[2];
  regex obj_regex("([0-9]+)(\\{.+\\})");
  smatch obj_matches;

  bool obj_exists = regex_search(obj, obj_matches, obj_regex);
  if (!obj_exists) { throw runtime_error("Object belonging to key '" + key + "' not prepended with length."); }

  size_t obj_size = stoi(obj_matches[1]);
  size_t obj_start = obj.find('{');
  
  return obj.substr(obj_start, obj_size);
}

string extract_string(string json, string key) {
  regex pair_regex("\"(" + key + ")\":\"([^\\\"]+)\"[,}\\]]"); // "(my_key)":"([^\"]+)"[,}\]]
  smatch pair_matches;
  
  bool pair_exists = regex_search(json, pair_matches, pair_regex);
  if (!pair_exists) { throw runtime_error("Search for string belonging to key '" + key + "' failed."); }
  
  return pair_matches[2];
}
