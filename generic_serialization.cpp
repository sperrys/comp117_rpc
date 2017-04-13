
//   
//     generic_serialization.cpp 
//
//     Aaron Bowen and Spencer Perry
//
//     This is the generic_serialization file 
//     These are the serializations that are not dependent on 
//     the IDL File 

using namespace std;
#include <string>

#include "generic_serialization.h" 

string serialize_pair(string key, string value, string json_type) {
  stringstream pair;
  if (json_type == "string" || json_type == "char") {
    pair << "\"" << key << "\":\"" << value << "\"";
  } else {
    pair << "\"" << key << "\":" << value;
  }
  return pair.str();
}

string serialize_object(vector<string> pairs) {
  stringstream obj;
  obj << "{";
  for (unsigned int i = 0; i < pairs.size(); i++) {
    obj << pairs[i];
    if (i != pairs.size() - 1) obj << ",";
  }
  obj << "}";
  return to_string(obj.str().length()) + obj.str();
}

string serialize_array(vector<string> objects) {
  stringstream arr;
  arr << "[";
  for (unsigned int i = 0; i < objects.size(); i++) {
    arr << objects[i];
    if (i != objects.size() - 1) arr << ",";
  }
  arr << "]";
  return to_string(arr.str().length()) + arr.str();
}

// 
// Returns an param description JSON object for Basics Types 
// 

string serialize_int(int my_int) {
  vector<string> param_pairs;
  
  // value to string conversion
  string type = "int";
  stringstream value;
  value << my_int;

  // compose the inner description object
  param_pairs.push_back(serialize_pair(TYPE_KEY, type, "string"));
  param_pairs.push_back(serialize_pair(STRUCT_KEY, "false", "bool"));
  param_pairs.push_back(serialize_pair(ARRAY_KEY, "false", "bool"));
  param_pairs.push_back(serialize_pair(VALUE_KEY, value.str(), "int"));

  return serialize_object(param_pairs);
}

string serialize_bool(bool my_bool) {
  vector<string> param_pairs;

  // value to string conversion
  string type = "bool";
  stringstream value;
  value << my_bool;

  // compose the inner description object
  param_pairs.push_back(serialize_pair(TYPE_KEY, type, "string"));
  param_pairs.push_back(serialize_pair(STRUCT_KEY, "false", "bool"));
  param_pairs.push_back(serialize_pair(ARRAY_KEY, "false", "bool"));
  param_pairs.push_back(serialize_pair(VALUE_KEY, value.str(), "bool"));

  return serialize_object(param_pairs);
}

string serialize_string(string my_string) {

  vector<string> param_pairs;
  string type = "string";

  // compose the inner description object
  param_pairs.push_back(serialize_pair(TYPE_KEY, type, "string"));
  param_pairs.push_back(serialize_pair(STRUCT_KEY, "false", "bool"));
  param_pairs.push_back(serialize_pair(ARRAY_KEY, "false", "bool"));
  param_pairs.push_back(serialize_pair(VALUE_KEY, my_string, "string"));

  return serialize_object(param_pairs);
}

string serialize_char(char my_char) {
  vector<string> param_pairs;

  // value to string conversion
  string type = "char";
  stringstream value;
  value << my_char;

  // compose the inner description object
  param_pairs.push_back(serialize_pair(TYPE_KEY, type, "string"));
  param_pairs.push_back(serialize_pair(STRUCT_KEY, "false", "bool"));
  param_pairs.push_back(serialize_pair(ARRAY_KEY, "false", "bool"));
  param_pairs.push_back(serialize_pair(VALUE_KEY, value.str(), "char"));

  return serialize_object(param_pairs);
}

string serialize_float(float my_float) {
  vector<string> param_pairs;

  // value to string conversion
  string type = "float";
  stringstream value;
  value << my_float;

  // compose the inner description object
  param_pairs.push_back(serialize_pair(TYPE_KEY, type, "string"));
  param_pairs.push_back(serialize_pair(STRUCT_KEY, "false", "bool"));
  param_pairs.push_back(serialize_pair(ARRAY_KEY, "false", "bool"));
  param_pairs.push_back(serialize_pair(VALUE_KEY, value.str(), "float"));

  return serialize_object(param_pairs);
}

string serialize_void() {
  vector<string> param_pairs;

  // value to string conversion
  string type = "void";
  stringstream value;
  value << "null";

  // compose the inner description object
  param_pairs.push_back(serialize_pair(TYPE_KEY, type, "string"));
  param_pairs.push_back(serialize_pair(STRUCT_KEY, "false", "bool"));
  param_pairs.push_back(serialize_pair(ARRAY_KEY, "false", "bool"));
  param_pairs.push_back(serialize_pair(VALUE_KEY, value.str(), "null"));

  return serialize_object(param_pairs);
}
