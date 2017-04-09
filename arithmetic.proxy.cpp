// --------------------------------------------------------------
//
//                        simplefunction.proxy.cpp
//
//        Author: Noah Mendelsohn         
//   
//       This is a hand-crafted demonstration proxy.
//
//       For your project, your "rpcgen" program will generate
//       proxies like this one automatically from the idl
//       file. Note that this proxy also #includes the 
//       simplefunctions.idl file. Of course, your rpcgen
//       program will change that, as well as the number
//       of functions generated. More importantly, it will
//       generate code to handle function arguments and
//       return values.
//
//
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

#include "rpcproxyhelper.h"

#include "c150debug.h"
#include <cstdio>
#include <stdbool.h>
#include <cstring>
#include <iostream>
#include <sstream>
#include <vector>

using namespace C150NETWORK;  // for all the comp150 utilities 

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

string handle_int_3(int my_int_3[3]) {
  vector<string> param_pairs;

  // value to string conversion
  string type = "int[3]";
  vector<string> elements;
  for (int i = 0; i < 3; i++) {
    elements.push_back(handle_int(my_int_3[i]));
  }
  stringstream value;
  value << jsonify_array(elements);

  // compose the inner description object
  param_pairs.push_back(jsonify_pair(TYPE_KEY, type, "string"));
  param_pairs.push_back(jsonify_pair(STRUCT_KEY, "false", "bool"));
  param_pairs.push_back(jsonify_pair(ARRAY_KEY, "true", "bool"));
  param_pairs.push_back(jsonify_pair(VALUE_KEY, value.str(), "array"));

  return jsonify_object(param_pairs);
}

string handle_Person(Person my_Person) {
  vector<string> param_pairs;

  // value to string conversion
  string type = "Person";
  vector<string> elements;
  elements.push_back(jsonify_pair("firstname", handle_string(my_Person.firstname), "object"));
  elements.push_back(jsonify_pair("lastname", handle_string(my_Person.lastname), "object"));
  elements.push_back(jsonify_pair("age", handle_int(my_Person.age), "object"));
  stringstream value;
  value << jsonify_object(elements);

  // compose the inner description object
  param_pairs.push_back(jsonify_pair(TYPE_KEY, type, "string"));
  param_pairs.push_back(jsonify_pair(STRUCT_KEY, "true", "bool"));
  param_pairs.push_back(jsonify_pair(ARRAY_KEY, "false", "bool"));
  param_pairs.push_back(jsonify_pair(VALUE_KEY, value.str(), "object"));

  return jsonify_object(param_pairs);
}

string handle_people_array(Person p[3]) {
  vector<string> param_pairs;

  // value to string conversion
  string type = "p[3]";
  vector<string> elements;
  for (int i = 0; i < 3; i++) {
    elements.push_back(handle_Person(p[i]));
  }
  stringstream value;
  value << jsonify_array(elements);

  // compose the inner description object
  param_pairs.push_back(jsonify_pair(TYPE_KEY, type, "string"));
  param_pairs.push_back(jsonify_pair(STRUCT_KEY, "false", "bool"));
  param_pairs.push_back(jsonify_pair(ARRAY_KEY, "true", "bool"));
  param_pairs.push_back(jsonify_pair(VALUE_KEY, value.str(), "array"));

  return jsonify_object(param_pairs);
}

string handle_ThreePeople(ThreePeople my_ThreePeople) {
  vector<string> param_pairs;

  // value to string conversion
  string type = "ThreePeople";
  vector<string> elements;
  elements.push_back(jsonify_pair("p1", handle_Person(my_ThreePeople.p1), "object"));
  elements.push_back(jsonify_pair("p2", handle_Person(my_ThreePeople.p2), "object"));
  elements.push_back(jsonify_pair("p3", handle_Person(my_ThreePeople.p3), "object"));
  stringstream value;
  value << jsonify_object(elements);

  // compose the inner description object
  param_pairs.push_back(jsonify_pair(TYPE_KEY, type, "string"));
  param_pairs.push_back(jsonify_pair(STRUCT_KEY, "true", "bool"));
  param_pairs.push_back(jsonify_pair(ARRAY_KEY, "false", "bool"));
  param_pairs.push_back(jsonify_pair(VALUE_KEY, value.str(), "object"));

  return jsonify_object(param_pairs);
}

