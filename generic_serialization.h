// 
//       generic_serialization.h 
//
// 	     Aaron Bowen and Spencer Perry
//
//       This header file for all serialization that 
//       isn't depend on the idl.
//

#include <vector>
#include <string>
#include <sstream>

using namespace std;

const string VALUE_KEY = "value";
const string TYPE_KEY = "type";
const string STRUCT_KEY = "is_struct";
const string ARRAY_KEY = "is_array";

string serialize_array(vector<string> objects);
string serialize_bool(bool my_bool);
string serialize_char(char my_char);
string serialize_int(int my_int);
string serialize_float(float my_float);
string serialize_object(vector<string> pairs);
string serialize_pair(string key, string value, string json_type);
string serialize_string(string my_string);
string serialize_void();