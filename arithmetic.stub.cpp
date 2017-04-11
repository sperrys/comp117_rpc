// --------------------------------------------------------------
//
//                        simplefunction.stub.cpp
//
//        Author: Noah Mendelsohn         
//   
//       This is a hand-crafted demonstration stub.
//
//       It implements a very simple protocol that works only
//       for functions with no arguments and void return. Invocation
//       requests are just the null terminated function name; 
//       Responses are the null terminated words DONE or BAD.
//       You'll have to do something much more sophisticated
//       for routines that accept and return values. (And you might
//       not want to use nulls as delimiters in your protocol, since
//       some of the values you send might contain them!)
//
//       For your project, your "rpcgen" program will generate
//       stubs like this one automatically from the idl
//       file. Note that this stub also #includes the 
//       simplefunctions.idl file. Of course, your rpcgen
//       program will change that, as well as the number
//       of functions generated. More importantly, it will
//       generate code to handle function arguments and
//       return values.
//
//       You can structure your stub however you like. This
//       one relies on the container to loop calling 
//       dispatchFunction() until eof is reached, but you
//       can do it other ways. In general, there needs to
//       be some place where you read the stream to see
//       which function to call; how you do that is up to you.
//
//       Copyright: 2012 Noah Mendelsohn
//
// --------------------------------------------------------------

// IMPORTANT! WE INCLUDE THE IDL FILE AS IT DEFINES THE INTERFACES
// TO THE FUNCTIONS WE'RE IMPLEMENTING. THIS MAKES SURE THE
// CODE HERE ACTUALLY MATCHES THE REMOTED INTERFACE

using namespace std;
#include <string>

#include "arithmetic.idl"
#include "lotsofstuff.idl"

#include "rpcstubhelper.h"

#include <cstdio>
#include <cstring>
#include <string>
#include "c150debug.h"
#include <regex>

using namespace C150NETWORK;  // for all the comp150 utilities 



// ======================================================================
//
//                        COMMON SUPPORT FUNCTIONS
//
// ======================================================================

// JSON FUNCS
size_t read_message_size();
string read_message(size_t message_size);

// PARSING FUNCS
string extract_string(string json, string key);
int extract_int(string json, string key);
string extract_array(string json, string key);
string consume_object(string &json);

// STRING TO CPP FUNCS
int handle_int(string json);
float handle_float(string json);
string handle_string(string json);

int *handle_int_3(string json);
Person* handle_people_3(string json);

Person handle_person(string person_obj);
ThreePeople handle_ThreePeople(string ThreePeople_obj);

// ======================================================================
//                             STUBS
//
//    Each of these is generated to match the signature of the 
//    function for which it is a stub. The names are prefixed with "__"
//    to keep them distinct from the actual routines, which we call!
//
//    Note that when functions take arguments, these are the routines
//    that will read them from the input stream. These routines should
//    be generated dynamically from your rpcgen program (and so should the
//    code above).
//
// ======================================================================

void __add(string json, int param_count, string params) {
  int x = handle_int(consume_object(params));
  int y = handle_int(consume_object(params));
  //
  // Time to actually call the function 
  //
  c150debug->printf(C150RPCDEBUG,"simplefunction.stub.cpp: invoking add()");
  add(x, y);

  //
  // Send the response to the client
  //
  // If func1 returned something other than void, this is
  // where we'd send the return value back.
  //
  c150debug->printf(C150RPCDEBUG,"simplefunction.stub.cpp: returned from  func1() -- responding to client");
  //RPCSTUBSOCKET->write(doneBuffer, strlen(doneBuffer)+1);
}

void __sum(string json, int param_count, string params) {
  int *x = handle_int_3(consume_object(params));
  cout << *x << endl;
  //
  // Time to actually call the function 
  //
  c150debug->printf(C150RPCDEBUG,"simplefunction.stub.cpp: invoking sum()");
  // sum(x);

  //
  // Send the response to the client
  //
  // If func1 returned something other than void, this is
  // where we'd send the return value back.
  //
  c150debug->printf(C150RPCDEBUG,"simplefunction.stub.cpp: returned from  func1() -- responding to client");
  //RPCSTUBSOCKET->write(doneBuffer, strlen(doneBuffer)+1);
}

