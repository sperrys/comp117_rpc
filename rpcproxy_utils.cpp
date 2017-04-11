

//
//               rpcproxy_utils.cpp 
//              
//            Aaron Bowen and Spencer Perry
//          
//
//         function declarations for useful proxy functions
//
//

#include "rpcproxy_utils.h"

const string VALUE_KEY = "value";
const string TYPE_KEY = "type";
const string STRUCT_KEY = "is_struct";
const string ARRAY_KEY = "is_array";


string jsonify_pair(string key, string value, string json_type) {
  stringstream pair;
  if (json_type == "string" || json_type == "char") {
    pair << "\"" << key << "\":\"" << value << "\"";
  } else {
    pair << "\"" << key << "\":" << value;
  }
  return pair.str();
}

string jsonify_object(vector<string> pairs) {
  stringstream obj;
  obj << "{";
  for (unsigned int i = 0; i < pairs.size(); i++) {
    obj << pairs[i];
    if (i != pairs.size() - 1) obj << ",";
  }
  obj << "}";
  return to_string(obj.str().length()) + obj.str();
}

string jsonify_array(vector<string> objects) {
  stringstream arr;
  arr << "[";
  for (unsigned int i = 0; i < objects.size(); i++) {
    arr << objects[i];
    if (i != objects.size() - 1) arr << ",";
  }
  arr << "]";
  return to_string(arr.str().length()) + arr.str();
}

// returns an param description JSON object
string handle_int(int my_int) {
  vector<string> param_pairs;
  
  // value to string conversion
  string type = "int";
  stringstream value;
  value << my_int;

  // compose the inner description object
  param_pairs.push_back(jsonify_pair(TYPE_KEY, type, "string"));
  param_pairs.push_back(jsonify_pair(STRUCT_KEY, "false", "bool"));
  param_pairs.push_back(jsonify_pair(ARRAY_KEY, "false", "bool"));
  param_pairs.push_back(jsonify_pair(VALUE_KEY, value.str(), "int"));

  return jsonify_object(param_pairs);
}

string handle_bool(bool my_bool) {
  vector<string> param_pairs;

  // value to string conversion
  string type = "bool";
  stringstream value;
  value << my_bool;

  // compose the inner description object
  param_pairs.push_back(jsonify_pair(TYPE_KEY, type, "string"));
  param_pairs.push_back(jsonify_pair(STRUCT_KEY, "false", "bool"));
  param_pairs.push_back(jsonify_pair(ARRAY_KEY, "false", "bool"));
  param_pairs.push_back(jsonify_pair(VALUE_KEY, value.str(), "bool"));

  return jsonify_object(param_pairs);
}

string handle_string(string my_string) {

  vector<string> param_pairs;
  string type = "string";

  // compose the inner description object
  param_pairs.push_back(jsonify_pair(TYPE_KEY, type, "string"));
  param_pairs.push_back(jsonify_pair(STRUCT_KEY, "false", "bool"));
  param_pairs.push_back(jsonify_pair(ARRAY_KEY, "false", "bool"));
  param_pairs.push_back(jsonify_pair(VALUE_KEY, my_string, "string"));

  return jsonify_object(param_pairs);
}

string handle_char(char my_char) {
  vector<string> param_pairs;

  // value to string conversion
  string type = "char";
  stringstream value;
  value << my_char;

  // compose the inner description object
  param_pairs.push_back(jsonify_pair(TYPE_KEY, type, "string"));
  param_pairs.push_back(jsonify_pair(STRUCT_KEY, "false", "bool"));
  param_pairs.push_back(jsonify_pair(ARRAY_KEY, "false", "bool"));
  param_pairs.push_back(jsonify_pair(VALUE_KEY, value.str(), "char"));

  return jsonify_object(param_pairs);
}