void person_func(Person p) {
  // Compose the remote call
  string message;
  vector<string> pairs;

  // Remote call metadata
  pairs.push_back(jsonify_pair("method", "person_func", "string"));
  pairs.push_back(jsonify_pair("param_count", "1", "int"));

  // Remote call params
  vector<string> param_objects;
  param_objects.push_back(handle_Person(p));
  cout << "object for " << "p" << ": " << handle_Person(p) << "\n";

  string params = jsonify_array(param_objects);
  pairs.push_back(jsonify_pair("params", params, "array"));

  // Finalize the message
  message = jsonify_object(pairs);

  cout << "The final message: " << message << "\n";

  // Send the remote call
  c150debug->printf(C150RPCDEBUG,"arithmetic.proxy.cpp: person_func() invoked");
  RPCPROXYSOCKET->write(message.c_str(), message.length() + 1); // write function name including null

  // Read the response
  char readBuffer[5];  // to read magic value DONE + null
  c150debug->printf(C150RPCDEBUG,"arithmetic.proxy.cpp: person_func() invocation sent, waiting for response");
  RPCPROXYSOCKET->read(readBuffer, sizeof(readBuffer)); // only legal response is DONE

  return;
}

void people_func(ThreePeople p) {
  // Compose the remote call
  string message;
  vector<string> pairs;

  // Remote call metadata
  pairs.push_back(jsonify_pair("method", "people_func", "string"));
  pairs.push_back(jsonify_pair("param_count", "1", "int"));

  // Remote call params
  vector<string> param_objects;
  param_objects.push_back(handle_ThreePeople(p));
  cout << "object for " << "p" << ": " << handle_ThreePeople(p) << "\n";

  string params = jsonify_array(param_objects);
  pairs.push_back(jsonify_pair("params", params, "array"));

  // Finalize the message
  message = jsonify_object(pairs);

  cout << "The final message: " << message << "\n";

   // Send the remote call
  c150debug->printf(C150RPCDEBUG,"arithmetic.proxy.cpp: people_func() invoked");
  RPCPROXYSOCKET->write(message.c_str(), message.length() + 1); // write function name including null

  // Read the response
  char readBuffer[5];  // to read magic value DONE + null
  c150debug->printf(C150RPCDEBUG,"arithmetic.proxy.cpp: people_func() invocation sent, waiting for response");
  RPCPROXYSOCKET->read(readBuffer, sizeof(readBuffer)); // only legal response is DONE

  return;
}

void people_array(Person p[]) {
  // Compose the remote call
  string message;
  vector<string> pairs;

  // Remote call metadata
  pairs.push_back(jsonify_pair("method", "people_array", "string"));
  pairs.push_back(jsonify_pair("param_count", "1", "int"));

  // Remote call params
  vector<string> param_objects;
  param_objects.push_back(handle_people_array(p));
  cout << "object for " << "p" << ": " << handle_people_array(p) << "\n";

  string params = jsonify_array(param_objects);
  pairs.push_back(jsonify_pair("params", params, "array"));

  // Finalize the message
  message = jsonify_object(pairs);

  cout << "The final message: " << message << "\n";

   // Send the remote call
  c150debug->printf(C150RPCDEBUG,"arithmetic.proxy.cpp: people_array() invoked");
  RPCPROXYSOCKET->write(message.c_str(), message.length() + 1); // write function name including null

  // Read the response
  char readBuffer[5];  // to read magic value DONE + null
  c150debug->printf(C150RPCDEBUG,"arithmetic.proxy.cpp: people_array() invocation sent, waiting for response");
  RPCPROXYSOCKET->read(readBuffer, sizeof(readBuffer)); // only legal response is DONE

  return;
}

