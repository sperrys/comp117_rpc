// 
//       generic_serialization.h 
//
// 	     Aaron Bowen and Spencer Perry
//
//       This header file for all serialization that 
//       isn't depend on the idl.
//

#include <vector>

string serialize_array(vector<string> objects);
string serialize_bool(bool my_bool);
string serialize_char(char my_char);
string serialize_int(int my_int);
string serialize_object(vector<string> pairs);
string serialize_pair(string key, string value, string json_type);
string serialize_string(string my_string);