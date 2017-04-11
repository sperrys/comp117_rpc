
//
//
//							rpc_utility_funcs.h
//
// 						Aaron Bowen and Spencer Perry
// 
//					Useful function declarations written for the stub
// 


#include <string>
#include <cstdio>
#include <cstring>
#include <regex>
#include "rpcstubhelper.h"

using namespace std; 
using namespace C150NETWORK; 

size_t read_message_size();
string read_message(size_t message_size);

size_t extract_object_length(string json);
string extract_object(string json, string key);

float extract_float(string json, string key);
int extract_int(string json, string key);
string extract_string(string json, string key);
string extract_array(string json, string key);