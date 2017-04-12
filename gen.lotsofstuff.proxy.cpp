// --------------------------------------------------------------
//
//
//                    lotsofstuff.proxy.cpp                    
//
//          Authors: Aaron Bowen, Spencer Perry
//          This is an auto-generated proxy.
//
//
// --------------------------------------------------------------



#include "lotsofstuff.idl"
#include <vector>
#include <cstring>
#include <cstdio>
#include <stdbool.h>
#include <iostream>
#include <sstream>
#include <rpcproxyhelper.h>
#include <c150debug.h>
#include <utility.h>

using namespace C150NETWORK;
using namespace std;

const string VALUE_KEY = "value";
const string TYPE_KEY = "type";
const string STRUCT_KEY = "is_struct";
const string ARRAY_KEY = "is_array";


void func3()  {
    // Compose the remote call
    string message; 
    vector<string> pairs; 

    // Remote Call metadata 
    pairs.push_back(jsonify_pair("method", "func3", "string"));
    pairs.push_back(jsonify_pair("param_count", "0, "string)); 
 
    // Remote call params 
    vector<string> param_objects; 

    string params = jsonify_array(param_objects); 
    pairs.push_back(jsonify_pair("params", params, "array")); 

    // Finalize the message 
    message = jsonify_object(pairs);

    // Send the remote call
    c150debug->printf(C150RPCDEBUG," func3() invoked");
    RPCPROXYSOCKET->write(message.c_str(), message.length() + 1); // write function name including null 

    // Read the response
    c150debug->printf(C150RPCDEBUG,"func3() invocation sent, waiting for response");
    string response = read_message(RPCPROXYSOCKET, read_message_size(RPCPROXYSOCKET));

    // Check the response
    if (extract_bool(response, "error")) { 
        throw C150Exception("func3() encountered an error during computation"); 
    } 
    c150debug->printf(C150RPCDEBUG, "func3() successful return from remote call"); 
    return deserialize_void(extract_object(response, "result"));
 } 

void func2()  {
    // Compose the remote call
    string message; 
    vector<string> pairs; 

    // Remote Call metadata 
    pairs.push_back(jsonify_pair("method", "func2", "string"));
    pairs.push_back(jsonify_pair("param_count", "0, "string)); 
 
    // Remote call params 
    vector<string> param_objects; 

    string params = jsonify_array(param_objects); 
    pairs.push_back(jsonify_pair("params", params, "array")); 

    // Finalize the message 
    message = jsonify_object(pairs);

    // Send the remote call
    c150debug->printf(C150RPCDEBUG," func2() invoked");
    RPCPROXYSOCKET->write(message.c_str(), message.length() + 1); // write function name including null 

    // Read the response
    c150debug->printf(C150RPCDEBUG,"func2() invocation sent, waiting for response");
    string response = read_message(RPCPROXYSOCKET, read_message_size(RPCPROXYSOCKET));

    // Check the response
    if (extract_bool(response, "error")) { 
        throw C150Exception("func2() encountered an error during computation"); 
    } 
    c150debug->printf(C150RPCDEBUG, "func2() successful return from remote call"); 
    return deserialize_void(extract_object(response, "result"));
 } 

void func1()  {
    // Compose the remote call
    string message; 
    vector<string> pairs; 

    // Remote Call metadata 
    pairs.push_back(jsonify_pair("method", "func1", "string"));
    pairs.push_back(jsonify_pair("param_count", "0, "string)); 
 
    // Remote call params 
    vector<string> param_objects; 

    string params = jsonify_array(param_objects); 
    pairs.push_back(jsonify_pair("params", params, "array")); 

    // Finalize the message 
    message = jsonify_object(pairs);

    // Send the remote call
    c150debug->printf(C150RPCDEBUG," func1() invoked");
    RPCPROXYSOCKET->write(message.c_str(), message.length() + 1); // write function name including null 

    // Read the response
    c150debug->printf(C150RPCDEBUG,"func1() invocation sent, waiting for response");
    string response = read_message(RPCPROXYSOCKET, read_message_size(RPCPROXYSOCKET));

    // Check the response
    if (extract_bool(response, "error")) { 
        throw C150Exception("func1() encountered an error during computation"); 
    } 
    c150debug->printf(C150RPCDEBUG, "func1() successful return from remote call"); 
    return deserialize_void(extract_object(response, "result"));
 } 

