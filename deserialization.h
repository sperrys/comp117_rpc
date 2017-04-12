Person deserialize_person(string person_obj);
Person* deserialize_people_3(string json);
ThreePeople deserialize_ThreePeople(string ThreePeople_obj);
float deserialize_float(string json);
int *deserialize_int_3(string json);
int deserialize_int(string json);
string deserialize_string(string json);

bool extract_bool(string json, string key);
float extract_float(string json, string key);
int extract_int(string json, string key);
string extract_array(string json, string key);
string extract_object(string json, string key);
string extract_string(string json, string key);
string consume_object(string &json);
