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

// idl interfaces
#include "arithmetic.idl"
#include "lotsofstuff.idl"

// utility interfaces
#include "generic_deserialization.h"
#include "deserialization.h"
#include "generic_serialization.h"
#include "serialization.h"
#include "tcp.h"

// c150 interface
#include "rpcproxyhelper.h"
#include "c150debug.h"

using namespace C150NETWORK;  // for all the comp150 utilities 

const string VALUE_KEY = "value";
const string TYPE_KEY = "type";
const string STRUCT_KEY = "is_struct";
const string ARRAY_KEY = "is_array";

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
  // Compose the remote call
  string message;
  vector<string> pairs;

  // Remote call metadata
  pairs.push_back(serialize_pair("method", "sum", "string"));
  pairs.push_back(serialize_pair("param_count", "1", "int"));

  // Remote call params
  vector<string> param_objects;
  param_objects.push_back(serialize_int_3(x));

  string params = serialize_array(param_objects);
  pairs.push_back(serialize_pair("params", params, "array"));

  // Finalize the message
  message = serialize_object(pairs);

  // Send the remote call
  c150debug->printf(C150RPCDEBUG,"arithmetic.proxy.cpp: sum() invoked");
  RPCPROXYSOCKET->write(message.c_str(), message.length() + 1); // write function name including null

  // Read the response
  c150debug->printf(C150RPCDEBUG,"arithmetic.proxy.cpp: sum() invocation sent, waiting for response");
  char readBuffer[5];  // to read magic value DONE + null
  RPCPROXYSOCKET->read(readBuffer, sizeof(readBuffer)); // only legal response is DONE

  return 0;
}

int add(int x, int y) {
  // Compose the remote call
  string message;
  vector<string> pairs;

  // Remote call metadata
  pairs.push_back(serialize_pair("method", "add", "string"));
  pairs.push_back(serialize_pair("param_count", "2", "int"));

  // Remote call params
  vector<string> param_objects;
  param_objects.push_back(serialize_int(x));
  
  param_objects.push_back(serialize_int(y));

  string params = serialize_array(param_objects);
  pairs.push_back(serialize_pair("params", params, "array"));

  // Finalize the message
  message = serialize_object(pairs);

  // Send the remote call
  c150debug->printf(C150RPCDEBUG,"arithmetic.proxy.cpp: add() invoked");
  RPCPROXYSOCKET->write(message.c_str(), message.length() + 1); // write function name including null

  // Read the response
  c150debug->printf(C150RPCDEBUG,"arithmetic.proxy.cpp: add() invocation sent, waiting for response");
  string response = read_message(RPCPROXYSOCKET, read_message_size(RPCPROXYSOCKET));

  // Check the response
  if (extract_bool(response, "error")) {
    throw C150Exception("arithmetic.proxy.cpp: add() encountered an error during computation");
  }
  c150debug->printf(C150RPCDEBUG,"arithmetic.proxy.cpp: add() successful return from remote call");

  return deserialize_int(extract_object(response, "result"));
}