void __person_func(string json, int param_count, string params) {
  Person my_person = handle_person(consume_object(params));

  //
  // Time to actually call the function 
  //
  c150debug->printf(C150RPCDEBUG,"simplefunction.stub.cpp: invoking sum()");
  // sum(x);

  //
  // Send the response to the client
  //
  // If func1 returned something other than void, this is
  // where we'd send the return value back.
  //
  c150debug->printf(C150RPCDEBUG,"simplefunction.stub.cpp: returned from  func1() -- responding to client");
  //RPCSTUBSOCKET->write(doneBuffer, strlen(doneBuffer)+1);
}

void __people_func(string json, int param_count, string params) {
  ThreePeople people = handle_ThreePeople(consume_object(params));

  cout << "P1 " << people.p1.firstname << ", 1st favorite number: " <<  people.p1.favorite_numbers[0] << ", " << people.p1.favorite_numbers[1] << ", " << people.p1.favorite_numbers[2] << endl;
  cout << "P2 " << people.p2.firstname << ", 2nd favorite number: " <<  people.p2.favorite_numbers[0] << ", " << people.p2.favorite_numbers[1] << ", " << people.p2.favorite_numbers[2] << endl;
  cout << "P3 " << people.p3.firstname << ", 3rd favorite number: " <<  people.p3.favorite_numbers[0] << ", " << people.p3.favorite_numbers[1] << ", " << people.p3.favorite_numbers[2] << endl;
  //
  // Time to actually call the function 
  //
  c150debug->printf(C150RPCDEBUG,"simplefunction.stub.cpp: invoking sum()");
  // sum(x);

  //
  // Send the response to the client
  //
  // If func1 returned something other than void, this is
  // where we'd send the return value back.
  //
  c150debug->printf(C150RPCDEBUG,"simplefunction.stub.cpp: returned from  func1() -- responding to client");
  //RPCSTUBSOCKET->write(doneBuffer, strlen(doneBuffer)+1
}

void __people_array(string json, int param_count, string params) {
  Person *people = handle_people_3(consume_object(params));
  cout << people[0].firstname << endl;

  //
  // Time to actually call the function 
  //
  c150debug->printf(C150RPCDEBUG,"simplefunction.stub.cpp: invoking sum()");
  // sum(x);

  //
  // Send the response to the client
  //
  // If func1 returned something other than void, this is
  // where we'd send the return value back.
  //
  c150debug->printf(C150RPCDEBUG,"simplefunction.stub.cpp: returned from  func1() -- responding to client");
  //RPCSTUBSOCKET->write(doneBuffer, strlen(doneBuffer)+1
}


void __subtract(string json, int params) {
  //char doneBuffer[5] = "DONE";
  //RPCSTUBSOCKET->write(doneBuffer, strlen(doneBuffer)+1);
}

void __multiply(string json, int params) {
  //char doneBuffer[5] = "DONE";
  //RPCSTUBSOCKET->write(doneBuffer, strlen(doneBuffer)+1);

}

void __divide(string json, int params) {
  //char doneBuffer[5] = "DONE";
  //RPCSTUBSOCKET->write(doneBuffer, strlen(doneBuffer)+1);
}

// Pseudo-stub for missing functions.
void __badFunction(string func_name) {
  //char doneBuffer[5] = "BAD";  // to write magic value DONE + null


  //
  // Send the response to the client indicating bad function
  //

  c150debug->printf(C150RPCDEBUG,"simplefunction.stub.cpp: received call for nonexistent function %s()", func_name);
  //RPCSTUBSOCKET->write(doneBuffer, strlen(doneBuffer)+1);
}

