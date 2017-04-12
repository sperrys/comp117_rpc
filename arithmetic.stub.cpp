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
#include "rpcstubhelper.h"
#include "c150debug.h"

using namespace C150NETWORK;  // for all the comp150 utilities 

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
  int x = deserialize_int(consume_object(params));
  int y = deserialize_int(consume_object(params));
  //
  // Time to actually call the function 
  //
  c150debug->printf(C150RPCDEBUG,"simplefunction.stub.cpp: invoking add()");
  int result = add(x, y);

  // Compose the remote call
  vector<string> pairs;
  pairs.push_back(serialize_pair("method", "sum", "string"));
  pairs.push_back(serialize_pair("error", "false", "bool"));
  pairs.push_back(serialize_pair("result", serialize_int(result), "object"));
  string message = serialize_object(pairs);

  // Send the response to the client
  c150debug->printf(C150RPCDEBUG,"simplefunction.stub.cpp: returned from  func1() -- responding to client");
  RPCSTUBSOCKET->write(message.c_str(), message.length() + 1);
}

void __sum(string json, int param_count, string params) {
  int *x = deserialize_int_3(consume_object(params));
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
  Person my_person = deserialize_person(consume_object(params));

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
  ThreePeople people = deserialize_ThreePeople(consume_object(params));

  cout << people.p1.firstname << "'s favorite numbers: " <<  people.p1.favorite_numbers[0] << ", " << people.p1.favorite_numbers[1] << ", " << people.p1.favorite_numbers[2] << endl;
  cout << people.p2.firstname << "'s favorite numbers: " <<  people.p2.favorite_numbers[0] << ", " << people.p2.favorite_numbers[1] << ", " << people.p2.favorite_numbers[2] << endl;
  cout << people.p3.firstname << "'s favorite numbers: " <<  people.p3.favorite_numbers[0] << ", " << people.p3.favorite_numbers[1] << ", " << people.p3.favorite_numbers[2] << endl;
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
  Person *people = deserialize_people_3(consume_object(params));
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
  string json_str = read_message(RPCSTUBSOCKET, read_message_size(RPCSTUBSOCKET));

  string func_name = extract_string(json_str, "method");
  int param_count = extract_int(json_str, "param_count");
  string params = extract_array(json_str, "params");

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





