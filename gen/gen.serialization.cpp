//                  serilization.cpp
//
//     This is generated implementation file for the serialization 


using namespace std;
#include <string>


#include "lotsofstuff.idl"
#include "generic_serialization.h"
#include "serialization.h"

string serialize___int_100(int my___int_100[100]) {
    vector<string> param_pairs; 
 
    // value to string conversion 
    string type = "int[100]"; 
    vector <string> elements; 
 
    for (int i = 0; i < 100; i++) { 
         elements.push_back(serialize_int(my___int_100[i]));
    }
    stringstream value;
    value << serialize_array(elements); 

    // compose the inner description object
    param_pairs.push_back(serialize_pair(TYPE_KEY, type, "string"));
    param_pairs.push_back(serialize_pair(STRUCT_KEY, "false", "bool"));
    param_pairs.push_back(serialize_pair(ARRAY_KEY, "true", "bool"));
    param_pairs.push_back(serialize_pair(VALUE_KEY, value.str(), "object"));

    return serialize_object(param_pairs);
}

string serialize_ThreePeople(ThreePeople my_ThreePeople) {
    vector<string> param_pairs; 
 
    // value to string conversion 
    string type = "ThreePeople"; 
    vector <string> elements; 
 
    elements.push_back(serialize_pair("ThreePeople", serialize_Person(my_ThreePeople.p1), "object"));
    elements.push_back(serialize_pair("ThreePeople", serialize_Person(my_ThreePeople.p2), "object"));
    elements.push_back(serialize_pair("ThreePeople", serialize_Person(my_ThreePeople.p3), "object"));
    stringstream value;
    value << serialize_object(elements); 

    // compose the inner description object
    param_pairs.push_back(serialize_pair(TYPE_KEY, type, "string"));
    param_pairs.push_back(serialize_pair(STRUCT_KEY, "true", "bool"));
    param_pairs.push_back(serialize_pair(ARRAY_KEY, "false", "bool"));
    param_pairs.push_back(serialize_pair(VALUE_KEY, value.str(), "object"));

    return serialize_object(param_pairs);
}

string serialize___int_10__100(int my___int_10__100[10][100]) {
    vector<string> param_pairs; 
 
    // value to string conversion 
    string type = "int[10][100]"; 
    vector <string> elements; 
 
    for (int i = 0; i < 10; i++) { 
         elements.push_back(serialize___int_100(my___int_10__100[i]));
    }
    stringstream value;
    value << serialize_array(elements); 

    // compose the inner description object
    param_pairs.push_back(serialize_pair(TYPE_KEY, type, "string"));
    param_pairs.push_back(serialize_pair(STRUCT_KEY, "false", "bool"));
    param_pairs.push_back(serialize_pair(ARRAY_KEY, "true", "bool"));
    param_pairs.push_back(serialize_pair(VALUE_KEY, value.str(), "object"));

    return serialize_object(param_pairs);
}

string serialize___int_4(int my___int_4[4]) {
    vector<string> param_pairs; 
 
    // value to string conversion 
    string type = "int[4]"; 
    vector <string> elements; 
 
    for (int i = 0; i < 4; i++) { 
         elements.push_back(serialize_int(my___int_4[i]));
    }
    stringstream value;
    value << serialize_array(elements); 

    // compose the inner description object
    param_pairs.push_back(serialize_pair(TYPE_KEY, type, "string"));
    param_pairs.push_back(serialize_pair(STRUCT_KEY, "false", "bool"));
    param_pairs.push_back(serialize_pair(ARRAY_KEY, "true", "bool"));
    param_pairs.push_back(serialize_pair(VALUE_KEY, value.str(), "object"));

    return serialize_object(param_pairs);
}

string serialize_Person(Person my_Person) {
    vector<string> param_pairs; 
 
    // value to string conversion 
    string type = "Person"; 
    vector <string> elements; 
 
    elements.push_back(serialize_pair("Person", serialize_string(my_Person.firstname), "object"));
    elements.push_back(serialize_pair("Person", serialize_string(my_Person.lastname), "object"));
    elements.push_back(serialize_pair("Person", serialize_int(my_Person.age), "object"));
    elements.push_back(serialize_pair("Person", serialize___int_3(my_Person.favorite_numbers), "object"));
    stringstream value;
    value << serialize_object(elements); 

    // compose the inner description object
    param_pairs.push_back(serialize_pair(TYPE_KEY, type, "string"));
    param_pairs.push_back(serialize_pair(STRUCT_KEY, "true", "bool"));
    param_pairs.push_back(serialize_pair(ARRAY_KEY, "false", "bool"));
    param_pairs.push_back(serialize_pair(VALUE_KEY, value.str(), "object"));

    return serialize_object(param_pairs);
}

