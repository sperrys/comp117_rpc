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
#include "utility.h"

#include "c150debug.h"

using namespace C150NETWORK;  // for all the comp150 utilities 

const string VALUE_KEY = "value";
const string TYPE_KEY = "type";
const string STRUCT_KEY = "is_struct";
const string ARRAY_KEY = "is_array";


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

void person_func(Person p) {
  // Compose the remote call
  string message;
  vector<string> pairs;

  // Remote call metadata
  pairs.push_back(serialize_pair("method", "person_func", "string"));
  pairs.push_back(serialize_pair("param_count", "1", "int"));

  // Remote call params
  vector<string> param_objects;
  param_objects.push_back(serialize_Person(p));
  cout << "object for " << "p" << ": " << serialize_Person(p) << "\n";

  string params = serialize_array(param_objects);
  pairs.push_back(serialize_pair("params", params, "array"));

  // Finalize the message
  message = serialize_object(pairs);

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
  pairs.push_back(serialize_pair("method", "people_func", "string"));
  pairs.push_back(serialize_pair("param_count", "1", "int"));

  // Remote call params
  vector<string> param_objects;
  param_objects.push_back(serialize_ThreePeople(p));
  cout << "object for " << "p" << ": " << serialize_ThreePeople(p) << "\n";

  string params = serialize_array(param_objects);
  pairs.push_back(serialize_pair("params", params, "array"));

  // Finalize the message
  message = serialize_object(pairs);

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
  pairs.push_back(serialize_pair("method", "people_array", "string"));
  pairs.push_back(serialize_pair("param_count", "1", "int"));

  // Remote call params
  vector<string> param_objects;
  param_objects.push_back(serialize_people_array(p));
  cout << "object for " << "p" << ": " << serialize_people_array(p) << "\n";

  string params = serialize_array(param_objects);
  pairs.push_back(serialize_pair("params", params, "array"));

  // Finalize the message
  message = serialize_object(pairs);

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
  pairs.push_back(serialize_pair("method", "sum", "string"));
  pairs.push_back(serialize_pair("param_count", "1", "int"));

  // Remote call params
  vector<string> param_objects;
  param_objects.push_back(serialize_int_3(x));
  cout << "object for " << "x" << ": " << serialize_int_3(x) << "\n";

  string params = serialize_array(param_objects);
  pairs.push_back(serialize_pair("params", params, "array"));

  // Finalize the message
  message = serialize_object(pairs);

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
  pairs.push_back(serialize_pair("method", "add", "string"));
  pairs.push_back(serialize_pair("param_count", "2", "int"));

  // Remote call params
  vector<string> param_objects;
  param_objects.push_back(serialize_int(x));
  cout << "object for " << "x" << ": " << serialize_int(x) << "\n";
  
  param_objects.push_back(serialize_int(y));
  cout << "object for " << "y" << ": " << serialize_int(y) << "\n";

  string params = serialize_array(param_objects);
  pairs.push_back(serialize_pair("params", params, "array"));

  // Finalize the message
  message = serialize_object(pairs);

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