int sum(int x[3]) {
  //  {
  //    method_name: "sum",
  //    param_count: 1,
  //    params: [
  //      {
  //        type: "int[3]"
  //        is_struct: false,
  //        is_array: true,
  //        value: [
  //          1: {
  //            type: "int",
  //            value: 14,
  //          },
  //          2: {
  //            type: "int",
  //            value: 125,
  //          },
  //          3: {
  //            type: "int",
  //            value: 2,
  //          }
  //        ]
  //      },
  //      {
  //        type: "Person",
  //        value: {
  //          age: {
  //            type: "int",
  //            value: 42,
  //          },
  //          nephew: {
  //            type: "Person",
  //            value: {
  //              age: {
  //                type: "int",
  //                value: 3,
  //              },
  //              nephew: null
  //          }
  //        }
  //      }
  //    ]
  //  }

  // Compose the remote call
  string message;
  vector<string> pairs;

  // Remote call metadata
  pairs.push_back(jsonify_pair("method", "sum", "string"));
  pairs.push_back(jsonify_pair("param_count", "1", "int"));

  // Remote call params
  vector<string> param_objects;
  param_objects.push_back(handle_int_3(x));
  cout << "object for " << "x" << ": " << handle_int_3(x) << "\n";

  string params = jsonify_array(param_objects);
  pairs.push_back(jsonify_pair("params", params, "array"));

  // Finalize the message
  message = jsonify_object(pairs);

  cout << "The final message: " << message << "\n";

  // Send the remote call
  c150debug->printf(C150RPCDEBUG,"arithmetic.proxy.cpp: sum() invoked");
  RPCPROXYSOCKET->write(message.c_str(), message.length() + 1); // write function name including null

  // Read the response
  char readBuffer[5];  // to read magic value DONE + null
  c150debug->printf(C150RPCDEBUG,"arithmetic.proxy.cpp: sum() invocation sent, waiting for response");
  RPCPROXYSOCKET->read(readBuffer, sizeof(readBuffer)); // only legal response is DONE

  return 0;
}

int add(int x, int y) {
  // {
  //   "method_name": "add",
  //   "param_count": 2,
  //   "params": [
  //     {
  //       "value": "1",
  //       "type": "int"
  //     },
  //     {
  //       "value": "10",
  //       "type": "int"
  //     }
  //   ]
  // }

  // Compose the remote call
  string message;
  vector<string> pairs;

  // Remote call metadata
  pairs.push_back(jsonify_pair("method", "add", "string"));
  pairs.push_back(jsonify_pair("param_count", "2", "int"));

  // Remote call params
  vector<string> param_objects;
  param_objects.push_back(handle_int(x));
  cout << "object for " << "x" << ": " << handle_int(x) << "\n";
  
  param_objects.push_back(handle_int(y));
  cout << "object for " << "y" << ": " << handle_int(y) << "\n";

  string params = jsonify_array(param_objects);
  pairs.push_back(jsonify_pair("params", params, "array"));

  // Finalize the message
  message = jsonify_object(pairs);

  cout << "The final message: " << message.c_str() << "\n";

  // Send the remote call
  c150debug->printf(C150RPCDEBUG,"simplefunction.proxy.cpp: add() invoked");
  RPCPROXYSOCKET->write(message.c_str(), message.length() + 1); // write function name including null

  // Read the response
  char readBuffer[5];  // to read magic value DONE + null
  c150debug->printf(C150RPCDEBUG,"simplefunction.proxy.cpp: add() invocation sent, waiting for response");
  RPCPROXYSOCKET->read(readBuffer, sizeof(readBuffer)); // only legal response is DONE

  //
  // Check the response
  //
  if (strncmp(readBuffer,"DONE", sizeof(readBuffer)) != 0) {
    throw C150Exception("simplefunction.proxy: add() received invalid response from the server");
  }
  c150debug->printf(C150RPCDEBUG,"simplefunction.proxy.cpp: add() successful return from remote call");

  return 0;
}
