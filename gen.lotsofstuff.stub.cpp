// --------------------------------------------------------------
//
//
//                    lotsofstuff.stub.cpp                    
//
//          Authors: Aaron Bowen, Spencer Perry
//          This is an auto-generated stub.
//
//
// --------------------------------------------------------------



#include "lotsofstuff.idl"
#include <string>
#include <cstdio>
#include <cstring>
#include <utility.h>
#include <rpcstubhelper.h>
#include <c150debug.h>

using namespace C150NETWORK;



void __func3(string json, int param_count, string params) { 


      // Time to Call The Function
 
      c150debug->printf(C150RPCDEBUG,"stub - invoking func3() ");
      void result = func3(); 

      // Compose the remote call
      vector<string> pairs;
      pairs.push_back(serialize_pair("method", "func3", "string"));
      pairs.push_back(serialize_pair("error", "false", "bool"));
      pairs.push_back(serialize_pair("result", serialize_void(result), "object"));
      string message = serialize_object(pairs);

      // Send the response to the client
      c150debug->printf(C150RPCDEBUG,"simplefunction.stub.cpp: returned from  func1() -- responding to client");
      RPCSTUBSOCKET->write(message.c_str(), message.length() + 1);
}
void __func2(string json, int param_count, string params) { 


      // Time to Call The Function
 
      c150debug->printf(C150RPCDEBUG,"stub - invoking func2() ");
      void result = func2(); 

      // Compose the remote call
      vector<string> pairs;
      pairs.push_back(serialize_pair("method", "func2", "string"));
      pairs.push_back(serialize_pair("error", "false", "bool"));
      pairs.push_back(serialize_pair("result", serialize_void(result), "object"));
      string message = serialize_object(pairs);

      // Send the response to the client
      c150debug->printf(C150RPCDEBUG,"simplefunction.stub.cpp: returned from  func1() -- responding to client");
      RPCSTUBSOCKET->write(message.c_str(), message.length() + 1);
}
void __func1(string json, int param_count, string params) { 


      // Time to Call The Function
 
      c150debug->printf(C150RPCDEBUG,"stub - invoking func1() ");
      void result = func1(); 

      // Compose the remote call
      vector<string> pairs;
      pairs.push_back(serialize_pair("method", "func1", "string"));
      pairs.push_back(serialize_pair("error", "false", "bool"));
      pairs.push_back(serialize_pair("result", serialize_void(result), "object"));
      string message = serialize_object(pairs);

      // Send the response to the client
      c150debug->printf(C150RPCDEBUG,"simplefunction.stub.cpp: returned from  func1() -- responding to client");
      RPCSTUBSOCKET->write(message.c_str(), message.length() + 1);
}
void __area(string json, int param_count, string params) { 

      rectangle r = deserialize_rectangle(consume_object(params));

      // Time to Call The Function
 
      c150debug->printf(C150RPCDEBUG,"stub - invoking area() ");
      int result = area(r); 

      // Compose the remote call
      vector<string> pairs;
      pairs.push_back(serialize_pair("method", "area", "string"));
      pairs.push_back(serialize_pair("error", "false", "bool"));
      pairs.push_back(serialize_pair("result", serialize_int(result), "object"));
      string message = serialize_object(pairs);

      // Send the response to the client
      c150debug->printf(C150RPCDEBUG,"simplefunction.stub.cpp: returned from  func1() -- responding to client");
      RPCSTUBSOCKET->write(message.c_str(), message.length() + 1);
}
void __findPerson(string json, int param_count, string params) { 

      ThreePeople tp = deserialize_ThreePeople(consume_object(params));

      // Time to Call The Function
 
      c150debug->printf(C150RPCDEBUG,"stub - invoking findPerson() ");
      Person result = findPerson(tp); 

      // Compose the remote call
      vector<string> pairs;
      pairs.push_back(serialize_pair("method", "findPerson", "string"));
      pairs.push_back(serialize_pair("error", "false", "bool"));
      pairs.push_back(serialize_pair("result", serialize_Person(result), "object"));
      string message = serialize_object(pairs);

      // Send the response to the client
      c150debug->printf(C150RPCDEBUG,"simplefunction.stub.cpp: returned from  func1() -- responding to client");
      RPCSTUBSOCKET->write(message.c_str(), message.length() + 1);
}
void __sum(string json, int param_count, string params) { 

      int[3] x = deserialize___int[3](consume_object(params));

      // Time to Call The Function
 
      c150debug->printf(C150RPCDEBUG,"stub - invoking sum() ");
      int result = sum(x); 

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
void __sqrt(string json, int param_count, string params) { 

      int x = deserialize_int(consume_object(params));
      int y = deserialize_int(consume_object(params));

      // Time to Call The Function
 
      c150debug->printf(C150RPCDEBUG,"stub - invoking sqrt() ");
      int result = sqrt(x, y); 

      // Compose the remote call
      vector<string> pairs;
      pairs.push_back(serialize_pair("method", "sqrt", "string"));
      pairs.push_back(serialize_pair("error", "false", "bool"));
      pairs.push_back(serialize_pair("result", serialize_int(result), "object"));
      string message = serialize_object(pairs);

      // Send the response to the client
      c150debug->printf(C150RPCDEBUG,"simplefunction.stub.cpp: returned from  func1() -- responding to client");
      RPCSTUBSOCKET->write(message.c_str(), message.length() + 1);
}
void __person_func(string json, int param_count, string params) { 

      Person p = deserialize_Person(consume_object(params));

      // Time to Call The Function
 
      c150debug->printf(C150RPCDEBUG,"stub - invoking person_func() ");
      void result = person_func(p); 

      // Compose the remote call
      vector<string> pairs;
      pairs.push_back(serialize_pair("method", "person_func", "string"));
      pairs.push_back(serialize_pair("error", "false", "bool"));
      pairs.push_back(serialize_pair("result", serialize_void(result), "object"));
      string message = serialize_object(pairs);

      // Send the response to the client
      c150debug->printf(C150RPCDEBUG,"simplefunction.stub.cpp: returned from  func1() -- responding to client");
      RPCSTUBSOCKET->write(message.c_str(), message.length() + 1);
}
void __upcase(string json, int param_count, string params) { 

      string s = deserialize_string(consume_object(params));

      // Time to Call The Function
 
      c150debug->printf(C150RPCDEBUG,"stub - invoking upcase() ");
      string result = upcase(s); 

      // Compose the remote call
      vector<string> pairs;
      pairs.push_back(serialize_pair("method", "upcase", "string"));
      pairs.push_back(serialize_pair("error", "false", "bool"));
      pairs.push_back(serialize_pair("result", serialize_string(result), "object"));
      string message = serialize_object(pairs);

      // Send the response to the client
      c150debug->printf(C150RPCDEBUG,"simplefunction.stub.cpp: returned from  func1() -- responding to client");
      RPCSTUBSOCKET->write(message.c_str(), message.length() + 1);
}
void __takesTwoArrays(string json, int param_count, string params) { 

      int[24] x = deserialize___int[24](consume_object(params));
      int[24] y = deserialize___int[24](consume_object(params));

      // Time to Call The Function
 
      c150debug->printf(C150RPCDEBUG,"stub - invoking takesTwoArrays() ");
      int result = takesTwoArrays(x, y); 

      // Compose the remote call
      vector<string> pairs;
      pairs.push_back(serialize_pair("method", "takesTwoArrays", "string"));
      pairs.push_back(serialize_pair("error", "false", "bool"));
      pairs.push_back(serialize_pair("result", serialize_int(result), "object"));
      string message = serialize_object(pairs);

      // Send the response to the client
      c150debug->printf(C150RPCDEBUG,"simplefunction.stub.cpp: returned from  func1() -- responding to client");
      RPCSTUBSOCKET->write(message.c_str(), message.length() + 1);
}
void __multiply(string json, int param_count, string params) { 

      float x = deserialize_float(consume_object(params));
      float y = deserialize_float(consume_object(params));

      // Time to Call The Function
 
      c150debug->printf(C150RPCDEBUG,"stub - invoking multiply() ");
      float result = multiply(x, y); 

      // Compose the remote call
      vector<string> pairs;
      pairs.push_back(serialize_pair("method", "multiply", "string"));
      pairs.push_back(serialize_pair("error", "false", "bool"));
      pairs.push_back(serialize_pair("result", serialize_float(result), "object"));
      string message = serialize_object(pairs);

      // Send the response to the client
      c150debug->printf(C150RPCDEBUG,"simplefunction.stub.cpp: returned from  func1() -- responding to client");
      RPCSTUBSOCKET->write(message.c_str(), message.length() + 1);
}
void __searchRectangles(string json, int param_count, string params) { 

      rectangle[200] rects = deserialize___rectangle[200](consume_object(params));

      // Time to Call The Function
 
      c150debug->printf(C150RPCDEBUG,"stub - invoking searchRectangles() ");
      void result = searchRectangles(rects); 

      // Compose the remote call
      vector<string> pairs;
      pairs.push_back(serialize_pair("method", "searchRectangles", "string"));
      pairs.push_back(serialize_pair("error", "false", "bool"));
      pairs.push_back(serialize_pair("result", serialize_void(result), "object"));
      string message = serialize_object(pairs);

      // Send the response to the client
      c150debug->printf(C150RPCDEBUG,"simplefunction.stub.cpp: returned from  func1() -- responding to client");
      RPCSTUBSOCKET->write(message.c_str(), message.length() + 1);
}
void __people_func(string json, int param_count, string params) { 

      ThreePeople p = deserialize_ThreePeople(consume_object(params));

      // Time to Call The Function
 
      c150debug->printf(C150RPCDEBUG,"stub - invoking people_func() ");
      void result = people_func(p); 

      // Compose the remote call
      vector<string> pairs;
      pairs.push_back(serialize_pair("method", "people_func", "string"));
      pairs.push_back(serialize_pair("error", "false", "bool"));
      pairs.push_back(serialize_pair("result", serialize_void(result), "object"));
      string message = serialize_object(pairs);

      // Send the response to the client
      c150debug->printf(C150RPCDEBUG,"simplefunction.stub.cpp: returned from  func1() -- responding to client");
      RPCSTUBSOCKET->write(message.c_str(), message.length() + 1);
}
void __showsArraysofArrays(string json, int param_count, string params) { 

      int[24] x = deserialize___int[24](consume_object(params));
      int[24][15] y = deserialize___int[24][15](consume_object(params));
      int[24][15] z = deserialize___int[24][15](consume_object(params));

      // Time to Call The Function
 
      c150debug->printf(C150RPCDEBUG,"stub - invoking showsArraysofArrays() ");
      int result = showsArraysofArrays(x, y, z); 

      // Compose the remote call
      vector<string> pairs;
      pairs.push_back(serialize_pair("method", "showsArraysofArrays", "string"));
      pairs.push_back(serialize_pair("error", "false", "bool"));
      pairs.push_back(serialize_pair("result", serialize_int(result), "object"));
      string message = serialize_object(pairs);

      // Send the response to the client
      c150debug->printf(C150RPCDEBUG,"simplefunction.stub.cpp: returned from  func1() -- responding to client");
      RPCSTUBSOCKET->write(message.c_str(), message.length() + 1);
}

void dispatch_Function() {
    // Read the Json Message in 
    string json_str = read_message(RPCSTUBSOCKET, read_message_size(RPCSTUBSOCKET));

    string func_name = exstract_string(json_str, "method");
    int param_count = extract_int(json_str, "param_count");
    string params = extract_array(json_strm "params");

    if(!RPCSTUBSOCKET->eof()) { 
        if(func_name == "func3")
             __func3(json_str, param_count, params); 
        if(func_name == "func2")
             __func2(json_str, param_count, params); 
        if(func_name == "func1")
             __func1(json_str, param_count, params); 
        if(func_name == "area")
             __area(json_str, param_count, params); 
        if(func_name == "findPerson")
             __findPerson(json_str, param_count, params); 
        if(func_name == "sum")
             __sum(json_str, param_count, params); 
        if(func_name == "sqrt")
             __sqrt(json_str, param_count, params); 
        if(func_name == "person_func")
             __person_func(json_str, param_count, params); 
        if(func_name == "upcase")
             __upcase(json_str, param_count, params); 
        if(func_name == "takesTwoArrays")
             __takesTwoArrays(json_str, param_count, params); 
        if(func_name == "multiply")
             __multiply(json_str, param_count, params); 
        if(func_name == "searchRectangles")
             __searchRectangles(json_str, param_count, params); 
        if(func_name == "people_func")
             __people_func(json_str, param_count, params); 
        if(func_name == "showsArraysofArrays")
             __showsArraysofArrays(json_str, param_count, params); 
        else
            __badFuction(json_str, param_count, params);
    }
}
