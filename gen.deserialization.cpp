//                  deserilization.cpp
//
//     This is generated header file for the deserialization 


#include "generic_deserialization.h"
#include "deserialization.h"


int deserialize___int_100(string json) {
    int  my_int[100] = new int [100];
    string objs = extract_array(json, "value");

    for (int i = 0; i < 100; i++) {
         my_int[i] = deserialize_int(consume_object(objs));
    }

    return my_int; 
} 
int *deserialize___int_4__10(string json) {
    int * my___int[4] = new int *[4];
    string objs = extract_array(json, "value");

    for (int i = 0; i < 4; i++) {
         my___int[i] = deserialize___int_10(consume_object(objs));
    }

    return my___int; 
} 
int deserialize___int_3(string json) {
    int  my_int[3] = new int [3];
    string objs = extract_array(json, "value");

    for (int i = 0; i < 3; i++) {
         my_int[i] = deserialize_int(consume_object(objs));
    }

    return my_int; 
} 
StructWithArrays deserialize_StructWithArrays(string json) {

    StructWithArrays *my_StructWithArrays = new struct StructWithArrays;
    string value_obj = extract_object(json, "value");

    my_StructWithArrays->aNumber = deserialize_int(extract_object(value_obj, "aNumber"));
    Person *people =  deserialize___Person_10(extract_object(value_obj, "people")); 
    for (int i = 0; i < 10; i++) { my_StructWithArrays->people[i] = people[i]; }


    return *my_StructWithArrays
}
 
ThreePeople deserialize_ThreePeople(string json) {

    ThreePeople *my_ThreePeople = new struct ThreePeople;
    string value_obj = extract_object(json, "value");

    my_ThreePeople->p1 = deserialize_Person(extract_object(value_obj, "p1"));
    my_ThreePeople->p2 = deserialize_Person(extract_object(value_obj, "p2"));
    my_ThreePeople->p3 = deserialize_Person(extract_object(value_obj, "p3"));

    return *my_ThreePeople
}
 
int *deserialize___int_24__15(string json) {
    int * my___int[24] = new int *[24];
    string objs = extract_array(json, "value");

    for (int i = 0; i < 24; i++) {
         my___int[i] = deserialize___int_15(consume_object(objs));
    }

    return my___int; 
} 
int deserialize___int_4(string json) {
    int  my_int[4] = new int [4];
    string objs = extract_array(json, "value");

    for (int i = 0; i < 4; i++) {
         my_int[i] = deserialize_int(consume_object(objs));
    }

    return my_int; 
} 
int deserialize___int_10(string json) {
    int  my_int[10] = new int [10];
    string objs = extract_array(json, "value");

    for (int i = 0; i < 10; i++) {
         my_int[i] = deserialize_int(consume_object(objs));
    }

    return my_int; 
} 
rectangle deserialize_rectangle(string json) {

    rectangle *my_rectangle = new struct rectangle;
    string value_obj = extract_object(json, "value");

    my_rectangle->x = deserialize_int(extract_object(value_obj, "x"));
    my_rectangle->y = deserialize_int(extract_object(value_obj, "y"));

    return *my_rectangle
}
 
int *deserialize___int_10__100(string json) {
    int * my___int[10] = new int *[10];
    string objs = extract_array(json, "value");

    for (int i = 0; i < 10; i++) {
         my___int[i] = deserialize___int_100(consume_object(objs));
    }

    return my___int; 
} 
int deserialize___int_15(string json) {
    int  my_int[15] = new int [15];
    string objs = extract_array(json, "value");

    for (int i = 0; i < 15; i++) {
         my_int[i] = deserialize_int(consume_object(objs));
    }

    return my_int; 
} 
int **deserialize___int_4__10__100(string json) {
    int ** my___int[4] = new int **[4];
    string objs = extract_array(json, "value");

    for (int i = 0; i < 4; i++) {
         my___int[i] = deserialize___int_10__100(consume_object(objs));
    }

    return my___int; 
} 
Person deserialize_Person(string json) {

    Person *my_Person = new struct Person;
    string value_obj = extract_object(json, "value");

    my_Person->firstname = deserialize_string(extract_object(value_obj, "firstname"));
    my_Person->lastname = deserialize_string(extract_object(value_obj, "lastname"));
    my_Person->age = deserialize_int(extract_object(value_obj, "age"));
    int *favorite_numbers =  deserialize___int_3(extract_object(value_obj, "favorite_numbers")); 
    for (int i = 0; i < 3; i++) { my_Person->favorite_numbers[i] = favorite_numbers[i]; }


    return *my_Person
}
 
rectangle deserialize___rectangle_200(string json) {
    rectangle  my_rectangle[200] = new rectangle [200];
    string objs = extract_array(json, "value");

    for (int i = 0; i < 200; i++) {
         my_rectangle[i] = deserialize_rectangle(consume_object(objs));
    }

    return my_rectangle; 
} 
Person deserialize___Person_10(string json) {
    Person  my_Person[10] = new Person [10];
    string objs = extract_array(json, "value");

    for (int i = 0; i < 10; i++) {
         my_Person[i] = deserialize_Person(consume_object(objs));
    }

    return my_Person; 
} 
MT deserialize_MT(string json) {

    MT *my_MT = new struct MT;
    string value_obj = extract_object(json, "value");


    return *my_MT
}
 
s deserialize_s(string json) {

    s *my_s = new struct s;
    string value_obj = extract_object(json, "value");

    int *m1 =  deserialize___int_4(extract_object(value_obj, "m1")); 
    for (int i = 0; i < 4; i++) { my_s->m1[i] = m1[i]; }

    int *m2 =  deserialize___int_4__10(extract_object(value_obj, "m2")); 
    for (int i = 0; i < 4; i++) { my_s->m2[i] = m2[i]; }

    int *m3 =  deserialize___int_4__10__100(extract_object(value_obj, "m3")); 
    for (int i = 0; i < 4; i++) { my_s->m3[i] = m3[i]; }


    return *my_s
}
 
int deserialize___int_24(string json) {
    int  my_int[24] = new int [24];
    string objs = extract_array(json, "value");

    for (int i = 0; i < 24; i++) {
         my_int[i] = deserialize_int(consume_object(objs));
    }

    return my_int; 
} 
