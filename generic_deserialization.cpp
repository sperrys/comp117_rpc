// 
//	 generic_deserialization.cpp 
// 
//   Aaron Bowen, Spencer Perry
// 
//   This is the implementation file for all of the generic deserialization 
//   functions that aren't dependent on the idl. 


using namespace std;

#include <string>
#include <regex>

#include "generic_deserialization.h"

int deserialize_int(string int_object) {
  return extract_int(int_object, "value");
}

string deserialize_string(string string_object) {
  return extract_string(string_object, "value");
}

float deserialize_float(string float_object) {
  return extract_float(float_object, "value");
}

bool deserialize_bool(string bool_object) {
  return extract_bool(bool_object, "value");
}

void deserialize_void(string void_object) {
  return; // nothing meaningful to extract
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
  // first check for empty array
  regex empty_regex("\"(" + key + ")\":(2\\[\\])");
  smatch empty_matches;

  bool empty_array = regex_search(json, empty_matches, empty_regex);
  if (empty_array) { return ""; }

  // if the array isn't empty, extract the contents
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
  // first check for empty object
  regex empty_regex("\"(" + key + ")\":(2\\{\\})");
  smatch empty_matches;

  bool empty_obj = regex_search(json, empty_matches, empty_regex);
  if (empty_obj) { return ""; }

  // if the object isn't empty, extract the contents
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