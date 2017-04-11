#include <cstdio>
#include <cstring>
#include <iostream>
#include <sstream>
#include <stdbool.h>
#include <string>
#include <vector>

//
// TCP message utility functions
//

size_t read_message_size(C150NETWORK::C150StreamSocket *socket);
string read_message(C150NETWORK::C150StreamSocket *socket, size_t message_size);

//
// JSON utility functions.
// 
// "extract_xxx" functions extract the value from key/value pairs from a JSON object.
//

string consume_object(string &json);
string extract_array(string json, string key);
bool extract_bool(string json, string key);
float extract_float(string json, string key);
int extract_int(string json, string key);
string extract_object(string json, string key);
string extract_string(string json, string key);


// Proxy utility Functions 
string serialize_pair(string key, string value, string json_type);
string serialize_object(vector<string> pairs);
string serialize_array(vector<string> objects);

string serialize_int(int my_int);
string serialize_bool(bool my_bool);
string serialize_string(string my_string);
string serialize_char(char my_char);