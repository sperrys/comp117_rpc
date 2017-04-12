using namespace std;
#include <string>

#include <sstream>

#include "arithmetic.idl"
#include "lotsofstuff.idl"

#include "serialization.h"

const string VALUE_KEY = "value";
const string TYPE_KEY = "type";
const string STRUCT_KEY = "is_struct";
const string ARRAY_KEY = "is_array";

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

string serialize_int_3(int my_int_3[3]) {
  vector<string> param_pairs;

  // value to string conversion
  string type = "int[3]";
  vector<string> elements;
  for (int i = 0; i < 3; i++) {
    elements.push_back(serialize_int(my_int_3[i]));
  }
  stringstream value;
  value << serialize_array(elements);

  // compose the inner description object
  param_pairs.push_back(serialize_pair(TYPE_KEY, type, "string"));
  param_pairs.push_back(serialize_pair(STRUCT_KEY, "false", "bool"));
  param_pairs.push_back(serialize_pair(ARRAY_KEY, "true", "bool"));
  param_pairs.push_back(serialize_pair(VALUE_KEY, value.str(), "array"));

  return serialize_object(param_pairs);
}

string serialize_Person(Person my_Person) {
  vector<string> param_pairs;

  // value to string conversion
  string type = "Person";
  vector<string> elements;
  elements.push_back(serialize_pair("firstname", serialize_string(my_Person.firstname), "object"));
  elements.push_back(serialize_pair("lastname", serialize_string(my_Person.lastname), "object"));
  elements.push_back(serialize_pair("age", serialize_int(my_Person.age), "object"));
  elements.push_back(serialize_pair("favorite_numbers", serialize_int_3(my_Person.favorite_numbers), "object"));

  stringstream value;
  value << serialize_object(elements);

  // compose the inner description object
  param_pairs.push_back(serialize_pair(TYPE_KEY, type, "string"));
  param_pairs.push_back(serialize_pair(STRUCT_KEY, "true", "bool"));
  param_pairs.push_back(serialize_pair(ARRAY_KEY, "false", "bool"));
  param_pairs.push_back(serialize_pair(VALUE_KEY, value.str(), "object"));

  return serialize_object(param_pairs);
}

string serialize_people_array(Person p[3]) {
  vector<string> param_pairs;

  // value to string conversion
  string type = "p[3]";
  vector<string> elements;
  for (int i = 0; i < 3; i++) {
    elements.push_back(serialize_Person(p[i]));
  }
  stringstream value;
  value << serialize_array(elements);

  // compose the inner description object
  param_pairs.push_back(serialize_pair(TYPE_KEY, type, "string"));
  param_pairs.push_back(serialize_pair(STRUCT_KEY, "false", "bool"));
  param_pairs.push_back(serialize_pair(ARRAY_KEY, "true", "bool"));
  param_pairs.push_back(serialize_pair(VALUE_KEY, value.str(), "array"));

  return serialize_object(param_pairs);
}

string serialize_ThreePeople(ThreePeople my_ThreePeople) {
  vector<string> param_pairs;

  // value to string conversion
  string type = "ThreePeople";
  vector<string> elements;
  elements.push_back(serialize_pair("p1", serialize_Person(my_ThreePeople.p1), "object"));
  elements.push_back(serialize_pair("p2", serialize_Person(my_ThreePeople.p2), "object"));
  elements.push_back(serialize_pair("p3", serialize_Person(my_ThreePeople.p3), "object"));
  stringstream value;
  value << serialize_object(elements);

  // compose the inner description object
  param_pairs.push_back(serialize_pair(TYPE_KEY, type, "string"));
  param_pairs.push_back(serialize_pair(STRUCT_KEY, "true", "bool"));
  param_pairs.push_back(serialize_pair(ARRAY_KEY, "false", "bool"));
  param_pairs.push_back(serialize_pair(VALUE_KEY, value.str(), "object"));

  return serialize_object(param_pairs);
}
