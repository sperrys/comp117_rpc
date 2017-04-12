#include <vector>

string serialize_Person(Person my_Person);
string serialize_ThreePeople(ThreePeople my_ThreePeople);
string serialize_array(vector<string> objects);
string serialize_bool(bool my_bool);
string serialize_char(char my_char);
string serialize_int(int my_int);
string serialize_int_3(int my_int_3[3]);
string serialize_object(vector<string> pairs);
string serialize_pair(string key, string value, string json_type);
string serialize_people_array(Person p[3]);
string serialize_string(string my_string);
