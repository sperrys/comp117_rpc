using namespace std;
#include <string>

#include <regex>

#include "arithmetic.idl"
#include "lotsofstuff.idl"

#include "deserialization.h"

int* deserialize_int_3(string int_3_obj) {
  int *my_int = new int[3];
  string ints = extract_array(int_3_obj, "value");

  for (int i = 0; i < 3; i++) {
    my_int[i] = deserialize_int(consume_object(ints));
  }

  return my_int;
}

Person* deserialize_people_3(string people_3_obj) {
  Person *my_people = new Person[3];
  string people = extract_array(people_3_obj, "value");

  for (int i = 0; i < 3; i++) {
    my_people[i] = deserialize_person(consume_object(people));
  }

  return my_people;
}

Person deserialize_person(string person_obj) {
  Person *my_person = new struct Person;
  string value_obj = extract_object(person_obj, "value");

  my_person->firstname = deserialize_string(extract_object(value_obj, "firstname"));
  my_person->lastname = deserialize_string(extract_object(value_obj, "lastname"));
  my_person->age = deserialize_int(extract_object(value_obj, "age"));
  
  // can't assign arrays directly, so need to loop through to assign each value
  int *favorite_numbers = deserialize_int_3(extract_object(value_obj, "favorite_numbers"));
  for (int i = 0; i < 3; i++) { my_person->favorite_numbers[i] = favorite_numbers[i]; }
 
  return *my_person;
}

ThreePeople deserialize_ThreePeople(string ThreePeople_obj) {
  ThreePeople* people = new struct ThreePeople;
  string value_obj = extract_object(ThreePeople_obj, "value");

  people->p1 = deserialize_person(extract_object(value_obj, "p1"));
  people->p2 = deserialize_person(extract_object(value_obj, "p2"));
  people->p3 = deserialize_person(extract_object(value_obj, "p3"));

  return *people;
}

int deserialize_int(string int_object) {
  return extract_int(int_object, "value");
}

string deserialize_string(string string_object) {
  return extract_string(string_object, "value");
}

float deserialize_float(string float_object) {
  return extract_float(float_object, "value");
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
