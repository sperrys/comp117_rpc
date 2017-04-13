#include <string>
using namespace std;

#include "lotsofstuff.idl"
#include <stdexcept>
#include <iostream>

void person_func(Person p) {

	cout << "firstname: " << p.firstname << endl;
	cout << "lastname: " << p.lastname << endl;
	cout << "age:" << p.age << endl;
 
 	for (int i = 0; i < 3; i++) {
 		cout << "favorite num: " << p.favorite_numbers[i];
 	}

 }

 void people_func(ThreePeople people) {
 	cout << "person1 name" << people.p1.firstname;
 	cout << "person2 name" << people.p2.firstname;
 	cout << "person3 name" << people.p3.firstname;
 }

 int sum(int x[3]) {
 	int sum = 0; 
 	for (int i = 0; i < 3; i++) {
 		sum += i; 
 	}

 	return sum;
 }