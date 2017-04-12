//                  serilization.cpp
//
//     This is generated implementation file for the serialization 


#include "generic_serialization.h"
#include "serialization.h"


string serialize___int_100(int my___int[100] [100]) {
    vector<string> param_pairs; 
 
    // value to string conversion 
    string type = "int[100]"; 
    vector <string> elements; 
 
    for (int i = 0; i < 99; i++) { 
         elements.push_back(serialize_in(my___int[100][i]));
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

string serialize___int_4__10(int[10] my___int[4][10] [4]) {
    vector<string> param_pairs; 
 
    // value to string conversion 
    string type = "int[4][10]"; 
    vector <string> elements; 
 
    for (int i = 0; i < 3; i++) { 
         elements.push_back(serialize___int_10(my___int[4][10][i]));
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

string serialize___int_3(int my___int[3] [3]) {
    vector<string> param_pairs; 
 
    // value to string conversion 
    string type = "int[3]"; 
    vector <string> elements; 
 
    for (int i = 0; i < 2; i++) { 
         elements.push_back(serialize_in(my___int[3][i]));
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
 
    elements.push_back(serialize_pair("aNumber", my_in(StructWithArrays.aNumber), "object");
    elements.push_back(serialize_pair("people", my___Person_10(StructWithArrays.people), "object");

    // compose the inner description object
    param_pairs.push_back(serialize_pair(TYPE_KEY, type, "string"));
    param_pairs.push_back(serialize_pair(STRUCT_KEY, "true", "bool"));
    param_pairs.push_back(serialize_pair(ARRAY_KEY, "false", "bool"));
    param_pairs.push_back(serialize_pair(VALUE_KEY, value.str(), "object"));

    return serialize_object(param_pairs);
}

string serialize_ThreePeople(ThreePeople my_ThreePeople) {
    vector<string> param_pairs; 
 
    // value to string conversion 
    string type = "ThreePeople"; 
    vector <string> elements; 
 
    elements.push_back(serialize_pair("p1", my_Perso(ThreePeople.p1), "object");
    elements.push_back(serialize_pair("p2", my_Perso(ThreePeople.p2), "object");
    elements.push_back(serialize_pair("p3", my_Perso(ThreePeople.p3), "object");

    // compose the inner description object
    param_pairs.push_back(serialize_pair(TYPE_KEY, type, "string"));
    param_pairs.push_back(serialize_pair(STRUCT_KEY, "true", "bool"));
    param_pairs.push_back(serialize_pair(ARRAY_KEY, "false", "bool"));
    param_pairs.push_back(serialize_pair(VALUE_KEY, value.str(), "object"));

    return serialize_object(param_pairs);
}

string serialize___int_24__15(int[15] my___int[24][15] [24]) {
    vector<string> param_pairs; 
 
    // value to string conversion 
    string type = "int[24][15]"; 
    vector <string> elements; 
 
    for (int i = 0; i < 23; i++) { 
         elements.push_back(serialize___int_15(my___int[24][15][i]));
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

string serialize___int_4(int my___int[4] [4]) {
    vector<string> param_pairs; 
 
    // value to string conversion 
    string type = "int[4]"; 
    vector <string> elements; 
 
    for (int i = 0; i < 3; i++) { 
         elements.push_back(serialize_in(my___int[4][i]));
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

string serialize___int_10(int my___int[10] [10]) {
    vector<string> param_pairs; 
 
    // value to string conversion 
    string type = "int[10]"; 
    vector <string> elements; 
 
    for (int i = 0; i < 9; i++) { 
         elements.push_back(serialize_in(my___int[10][i]));
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

string serialize_rectangle(rectangle my_rectangle) {
    vector<string> param_pairs; 
 
    // value to string conversion 
    string type = "rectangle"; 
    vector <string> elements; 
 
    elements.push_back(serialize_pair("x", my_in(rectangle.x), "object");
    elements.push_back(serialize_pair("y", my_in(rectangle.y), "object");

    // compose the inner description object
    param_pairs.push_back(serialize_pair(TYPE_KEY, type, "string"));
    param_pairs.push_back(serialize_pair(STRUCT_KEY, "true", "bool"));
    param_pairs.push_back(serialize_pair(ARRAY_KEY, "false", "bool"));
    param_pairs.push_back(serialize_pair(VALUE_KEY, value.str(), "object"));

    return serialize_object(param_pairs);
}

string serialize___int_10__100(int[100] my___int[10][100] [10]) {
    vector<string> param_pairs; 
 
    // value to string conversion 
    string type = "int[10][100]"; 
    vector <string> elements; 
 
    for (int i = 0; i < 9; i++) { 
         elements.push_back(serialize___int_100(my___int[10][100][i]));
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

string serialize___int_15(int my___int[15] [15]) {
    vector<string> param_pairs; 
 
    // value to string conversion 
    string type = "int[15]"; 
    vector <string> elements; 
 
    for (int i = 0; i < 14; i++) { 
         elements.push_back(serialize_in(my___int[15][i]));
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

string serialize___int_4__10__100(int[10][100] my___int[4][10][100] [4]) {
    vector<string> param_pairs; 
 
    // value to string conversion 
    string type = "int[4][10][100]"; 
    vector <string> elements; 
 
    for (int i = 0; i < 3; i++) { 
         elements.push_back(serialize___int_10__100(my___int[4][10][100][i]));
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
 
    elements.push_back(serialize_pair("firstname", my_strin(Person.firstname), "object");
    elements.push_back(serialize_pair("lastname", my_strin(Person.lastname), "object");
    elements.push_back(serialize_pair("age", my_in(Person.age), "object");
    elements.push_back(serialize_pair("favorite_numbers", my___int_3(Person.favorite_numbers), "object");

    // compose the inner description object
    param_pairs.push_back(serialize_pair(TYPE_KEY, type, "string"));
    param_pairs.push_back(serialize_pair(STRUCT_KEY, "true", "bool"));
    param_pairs.push_back(serialize_pair(ARRAY_KEY, "false", "bool"));
    param_pairs.push_back(serialize_pair(VALUE_KEY, value.str(), "object"));

    return serialize_object(param_pairs);
}

string serialize___rectangle_200(rectangle my___rectangle[200] [200]) {
    vector<string> param_pairs; 
 
    // value to string conversion 
    string type = "rectangle[200]"; 
    vector <string> elements; 
 
    for (int i = 0; i < 199; i++) { 
         elements.push_back(serialize_rectangl(my___rectangle[200][i]));
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

string serialize___Person_10(Person my___Person[10] [10]) {
    vector<string> param_pairs; 
 
    // value to string conversion 
    string type = "Person[10]"; 
    vector <string> elements; 
 
    for (int i = 0; i < 9; i++) { 
         elements.push_back(serialize_Perso(my___Person[10][i]));
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
 

    // compose the inner description object
    param_pairs.push_back(serialize_pair(TYPE_KEY, type, "string"));
    param_pairs.push_back(serialize_pair(STRUCT_KEY, "true", "bool"));
    param_pairs.push_back(serialize_pair(ARRAY_KEY, "false", "bool"));
    param_pairs.push_back(serialize_pair(VALUE_KEY, value.str(), "object"));

    return serialize_object(param_pairs);
}

string serialize_s(s my_s) {
    vector<string> param_pairs; 
 
    // value to string conversion 
    string type = "s"; 
    vector <string> elements; 
 
    elements.push_back(serialize_pair("m1", my___int_4(s.m1), "object");
    elements.push_back(serialize_pair("m2", my___int_4__10(s.m2), "object");
    elements.push_back(serialize_pair("m3", my___int_4__10__100(s.m3), "object");

    // compose the inner description object
    param_pairs.push_back(serialize_pair(TYPE_KEY, type, "string"));
    param_pairs.push_back(serialize_pair(STRUCT_KEY, "true", "bool"));
    param_pairs.push_back(serialize_pair(ARRAY_KEY, "false", "bool"));
    param_pairs.push_back(serialize_pair(VALUE_KEY, value.str(), "object"));

    return serialize_object(param_pairs);
}

string serialize___int_24(int my___int[24] [24]) {
    vector<string> param_pairs; 
 
    // value to string conversion 
    string type = "int[24]"; 
    vector <string> elements; 
 
    for (int i = 0; i < 23; i++) { 
         elements.push_back(serialize_in(my___int[24][i]));
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

