
//
//
//							rpc_utility_funcs.cpp
//
// 						Aaron Bowen and Spencer Perry
// 
//				Useful function implementations written for the stub
// 



#include "rpcstub_utils.h"

// Important: this routine must leave the sock open but at EOF
// when eof is read from client. 
// This function parses the size of the json message from the socket
size_t read_message_size() {
  char buffer[30];
  char *buff_ptr = buffer;  // next char to read
  ssize_t readlen;          // amount of data read from socket

  for (unsigned int i = 0; i < sizeof(buffer); i++) {
    readlen = RPCSTUBSOCKET->read(buff_ptr, 1);  // read a byte

    if (*buff_ptr == '{') { return stoi(string(buffer)); }
    buff_ptr++;
    
    // Error Handle 
    if (readlen == 0) {
    c150debug->printf(C150RPCDEBUG,"simplefunction.stub: read zero length message, checking EOF");
      if (RPCSTUBSOCKET-> eof()) {
        c150debug->printf(C150RPCDEBUG,"simplefunction.stub: EOF signaled on input");
      } else {
      throw C150Exception("simplefunction.stub: unexpected zero length read without eof");
      }
    }
  }

  // catchall exception
  throw C150Exception("Finding JSON size failed.");
} 

// This function puts the JSON string in the buffer
string read_message(size_t message_size) {
  char buffer[message_size];
  char *buff_ptr = buffer;  // next char to read
  ssize_t readlen;          // amount of data read from socket
  bool read_null;

  for (unsigned int i = 0; i < sizeof(buffer); i++) {
    readlen = RPCSTUBSOCKET->read(buff_ptr, 1);  // read a byte

    if (readlen == 0) {
      break;
    } else if (*buff_ptr++ == '\0') {
      read_null = true;
      break;
    }
  }

  // Error Handling 
  if (readlen == 0) {
    c150debug->printf(C150RPCDEBUG,"simplefunction.stub: read zero length message, checking EOF");
    if (RPCSTUBSOCKET-> eof()) {
      c150debug->printf(C150RPCDEBUG,"simplefunction.stub: EOF signaled on input");
    } else {
      throw C150Exception("simplefunction.stub: unexpected zero length read without eof");
    }
  } else if (!read_null) { // If we didn't get a null, input message was poorly formatted
    throw C150Exception("simplefunction.stub: method name not null terminated or too long");
  }

  // buffer to string
  string message(buffer);
  message = to_string(message_size) + "{" + message; // manually reformat message

  return message;
}


// each object is preceeded with a character length
// e.g. "34{ ... }"
size_t extract_object_length(string json) {
  size_t obj_start = json.find('{');  // skip over sizing info
  return stoi(json.substr(0, obj_start));
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

bool extract_bool(string json, string key) {
  regex pair_regex("\"(" + key + ")\":(true|false)[,}\\]]"); // "(my_key)":(true|false)[,}\]]
  smatch pair_matches;
  
  bool pair_exists = regex_search(json, pair_matches, pair_regex);
  if (!pair_exists) { throw runtime_error("Search for bool belonging to key '" + key + "' failed."); }
  
  return pair_matches[2] == "true";
}

// Extracts the first instance of the key in the string, regardless of nesting level.
// If we care about nesting level, then we need to just parse the JSON fully before
// we do any data extraction/etc. on it.
string extract_string(string json, string key) {
  regex pair_regex("\"(" + key + ")\":\"([^\\\"]+)\"[,}\\]]"); // "(my_key)":"([^\"]+)"[,}\]]
  smatch pair_matches;
  
  bool pair_exists = regex_search(json, pair_matches, pair_regex);
  if (!pair_exists) { throw runtime_error("Search for string belonging to key '" + key + "' failed."); }
  
  // cout << "Prefix: '" << pair_matches.prefix() << "'\n";
  // cout << "full match: '" << pair_matches[0] << "'\n";
  // cout << "key: '" << pair_matches[1] << "'\n";
  // cout << "value: '" << pair_matches[2] << "'\n";
  // cout << "Suffix: '" << pair_matches.suffix() << "\'\n";
  
  return pair_matches[2];
}

// extracts an array from an object correctly only if it is the last key
// TODO: refind to take into account the prepended length
string extract_array(string json, string key) {
  regex pair_regex("\"(" + key + ")\":[0-9]+\\[([0-9]+\\{.+\\})\\]");
  smatch pair_matches;

  bool pair_exists = regex_search(json, pair_matches, pair_regex);
  if (!pair_exists) { throw runtime_error("Search for array belonging to key '" + key + "' failed."); }
  return pair_matches[2]; 
}


// extracts an array from an object correctly only if it is the last key
// TODO: refind to take into account the prepended length
string extract_object(string json, string key) {
  regex pair_regex("\"(" + key + ")\":([0-9]+\\{.+\\})");
  smatch pair_matches;

  bool pair_exists = regex_search(json, pair_matches, pair_regex);
  if (!pair_exists) { throw runtime_error("Search for object belonging to key '" + key + "' failed."); }
  return pair_matches[2]; 
}