int area(rectangle r)  {
    // Compose the remote call
    string message; 
    vector<string> pairs; 

    // Remote Call metadata 
    pairs.push_back(jsonify_pair("method", "area", "string"));
    pairs.push_back(jsonify_pair("param_count", "1, "string)); 
 
    // Remote call params 
    vector<string> param_objects; 
    param_objects.push_back(handle_rectangle, r));

    string params = jsonify_array(param_objects); 
    pairs.push_back(jsonify_pair("params", params, "array")); 

    // Finalize the message 
    message = jsonify_object(pairs);

    // Send the remote call
    c150debug->printf(C150RPCDEBUG," area() invoked");
    RPCPROXYSOCKET->write(message.c_str(), message.length() + 1); // write function name including null 

    // Read the response
    c150debug->printf(C150RPCDEBUG,"area() invocation sent, waiting for response");
    string response = read_message(RPCPROXYSOCKET, read_message_size(RPCPROXYSOCKET));

    // Check the response
    if (extract_bool(response, "error")) { 
        throw C150Exception("area() encountered an error during computation"); 
    } 
    c150debug->printf(C150RPCDEBUG, "area() successful return from remote call"); 
    return deserialize_int(extract_object(response, "result"));
 } 

Person findPerson(ThreePeople tp)  {
    // Compose the remote call
    string message; 
    vector<string> pairs; 

    // Remote Call metadata 
    pairs.push_back(jsonify_pair("method", "findPerson", "string"));
    pairs.push_back(jsonify_pair("param_count", "1, "string)); 
 
    // Remote call params 
    vector<string> param_objects; 
    param_objects.push_back(handle_ThreePeople, tp));

    string params = jsonify_array(param_objects); 
    pairs.push_back(jsonify_pair("params", params, "array")); 

    // Finalize the message 
    message = jsonify_object(pairs);

    // Send the remote call
    c150debug->printf(C150RPCDEBUG," findPerson() invoked");
    RPCPROXYSOCKET->write(message.c_str(), message.length() + 1); // write function name including null 

    // Read the response
    c150debug->printf(C150RPCDEBUG,"findPerson() invocation sent, waiting for response");
    string response = read_message(RPCPROXYSOCKET, read_message_size(RPCPROXYSOCKET));

    // Check the response
    if (extract_bool(response, "error")) { 
        throw C150Exception("findPerson() encountered an error during computation"); 
    } 
    c150debug->printf(C150RPCDEBUG, "findPerson() successful return from remote call"); 
    return deserialize_Person(extract_object(response, "result"));
 } 

int sum(__int[3] x)  {
    // Compose the remote call
    string message; 
    vector<string> pairs; 

    // Remote Call metadata 
    pairs.push_back(jsonify_pair("method", "sum", "string"));
    pairs.push_back(jsonify_pair("param_count", "1, "string)); 
 
    // Remote call params 
    vector<string> param_objects; 
    param_objects.push_back(handle___int[3], x));

    string params = jsonify_array(param_objects); 
    pairs.push_back(jsonify_pair("params", params, "array")); 

    // Finalize the message 
    message = jsonify_object(pairs);

    // Send the remote call
    c150debug->printf(C150RPCDEBUG," sum() invoked");
    RPCPROXYSOCKET->write(message.c_str(), message.length() + 1); // write function name including null 

    // Read the response
    c150debug->printf(C150RPCDEBUG,"sum() invocation sent, waiting for response");
    string response = read_message(RPCPROXYSOCKET, read_message_size(RPCPROXYSOCKET));

    // Check the response
    if (extract_bool(response, "error")) { 
        throw C150Exception("sum() encountered an error during computation"); 
    } 
    c150debug->printf(C150RPCDEBUG, "sum() successful return from remote call"); 
    return deserialize_int(extract_object(response, "result"));
 } 

int sqrt(int x, int y)  {
    // Compose the remote call
    string message; 
    vector<string> pairs; 

    // Remote Call metadata 
    pairs.push_back(jsonify_pair("method", "sqrt", "string"));
    pairs.push_back(jsonify_pair("param_count", "2, "string)); 
 
    // Remote call params 
    vector<string> param_objects; 
    param_objects.push_back(handle_int, x));
    param_objects.push_back(handle_int, y));

    string params = jsonify_array(param_objects); 
    pairs.push_back(jsonify_pair("params", params, "array")); 

    // Finalize the message 
    message = jsonify_object(pairs);

    // Send the remote call
    c150debug->printf(C150RPCDEBUG," sqrt() invoked");
    RPCPROXYSOCKET->write(message.c_str(), message.length() + 1); // write function name including null 

    // Read the response
    c150debug->printf(C150RPCDEBUG,"sqrt() invocation sent, waiting for response");
    string response = read_message(RPCPROXYSOCKET, read_message_size(RPCPROXYSOCKET));

    // Check the response
    if (extract_bool(response, "error")) { 
        throw C150Exception("sqrt() encountered an error during computation"); 
    } 
    c150debug->printf(C150RPCDEBUG, "sqrt() successful return from remote call"); 
    return deserialize_int(extract_object(response, "result"));
 } 