// Called when we're ready to read a new invocation request from the stream
void dispatchFunction() {
  // Read the JSON message in
  string json_str = read_message(read_message_size());

  cout << "JSON: " << json_str << endl;

  string func_name = extract_string(json_str, "method");
  // cout << "func_name: " << func_name << endl;
  int param_count = extract_int(json_str, "param_count");
  // cout << "param_count: " << param_count << endl;
  string params = extract_array(json_str, "params");
  // cout << "params: " << params << endl;

  if (!RPCSTUBSOCKET->eof()) {
    if (func_name == "add")
      __add(json_str, param_count, params);
    else   if (func_name == "person_func")
      __person_func(json_str, param_count, params);
    else   if (func_name == "people_func")
      __people_func(json_str, param_count, params);
    else   if (func_name == "sum")
      __sum(json_str, param_count, params);
    else   if (func_name == "subtract")
      __subtract(json_str, param_count);
    else   if (func_name == "multiply")
      __multiply(json_str, param_count);
    else   if (func_name == "divide")
      __divide(json_str, param_count);
    else   if  (func_name == "people_array")
      __people_array(json_str, param_count, params);
    else
      __badFunction(func_name);
  }
}

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


float extract_float(string json, string key) {
  // Warning: regex requires at least one digit preceding the decimal
  regex pair_regex("\"(" + key + ")\":(-?[0-9]+[\\.][0-9]*)[,}\\]]"); // "(my_key)":(-?[0-9]+[\.][0-9]*)[,}\]]
  smatch pair_matches;
  
  bool pair_exists = regex_search(json, pair_matches, pair_regex);
  if (!pair_exists) { throw runtime_error("Search for float belonging to key '" + key + "' failed."); }
  
  return stof(pair_matches[2]);
}

int extract_int(string json, string key) {
  cout << "searching: " << json << endl;
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

string extract_string(string json, string key) {
  regex pair_regex("\"(" + key + ")\":\"([^\\\"]+)\"[,}\\]]"); // "(my_key)":"([^\"]+)"[,}\]]
  smatch pair_matches;
  
  bool pair_exists = regex_search(json, pair_matches, pair_regex);
  if (!pair_exists) { throw runtime_error("Search for string belonging to key '" + key + "' failed."); }
  
  return pair_matches[2];
}

// extracts a nested array from an json object (without the outer brackets '[]')
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

// extracts a nested object from an json object
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

// consumes the next object in an array (NOTE: pass string by reference)
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

int* handle_int_3(string int_3_obj) {
  int *my_int = new int[3];
  string ints = extract_array(int_3_obj, "value");

  for (int i = 0; i < 3; i++) {
    my_int[i] = handle_int(consume_object(ints));
  }

  return my_int;
}


Person* handle_people_3(string people_3_obj) {
  Person *my_people = new Person[3];
  string people = extract_array(people_3_obj, "value");

  for (int i = 0; i < 3; i++) {
    my_people[i] = handle_person(consume_object(people));
  }

  return my_people;
}

Person handle_person(string person_obj) {
  Person *my_person = new struct Person;
  string value_obj = extract_object(person_obj, "value");

  my_person->firstname = handle_string(extract_object(value_obj, "firstname"));
  my_person->lastname = handle_string(extract_object(value_obj, "lastname"));
  my_person->age = handle_int(extract_object(value_obj, "age"));
  
  // can't assign arrays directly, so need to loop through to assign each value
  int *favorite_numbers = handle_int_3(extract_object(value_obj, "favorite_numbers"));
  for (int i = 0; i < 3; i++) { my_person->favorite_numbers[i] = favorite_numbers[i]; }
 
  return *my_person;
}

ThreePeople handle_ThreePeople(string ThreePeople_obj) {
  ThreePeople* people = new struct ThreePeople;
  string value_obj = extract_object(ThreePeople_obj, "value");

  people->p1 = handle_person(extract_object(value_obj, "p1"));
  people->p2 = handle_person(extract_object(value_obj, "p2"));
  people->p3 = handle_person(extract_object(value_obj, "p3"));

  return *people;
}

int handle_int(string int_object) {
  return extract_int(int_object, "value");
}

string handle_string(string string_object) {
  return extract_string(string_object, "value");
}

float handle_float(string float_object) {
  return extract_float(float_object, "value");
}