string serialize___Person_10(Person my___Person_10[10]) {
    vector<string> param_pairs; 
 
    // value to string conversion 
    string type = "Person[10]"; 
    vector <string> elements; 
 
    for (int i = 0; i < 10; i++) { 
         elements.push_back(serialize_Person(my___Person_10[i]));
    }
    stringstream value;
    value << serialize_array(elements); 

    // compose the inner description object
    param_pairs.push_back(serialize_pair(TYPE_KEY, type, "string"));
    param_pairs.push_back(serialize_pair(STRUCT_KEY, "false", "bool"));
    param_pairs.push_back(serialize_pair(ARRAY_KEY, "true", "bool"));
    param_pairs.push_back(serialize_pair(VALUE_KEY, value.str(), "object"));

    return serialize_object(param_pairs);
}

string serialize___int_4__10__100(int my___int_4__10__100[4][10][100]) {
    vector<string> param_pairs; 
 
    // value to string conversion 
    string type = "int[4][10][100]"; 
    vector <string> elements; 
 
    for (int i = 0; i < 4; i++) { 
         elements.push_back(serialize___int_10__100(my___int_4__10__100[i]));
    }
    stringstream value;
    value << serialize_array(elements); 

    // compose the inner description object
    param_pairs.push_back(serialize_pair(TYPE_KEY, type, "string"));
    param_pairs.push_back(serialize_pair(STRUCT_KEY, "false", "bool"));
    param_pairs.push_back(serialize_pair(ARRAY_KEY, "true", "bool"));
    param_pairs.push_back(serialize_pair(VALUE_KEY, value.str(), "object"));

    return serialize_object(param_pairs);
}

string serialize___int_4__10(int my___int_4__10[4][10]) {
    vector<string> param_pairs; 
 
    // value to string conversion 
    string type = "int[4][10]"; 
    vector <string> elements; 
 
    for (int i = 0; i < 4; i++) { 
         elements.push_back(serialize___int_10(my___int_4__10[i]));
    }
    stringstream value;
    value << serialize_array(elements); 

    // compose the inner description object
    param_pairs.push_back(serialize_pair(TYPE_KEY, type, "string"));
    param_pairs.push_back(serialize_pair(STRUCT_KEY, "false", "bool"));
    param_pairs.push_back(serialize_pair(ARRAY_KEY, "true", "bool"));
    param_pairs.push_back(serialize_pair(VALUE_KEY, value.str(), "object"));

    return serialize_object(param_pairs);
}

string serialize_s(s my_s) {
    vector<string> param_pairs; 
 
    // value to string conversion 
    string type = "s"; 
    vector <string> elements; 
 
    elements.push_back(serialize_pair("s", serialize___int_4(my_s.m1), "object"));
    elements.push_back(serialize_pair("s", serialize___int_4__10(my_s.m2), "object"));
    elements.push_back(serialize_pair("s", serialize___int_4__10__100(my_s.m3), "object"));
    stringstream value;
    value << serialize_object(elements); 

    // compose the inner description object
    param_pairs.push_back(serialize_pair(TYPE_KEY, type, "string"));
    param_pairs.push_back(serialize_pair(STRUCT_KEY, "true", "bool"));
    param_pairs.push_back(serialize_pair(ARRAY_KEY, "false", "bool"));
    param_pairs.push_back(serialize_pair(VALUE_KEY, value.str(), "object"));

    return serialize_object(param_pairs);
}

string serialize___int_3(int my___int_3[3]) {
    vector<string> param_pairs; 
 
    // value to string conversion 
    string type = "int[3]"; 
    vector <string> elements; 
 
    for (int i = 0; i < 3; i++) { 
         elements.push_back(serialize_int(my___int_3[i]));
    }
    stringstream value;
    value << serialize_array(elements); 

    // compose the inner description object
    param_pairs.push_back(serialize_pair(TYPE_KEY, type, "string"));
    param_pairs.push_back(serialize_pair(STRUCT_KEY, "false", "bool"));
    param_pairs.push_back(serialize_pair(ARRAY_KEY, "true", "bool"));
    param_pairs.push_back(serialize_pair(VALUE_KEY, value.str(), "object"));

    return serialize_object(param_pairs);
}

