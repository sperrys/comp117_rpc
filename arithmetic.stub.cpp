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
size_t extract_object_length(string json);
string extract_string(string json, string key);
int extract_int(string json, string key);
string extract_array(string json, string key);

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

  size_t x_param_size = extract_object_length(params);
  size_t x_param_start = params.find('{');
  size_t x_param_len = x_param_size;
  
  string x_param = params.substr(x_param_start, x_param_len);
  cout << "x: " << x_param << endl;
  int x = handle_int(x_param);
  cout << "x value: " << x << endl;

  params = params.substr(x_param_start + x_param_len + strlen(","), params.npos);

  size_t y_param_size = extract_object_length(params);
  size_t y_param_start = params.find('{');
  size_t y_param_len = y_param_size;
  
  string y_param = params.substr(y_param_start, y_param_len);
  cout << "y: " << y_param << endl;
  int y = handle_int(y_param);
  cout << "y value: " << y << endl;

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
  size_t x_param_size = extract_object_length(params);
  size_t x_param_start = params.find('{');
  size_t x_param_len = x_param_size;
  
  string x_param = params.substr(x_param_start, x_param_len);
  cout << "x: " << x_param << endl;
  int *x = handle_int_3(x_param);
  cout << "x[0]: " << x[0] << endl;

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

  size_t person_param_size = extract_object_length(params);
  size_t person_param_start = params.find('{');
  size_t person_param_len = person_param_size;
  
  string person_param = params.substr(person_param_start, person_param_len);
  cout << "x: " << person_param << endl;
  Person my_person = handle_person(person_param);
  cout << "person.firstname: " << my_person.firstname << endl;

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

  size_t ThreePeople_param_size = extract_object_length(params);
  size_t ThreePeople_param_start = params.find('{');
  size_t ThreePeople_param_len = ThreePeople_param_size;
  
  string ThreePeople_param = params.substr(ThreePeople_param_start, ThreePeople_param_len);
  cout << "x: " << ThreePeople_param << endl;
  ThreePeople people = handle_ThreePeople(ThreePeople_param);
  

  cout << "P1 firstname is " <<  people.p1.firstname << endl;
  cout << "P2 firstname is " <<  people.p2.firstname << endl;
  cout << "P3 firstname is " <<  people.p3.firstname << endl;
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

  size_t people_array_param_size = extract_object_length(params);
  size_t people_array_param_start = params.find('{');
  size_t people_array_param_len = people_array_param_size;
  
  string people_array_param = params.substr(people_array_param_start, people_array_param_len);
  cout << "x: " << people_array_param << endl;
  Person * people = handle_people_3(people_array_param);
  cout << people[1].firstname << endl;
  
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

int* handle_int_3(string int_3_obj) {
  int *my_int = (int *) malloc(sizeof(int) * 3);
  string objs = extract_array(int_3_obj, "value");

  for (int i = 0; i < 3; i++) {
    size_t i_param_size = extract_object_length(objs);
    size_t i_param_start = objs.find('{');
    size_t i_param_len = i_param_size;
    
    string i_param = objs.substr(i_param_start, i_param_len);
    // cout << "i: " << i_param << endl;
    int x = handle_int(i_param);
    // cout << "i value: " << x << endl;

    if (i < 2) {// not the last iteration
      objs = objs.substr(i_param_start + i_param_len + strlen(","), objs.npos);
    }

    my_int[i] = x;
  }

  return my_int;
}


Person* handle_people_3(string people_3_obj) {
  Person *my_people = (Person *) malloc(sizeof(Person) * 3);
  string objs = extract_array(people_3_obj, "value");

  for (int i = 0; i < 3; i++) {
    size_t i_param_size = extract_object_length(objs);
    size_t i_param_start = objs.find('{');
    size_t i_param_len = i_param_size;
    
    string i_param = objs.substr(i_param_start, i_param_len);
    // cout << "i: " << i_param << endl;
    Person x = handle_person(i_param);
    // cout << "i value: " << x << endl;

    if (i < 2) {// not the last iteration
      objs = objs.substr(i_param_start + i_param_len + strlen(","), objs.npos);
    }
    cerr << "Made it here" << endl;
    my_people[i] = x;
  }

  return my_people;
}

Person handle_person(string person_obj) {

  // Had to mess around to properly return struct 
  //Person my_person = *(Person *)malloc(sizeof(Person));
  Person* my_person = new struct Person;
  string value_obj = extract_object(person_obj, "value");

  // TODO extract based on length, not just regex
  my_person->firstname = handle_string(extract_string(extract_object(value_obj, "firstname"), "value"));
  my_person->lastname = handle_string(extract_string(extract_object(value_obj, "lastname"), "value"));
  my_person->age = handle_int(extract_object(value_obj, "age"));
 
  return *(my_person);
}

ThreePeople handle_ThreePeople(string ThreePeople_obj) {

  ThreePeople* people = new struct ThreePeople;
  string value_obj = extract_object(ThreePeople_obj, "value");

  people->p1 = handle_person(extract_object(value_obj, "p1"));
  people->p2 = handle_person(extract_object(value_obj, "p2"));
  people->p3 = handle_person(extract_object(value_obj, "p3"));

  return *(people);
}

int handle_int(string int_object) {
  return extract_int(int_object, "value");
}

string handle_string(string s_string) {
  return s_string;
}

float handle_float(string float_string) {
  return stof(float_string);
}




