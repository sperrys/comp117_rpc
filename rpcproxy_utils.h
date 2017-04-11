
//
//							 rpcproxy_utils.h 
//							
//						Aaron Bowen and Spencer Perry
//					
//
//				 function declarations for useful proxy functions
//
//


#include "rpcproxyhelper.h"

#include "c150debug.h"
#include <cstdio>
#include <stdbool.h>
#include <cstring>
#include <iostream>
#include <sstream>
#include <vector>

using namespace C150NETWORK;  // for all the comp150 utilities 


string jsonify_pair(string key, string value, string json_type);
string jsonify_object(vector<string> pairs);
string jsonify_array(vector<string> objects);
string handle_int(int my_int);
string handle_bool(bool my_bool);
string handle_string(string my_string);
string handle_char(char my_char);
