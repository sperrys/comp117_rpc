// --------------------------------------------------------------
//
//
//                    arithmetic.stub.cpp                    
//
//          Authors: Aaron Bowen, Spencer Perry
//          This is an auto-generated stub.
//
//
// --------------------------------------------------------------



#include "arithmetic.idl"
#include <string>
#include <cstdio>
#include <cstring>
#include "rpcstubhelper.h"
#include "c150debug.h"
#include "generic_deserialization.h"
#include "gen.deserialization.h"
#include "generic_serialization.h"
#include "gen.serialization.h"
#include "tcp.h"

using namespace C150NETWORK;
using namespace std;



void __multiply(string json, int param_count, string params) { 

      int x = deserialize_int(consume_object(params));
      int y = deserialize_int(consume_object(params));

      // Time to Call The Function
 
      c150debug->printf(C150RPCDEBUG,"stub - invoking multiply() ");
      int result = multiply(x, y); 

      // Compose the remote call
      vector<string> pairs;
      pairs.push_back(serialize_pair("method", "multiply", "string"));
      pairs.push_back(serialize_pair("error", "false", "bool"));
      pairs.push_back(serialize_pair("result", serialize_int(result), "object"));
      string message = serialize_object(pairs);

      // Send the response to the client
      c150debug->printf(C150RPCDEBUG,"simplefunction.stub.cpp: returned from  func1() -- responding to client");
      RPCSTUBSOCKET->write(message.c_str(), message.length() + 1);
}
void __add(string json, int param_count, string params) { 

      int x = deserialize_int(consume_object(params));
      int y = deserialize_int(consume_object(params));

      // Time to Call The Function
 
      c150debug->printf(C150RPCDEBUG,"stub - invoking add() ");
      int result = add(x, y); 

      // Compose the remote call
      vector<string> pairs;
      pairs.push_back(serialize_pair("method", "add", "string"));
      pairs.push_back(serialize_pair("error", "false", "bool"));
      pairs.push_back(serialize_pair("result", serialize_int(result), "object"));
      string message = serialize_object(pairs);

      // Send the response to the client
      c150debug->printf(C150RPCDEBUG,"simplefunction.stub.cpp: returned from  func1() -- responding to client");
      RPCSTUBSOCKET->write(message.c_str(), message.length() + 1);
}
void __subtract(string json, int param_count, string params) { 

      int x = deserialize_int(consume_object(params));
      int y = deserialize_int(consume_object(params));

      // Time to Call The Function
 
      c150debug->printf(C150RPCDEBUG,"stub - invoking subtract() ");
      int result = subtract(x, y); 

      // Compose the remote call
      vector<string> pairs;
      pairs.push_back(serialize_pair("method", "subtract", "string"));
      pairs.push_back(serialize_pair("error", "false", "bool"));
      pairs.push_back(serialize_pair("result", serialize_int(result), "object"));
      string message = serialize_object(pairs);

      // Send the response to the client
      c150debug->printf(C150RPCDEBUG,"simplefunction.stub.cpp: returned from  func1() -- responding to client");
      RPCSTUBSOCKET->write(message.c_str(), message.length() + 1);
}
void __divide(string json, int param_count, string params) { 

      int x = deserialize_int(consume_object(params));
      int y = deserialize_int(consume_object(params));

      // Time to Call The Function
 
      c150debug->printf(C150RPCDEBUG,"stub - invoking divide() ");
      int result = divide(x, y); 

      // Compose the remote call
      vector<string> pairs;
      pairs.push_back(serialize_pair("method", "divide", "string"));
      pairs.push_back(serialize_pair("error", "false", "bool"));
      pairs.push_back(serialize_pair("result", serialize_int(result), "object"));
      string message = serialize_object(pairs);

      // Send the response to the client
      c150debug->printf(C150RPCDEBUG,"simplefunction.stub.cpp: returned from  func1() -- responding to client");
      RPCSTUBSOCKET->write(message.c_str(), message.length() + 1);
}
void __badFunction(string func_name) { 
    char doneBuffer[5] = "BAD";  // to write magic value DONE + null  

    // Send the response to the client indicating bad function
    c150debug->printf(C150RPCDEBUG,"simplefunction.stub.cpp: received call for nonexistent function %s()", func_name);
    RPCSTUBSOCKET->write(doneBuffer, strlen(doneBuffer)+1);
 } 

void dispatchFunction() {
    // Read the Json Message in 
    string json_str = read_message(RPCSTUBSOCKET, read_message_size(RPCSTUBSOCKET));

    string func_name = extract_string(json_str, "method");
    int param_count = extract_int(json_str, "param_count");
    string params = extract_array(json_str, "params");

    if(!RPCSTUBSOCKET->eof()) { 
        if(func_name == "multiply")
             __multiply(json_str, param_count, params); 
        if(func_name == "add")
             __add(json_str, param_count, params); 
        if(func_name == "subtract")
             __subtract(json_str, param_count, params); 
        if(func_name == "divide")
             __divide(json_str, param_count, params); 
        else
            __badFunction(func_name);
    }
}
