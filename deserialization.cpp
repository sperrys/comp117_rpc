using namespace std;
#include <string>

#include <regex>

#include "arithmetic.idl"
#include "lotsofstuff.idl"

#include "generic_deserialization.h"
#include "deserialization.h"

int* deserialize_int_3(string int_3_obj) {
  int *my_int = new int[3];
  string ints = extract_array(int_3_obj, "value");

  for (int i = 0; i < 3; i++) {
    my_int[i] = deserialize_int(consume_object(ints));
  }

  return my_int;
}

Person* deserialize_people_3(string people_3_obj) {
  Person *my_people = new Person[3];
  string people = extract_array(people_3_obj, "value");

  for (int i = 0; i < 3; i++) {
    my_people[i] = deserialize_person(consume_object(people));
  }

  return my_people;
}

Person deserialize_person(string person_obj) {
  Person *my_person = new struct Person;
  string value_obj = extract_object(person_obj, "value");

  my_person->firstname = deserialize_string(extract_object(value_obj, "firstname"));
  my_person->lastname = deserialize_string(extract_object(value_obj, "lastname"));
  my_person->age = deserialize_int(extract_object(value_obj, "age"));
  
  // can't assign arrays directly, so need to loop through to assign each value
  int *favorite_numbers = deserialize_int_3(extract_object(value_obj, "favorite_numbers"));
  for (int i = 0; i < 3; i++) { my_person->favorite_numbers[i] = favorite_numbers[i]; }
 
  return *my_person;
}

ThreePeople deserialize_ThreePeople(string ThreePeople_obj) {
  ThreePeople* people = new struct ThreePeople;
  string value_obj = extract_object(ThreePeople_obj, "value");

  people->p1 = deserialize_person(extract_object(value_obj, "p1"));
  people->p2 = deserialize_person(extract_object(value_obj, "p2"));
  people->p3 = deserialize_person(extract_object(value_obj, "p3"));

  return *people;
}