void person_func(Person p)  {
    // Compose the remote call
    string message; 
    vector<string> pairs; 

    // Remote Call metadata 
    pairs.push_back(jsonify_pair("method", "person_func", "string"));
    pairs.push_back(jsonify_pair("param_count", "1, "string)); 
 
    // Remote call params 
    vector<string> param_objects; 
    param_objects.push_back(handle_Person, p));

    string params = jsonify_array(param_objects); 
    pairs.push_back(jsonify_pair("params", params, "array")); 

    // Finalize the message 
    message = jsonify_object(pairs);

    // Send the remote call
    c150debug->printf(C150RPCDEBUG," person_func() invoked");
    RPCPROXYSOCKET->write(message.c_str(), message.length() + 1); // write function name including null 

    // Read the response
    c150debug->printf(C150RPCDEBUG,"person_func() invocation sent, waiting for response");
    string response = read_message(RPCPROXYSOCKET, read_message_size(RPCPROXYSOCKET));

    // Check the response
    if (extract_bool(response, "error")) { 
        throw C150Exception("person_func() encountered an error during computation"); 
    } 
    c150debug->printf(C150RPCDEBUG, "person_func() successful return from remote call"); 
    return deserialize_void(extract_object(response, "result"));
 } 

string upcase(string s)  {
    // Compose the remote call
    string message; 
    vector<string> pairs; 

    // Remote Call metadata 
    pairs.push_back(jsonify_pair("method", "upcase", "string"));
    pairs.push_back(jsonify_pair("param_count", "1, "string)); 
 
    // Remote call params 
    vector<string> param_objects; 
    param_objects.push_back(handle_string, s));

    string params = jsonify_array(param_objects); 
    pairs.push_back(jsonify_pair("params", params, "array")); 

    // Finalize the message 
    message = jsonify_object(pairs);

    // Send the remote call
    c150debug->printf(C150RPCDEBUG," upcase() invoked");
    RPCPROXYSOCKET->write(message.c_str(), message.length() + 1); // write function name including null 

    // Read the response
    c150debug->printf(C150RPCDEBUG,"upcase() invocation sent, waiting for response");
    string response = read_message(RPCPROXYSOCKET, read_message_size(RPCPROXYSOCKET));

    // Check the response
    if (extract_bool(response, "error")) { 
        throw C150Exception("upcase() encountered an error during computation"); 
    } 
    c150debug->printf(C150RPCDEBUG, "upcase() successful return from remote call"); 
    return deserialize_string(extract_object(response, "result"));
 } 

int takesTwoArrays(__int[24] x, __int[24] y)  {
    // Compose the remote call
    string message; 
    vector<string> pairs; 

    // Remote Call metadata 
    pairs.push_back(jsonify_pair("method", "takesTwoArrays", "string"));
    pairs.push_back(jsonify_pair("param_count", "2, "string)); 
 
    // Remote call params 
    vector<string> param_objects; 
    param_objects.push_back(handle___int[24], x));
    param_objects.push_back(handle___int[24], y));

    string params = jsonify_array(param_objects); 
    pairs.push_back(jsonify_pair("params", params, "array")); 

    // Finalize the message 
    message = jsonify_object(pairs);

    // Send the remote call
    c150debug->printf(C150RPCDEBUG," takesTwoArrays() invoked");
    RPCPROXYSOCKET->write(message.c_str(), message.length() + 1); // write function name including null 

    // Read the response
    c150debug->printf(C150RPCDEBUG,"takesTwoArrays() invocation sent, waiting for response");
    string response = read_message(RPCPROXYSOCKET, read_message_size(RPCPROXYSOCKET));

    // Check the response
    if (extract_bool(response, "error")) { 
        throw C150Exception("takesTwoArrays() encountered an error during computation"); 
    } 
    c150debug->printf(C150RPCDEBUG, "takesTwoArrays() successful return from remote call"); 
    return deserialize_int(extract_object(response, "result"));
 } 

