// --------------------------------------------------------------
//
//
//                    arithmetic.proxy.cpp                    
//
//          Authors: Aaron Bowen, Spencer Perry
//          This is an auto-generated proxy.
//
//
// --------------------------------------------------------------



#include "arithmetic.idl"
#include <string>
#include "rpcproxyhelper.h"
#include "c150debug.h"
#include "generic_deserialization.h"
#include "gen.deserialization.h"
#include "generic_serialization.h"
#include "gen.serialization.h"
#include "tcp.h"

using namespace C150NETWORK;
using namespace std;

const string VALUE_KEY = "value";
const string TYPE_KEY = "type";
const string STRUCT_KEY = "is_struct";
const string ARRAY_KEY = "is_array";


int multiply(int x, int y)  {
    // Compose the remote call
    string message; 
    vector<string> pairs; 

    // Remote Call metadata 
    pairs.push_back(serialize_pair("method", "multiply", "string"));
    pairs.push_back(serialize_pair("param_count", "2", "string")); 
 
    // Remote call params 
    vector<string> param_objects; 
    param_objects.push_back(serialize_int(x));
    param_objects.push_back(serialize_int(y));

    string params = serialize_array(param_objects); 
    pairs.push_back(serialize_pair("params", params, "array")); 

    // Finalize the message 
    message = serialize_object(pairs);

    // Send the remote call
    c150debug->printf(C150RPCDEBUG," multiply() invoked");
    RPCPROXYSOCKET->write(message.c_str(), message.length() + 1); // write function name including null 

    // Read the response
    c150debug->printf(C150RPCDEBUG,"multiply() invocation sent, waiting for response");
    string response = read_message(RPCPROXYSOCKET, read_message_size(RPCPROXYSOCKET));

    // Check the response
    if (extract_bool(response, "error")) { 
        throw C150Exception("multiply() encountered an error during computation"); 
    } 
    c150debug->printf(C150RPCDEBUG, "multiply() successful return from remote call"); 
    return deserialize_int(extract_object(response, "result"));
 } 

int add(int x, int y)  {
    // Compose the remote call
    string message; 
    vector<string> pairs; 

    // Remote Call metadata 
    pairs.push_back(serialize_pair("method", "add", "string"));
    pairs.push_back(serialize_pair("param_count", "2", "string")); 
 
    // Remote call params 
    vector<string> param_objects; 
    param_objects.push_back(serialize_int(x));
    param_objects.push_back(serialize_int(y));

    string params = serialize_array(param_objects); 
    pairs.push_back(serialize_pair("params", params, "array")); 

    // Finalize the message 
    message = serialize_object(pairs);

    // Send the remote call
    c150debug->printf(C150RPCDEBUG," add() invoked");
    RPCPROXYSOCKET->write(message.c_str(), message.length() + 1); // write function name including null 

    // Read the response
    c150debug->printf(C150RPCDEBUG,"add() invocation sent, waiting for response");
    string response = read_message(RPCPROXYSOCKET, read_message_size(RPCPROXYSOCKET));

    // Check the response
    if (extract_bool(response, "error")) { 
        throw C150Exception("add() encountered an error during computation"); 
    } 
    c150debug->printf(C150RPCDEBUG, "add() successful return from remote call"); 
    return deserialize_int(extract_object(response, "result"));
 } 

int subtract(int x, int y)  {
    // Compose the remote call
    string message; 
    vector<string> pairs; 

    // Remote Call metadata 
    pairs.push_back(serialize_pair("method", "subtract", "string"));
    pairs.push_back(serialize_pair("param_count", "2", "string")); 
 
    // Remote call params 
    vector<string> param_objects; 
    param_objects.push_back(serialize_int(x));
    param_objects.push_back(serialize_int(y));

    string params = serialize_array(param_objects); 
    pairs.push_back(serialize_pair("params", params, "array")); 

    // Finalize the message 
    message = serialize_object(pairs);

    // Send the remote call
    c150debug->printf(C150RPCDEBUG," subtract() invoked");
    RPCPROXYSOCKET->write(message.c_str(), message.length() + 1); // write function name including null 

    // Read the response
    c150debug->printf(C150RPCDEBUG,"subtract() invocation sent, waiting for response");
    string response = read_message(RPCPROXYSOCKET, read_message_size(RPCPROXYSOCKET));

    // Check the response
    if (extract_bool(response, "error")) { 
        throw C150Exception("subtract() encountered an error during computation"); 
    } 
    c150debug->printf(C150RPCDEBUG, "subtract() successful return from remote call"); 
    return deserialize_int(extract_object(response, "result"));
 } 

int divide(int x, int y)  {
    // Compose the remote call
    string message; 
    vector<string> pairs; 

    // Remote Call metadata 
    pairs.push_back(serialize_pair("method", "divide", "string"));
    pairs.push_back(serialize_pair("param_count", "2", "string")); 
 
    // Remote call params 
    vector<string> param_objects; 
    param_objects.push_back(serialize_int(x));
    param_objects.push_back(serialize_int(y));

    string params = serialize_array(param_objects); 
    pairs.push_back(serialize_pair("params", params, "array")); 

    // Finalize the message 
    message = serialize_object(pairs);

    // Send the remote call
    c150debug->printf(C150RPCDEBUG," divide() invoked");
    RPCPROXYSOCKET->write(message.c_str(), message.length() + 1); // write function name including null 

    // Read the response
    c150debug->printf(C150RPCDEBUG,"divide() invocation sent, waiting for response");
    string response = read_message(RPCPROXYSOCKET, read_message_size(RPCPROXYSOCKET));

    // Check the response
    if (extract_bool(response, "error")) { 
        throw C150Exception("divide() encountered an error during computation"); 
    } 
    c150debug->printf(C150RPCDEBUG, "divide() successful return from remote call"); 
    return deserialize_int(extract_object(response, "result"));
 } 