string serialize_MT(MT my_MT) {
    vector<string> param_pairs; 
 
    // value to string conversion 
    string type = "MT"; 
    vector <string> elements; 
 
    stringstream value;
    value << serialize_object(elements); 

    // compose the inner description object
    param_pairs.push_back(serialize_pair(TYPE_KEY, type, "string"));
    param_pairs.push_back(serialize_pair(STRUCT_KEY, "true", "bool"));
    param_pairs.push_back(serialize_pair(ARRAY_KEY, "false", "bool"));
    param_pairs.push_back(serialize_pair(VALUE_KEY, value.str(), "object"));

    return serialize_object(param_pairs);
}

string serialize___int_24(int my___int_24[24]) {
    vector<string> param_pairs; 
 
    // value to string conversion 
    string type = "int[24]"; 
    vector <string> elements; 
 
    for (int i = 0; i < 24; i++) { 
         elements.push_back(serialize_int(my___int_24[i]));
    }
    stringstream value;
    value << serialize_array(elements); 

    // compose the inner description object
    param_pairs.push_back(serialize_pair(TYPE_KEY, type, "string"));
    param_pairs.push_back(serialize_pair(STRUCT_KEY, "false", "bool"));
    param_pairs.push_back(serialize_pair(ARRAY_KEY, "true", "bool"));
    param_pairs.push_back(serialize_pair(VALUE_KEY, value.str(), "object"));

    return serialize_object(param_pairs);
}

string serialize___rectangle_200(rectangle my___rectangle_200[200]) {
    vector<string> param_pairs; 
 
    // value to string conversion 
    string type = "rectangle[200]"; 
    vector <string> elements; 
 
    for (int i = 0; i < 200; i++) { 
         elements.push_back(serialize_rectangle(my___rectangle_200[i]));
    }
    stringstream value;
    value << serialize_array(elements); 

    // compose the inner description object
    param_pairs.push_back(serialize_pair(TYPE_KEY, type, "string"));
    param_pairs.push_back(serialize_pair(STRUCT_KEY, "false", "bool"));
    param_pairs.push_back(serialize_pair(ARRAY_KEY, "true", "bool"));
    param_pairs.push_back(serialize_pair(VALUE_KEY, value.str(), "object"));

    return serialize_object(param_pairs);
}

string serialize___int_10(int my___int_10[10]) {
    vector<string> param_pairs; 
 
    // value to string conversion 
    string type = "int[10]"; 
    vector <string> elements; 
 
    for (int i = 0; i < 10; i++) { 
         elements.push_back(serialize_int(my___int_10[i]));
    }
    stringstream value;
    value << serialize_array(elements); 

    // compose the inner description object
    param_pairs.push_back(serialize_pair(TYPE_KEY, type, "string"));
    param_pairs.push_back(serialize_pair(STRUCT_KEY, "false", "bool"));
    param_pairs.push_back(serialize_pair(ARRAY_KEY, "true", "bool"));
    param_pairs.push_back(serialize_pair(VALUE_KEY, value.str(), "object"));

    return serialize_object(param_pairs);
}

string serialize_StructWithArrays(StructWithArrays my_StructWithArrays) {
    vector<string> param_pairs; 
 
    // value to string conversion 
    string type = "StructWithArrays"; 
    vector <string> elements; 
 
    elements.push_back(serialize_pair("StructWithArrays", serialize_int(my_StructWithArrays.aNumber), "object"));
    elements.push_back(serialize_pair("StructWithArrays", serialize___Person_10(my_StructWithArrays.people), "object"));
    stringstream value;
    value << serialize_object(elements); 

    // compose the inner description object
    param_pairs.push_back(serialize_pair(TYPE_KEY, type, "string"));
    param_pairs.push_back(serialize_pair(STRUCT_KEY, "true", "bool"));
    param_pairs.push_back(serialize_pair(ARRAY_KEY, "false", "bool"));
    param_pairs.push_back(serialize_pair(VALUE_KEY, value.str(), "object"));

    return serialize_object(param_pairs);
}

string serialize_rectangle(rectangle my_rectangle) {
    vector<string> param_pairs; 
 
    // value to string conversion 
    string type = "rectangle"; 
    vector <string> elements; 
 
    elements.push_back(serialize_pair("rectangle", serialize_int(my_rectangle.x), "object"));
    elements.push_back(serialize_pair("rectangle", serialize_int(my_rectangle.y), "object"));
    stringstream value;
    value << serialize_object(elements); 

    // compose the inner description object
    param_pairs.push_back(serialize_pair(TYPE_KEY, type, "string"));
    param_pairs.push_back(serialize_pair(STRUCT_KEY, "true", "bool"));
    param_pairs.push_back(serialize_pair(ARRAY_KEY, "false", "bool"));
    param_pairs.push_back(serialize_pair(VALUE_KEY, value.str(), "object"));

    return serialize_object(param_pairs);
}