float multiply(float x, float y)  {
    // Compose the remote call
    string message; 
    vector<string> pairs; 

    // Remote Call metadata 
    pairs.push_back(jsonify_pair("method", "multiply", "string"));
    pairs.push_back(jsonify_pair("param_count", "2, "string)); 
 
    // Remote call params 
    vector<string> param_objects; 
    param_objects.push_back(handle_float, x));
    param_objects.push_back(handle_float, y));

    string params = jsonify_array(param_objects); 
    pairs.push_back(jsonify_pair("params", params, "array")); 

    // Finalize the message 
    message = jsonify_object(pairs);

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
    return deserialize_float(extract_object(response, "result"));
 } 

void searchRectangles(__rectangle[200] rects)  {
    // Compose the remote call
    string message; 
    vector<string> pairs; 

    // Remote Call metadata 
    pairs.push_back(jsonify_pair("method", "searchRectangles", "string"));
    pairs.push_back(jsonify_pair("param_count", "1, "string)); 
 
    // Remote call params 
    vector<string> param_objects; 
    param_objects.push_back(handle___rectangle[200], rects));

    string params = jsonify_array(param_objects); 
    pairs.push_back(jsonify_pair("params", params, "array")); 

    // Finalize the message 
    message = jsonify_object(pairs);

    // Send the remote call
    c150debug->printf(C150RPCDEBUG," searchRectangles() invoked");
    RPCPROXYSOCKET->write(message.c_str(), message.length() + 1); // write function name including null 

    // Read the response
    c150debug->printf(C150RPCDEBUG,"searchRectangles() invocation sent, waiting for response");
    string response = read_message(RPCPROXYSOCKET, read_message_size(RPCPROXYSOCKET));

    // Check the response
    if (extract_bool(response, "error")) { 
        throw C150Exception("searchRectangles() encountered an error during computation"); 
    } 
    c150debug->printf(C150RPCDEBUG, "searchRectangles() successful return from remote call"); 
    return deserialize_void(extract_object(response, "result"));
 } 

void people_func(ThreePeople p)  {
    // Compose the remote call
    string message; 
    vector<string> pairs; 

    // Remote Call metadata 
    pairs.push_back(jsonify_pair("method", "people_func", "string"));
    pairs.push_back(jsonify_pair("param_count", "1, "string)); 
 
    // Remote call params 
    vector<string> param_objects; 
    param_objects.push_back(handle_ThreePeople, p));

    string params = jsonify_array(param_objects); 
    pairs.push_back(jsonify_pair("params", params, "array")); 

    // Finalize the message 
    message = jsonify_object(pairs);

    // Send the remote call
    c150debug->printf(C150RPCDEBUG," people_func() invoked");
    RPCPROXYSOCKET->write(message.c_str(), message.length() + 1); // write function name including null 

    // Read the response
    c150debug->printf(C150RPCDEBUG,"people_func() invocation sent, waiting for response");
    string response = read_message(RPCPROXYSOCKET, read_message_size(RPCPROXYSOCKET));

    // Check the response
    if (extract_bool(response, "error")) { 
        throw C150Exception("people_func() encountered an error during computation"); 
    } 
    c150debug->printf(C150RPCDEBUG, "people_func() successful return from remote call"); 
    return deserialize_void(extract_object(response, "result"));
 } 

int showsArraysofArrays(__int[24] x, __int[24][15] y, __int[24][15] z)  {
    // Compose the remote call
    string message; 
    vector<string> pairs; 

    // Remote Call metadata 
    pairs.push_back(jsonify_pair("method", "showsArraysofArrays", "string"));
    pairs.push_back(jsonify_pair("param_count", "3, "string)); 
 
    // Remote call params 
    vector<string> param_objects; 
    param_objects.push_back(handle___int[24], x));
    param_objects.push_back(handle___int[24][15], y));
    param_objects.push_back(handle___int[24][15], z));

    string params = jsonify_array(param_objects); 
    pairs.push_back(jsonify_pair("params", params, "array")); 

    // Finalize the message 
    message = jsonify_object(pairs);

    // Send the remote call
    c150debug->printf(C150RPCDEBUG," showsArraysofArrays() invoked");
    RPCPROXYSOCKET->write(message.c_str(), message.length() + 1); // write function name including null 

    // Read the response
    c150debug->printf(C150RPCDEBUG,"showsArraysofArrays() invocation sent, waiting for response");
    string response = read_message(RPCPROXYSOCKET, read_message_size(RPCPROXYSOCKET));

    // Check the response
    if (extract_bool(response, "error")) { 
        throw C150Exception("showsArraysofArrays() encountered an error during computation"); 
    } 
    c150debug->printf(C150RPCDEBUG, "showsArraysofArrays() successful return from remote call"); 
    return deserialize_int(extract_object(response, "result"));
 } 

