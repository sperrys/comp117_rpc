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

#include "arithmetic.idl"

#include "rpcproxyhelper.h"

#include "c150debug.h"
#include <cstdio>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace C150NETWORK;  // for all the comp150 utilities 
using namespace std;

const string VALUE_KEY = "value";
const string TYPE_KEY = "type";

string serialize_pair(string key, string value) {
  stringstream pair;
  // only add value quotes if the value isn't an object or an array
  if ((value[0] == '{' && value[value.length() - 1] == '}') ||
      (value[0] == '[' && value[value.length() - 1] == ']')) {
    pair << "\"" << key << "\":" << value;
  } else {
    pair << "\"" << key << "\":\"" << value << "\"";
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
  return obj.str();
}

string serialize_array(vector<string> objects) {
  stringstream arr;
  arr << "[";
  for (unsigned int i = 0; i < objects.size(); i++) {
    arr << objects[i];
    if (i != objects.size() - 1) arr << ",";
  }
  arr << "]";
  return arr.str();
}

// returns an param description JSON object
string handle_int(string name, int my_int) {
  vector<string> param_pairs;
  
  // value to string conversion
  string type = "int";
  stringstream value;
  value << my_int;

  // compose the inner description object
  param_pairs.push_back(serialize_pair(VALUE_KEY, value.str()));
  param_pairs.push_back(serialize_pair(TYPE_KEY, type));

  // compose the outer object keyed by the param's name
  vector<string> name_key;
  name_key.push_back(serialize_pair(name, serialize_object(param_pairs)));
  string param = serialize_object(name_key);

  cout << "object for " << name << ": " << serialize_object(param_pairs) << "\n";

  return param;
}

string handle_bool(string name, bool my_bool) {
  vector<string> param_pairs;

  // value to string conversion
  string type = "bool";
  stringstream value;
  value << my_bool;

  // compose the inner description object
  param_pairs.push_back(serialize_pair(VALUE_KEY, value.str()));
  param_pairs.push_back(serialize_pair(TYPE_KEY, type));

  // compose the outer object keyed by the param's name
  vector<string> name_key;
  name_key.push_back(serialize_pair(name, serialize_object(param_pairs)));
  string param = serialize_object(name_key);

  cout << "object for " << name << ": " << serialize_object(param_pairs) << "\n";

  return param;
}

string handle_string(string name, string my_string) {

  vector<string> param_pairs;
  string type = "string";

  // compose the inner description object
  param_pairs.push_back(serialize_pair(VALUE_KEY, my_string));
  param_pairs.push_back(serialize_pair(TYPE_KEY, type));

  // compose the outer object keyed by the param's name
  vector<string> name_key;
  name_key.push_back(serialize_pair(name, serialize_object(param_pairs)));
  string param = serialize_object(name_key);

  cout << "object for " << name << ": " << serialize_object(param_pairs) << "\n";

  return param;
}

string handle_char(string name, char my_char) {
  vector<string> param_pairs;

  // value to string conversion
  string type = "char";
  stringstream value;
  value << my_char;

  // compose the inner description object
  param_pairs.push_back(serialize_pair(VALUE_KEY, value.str()));
  param_pairs.push_back(serialize_pair(TYPE_KEY, type));

  // compose the outer object keyed by the param's name
  vector<string> name_key;
  name_key.push_back(serialize_pair(name, serialize_object(param_pairs)));
  string param = serialize_object(name_key);

  cout << "object for " << name << ": " << serialize_object(param_pairs) << "\n";

  return param;
}

int add(int x, int y) {
  // {
  //   "method_name": "add",
  //   "param_count": 2,
  //   "params": [
  //     {
  //       "x": {
  //         "value": "1",
  //         "type": "int"
  //       }
  //     },
  //     {
  //       "y": {
  //         "value": "10",
  //         "type": "int"
  //       }
  //     }
  //   ]
  // }

  // Compose the remote call
  string message;
  vector<string> pairs;

  // Remote call metadata
  pairs.push_back(serialize_pair("method", "add"));
  pairs.push_back(serialize_pair("param_count", "2"));

  // Remote call params
  vector<string> param_objects;
  param_objects.push_back(handle_int("x", x));
  param_objects.push_back(handle_int("y", y));

  string params = serialize_array(param_objects);
  pairs.push_back(serialize_pair("params", params));

  // Finalize the message
  message = serialize_object(pairs);

  cout << "The final message: " << message << "\n";

  return 0;

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
