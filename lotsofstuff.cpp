using namespace std;
#include <string>

#include "lotsofstuff.idl"
#include <stdexcept>
#include <iostream>

void person_func(Person p) {

	cout << "firstname: " << p.firstname << endl;
	cout << "lastname: " << p.lastname << endl;
	cout << "age:" << p.age << endl;
 
 	for (int i = 0; i < 3; i++) {
 		cout << "favorite num: " << p.favorite_numbers[i] << endl;
 	}

}

void people_func(ThreePeople people) {
 	cout << "person1 name" << people.p1.firstname << endl;;
 	cout << "person2 name" << people.p2.firstname << endl;;
 	cout << "person3 name" << people.p3.firstname << endl;;
}

int sum(int x[3]) {
 	int sum = 0; 
 	for (int i = 0; i < 3; i++) {
 		sum += x[i]; 
 	}

 	return sum;
}

int takesTwoArrays(int x[24], int y[24]) {
  return 1;
}

int takesTwoSuperArrays(float x[4][2], float y[4][3][6]) {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 2; j++) {
      cout << x[i][j] << " ";
    }
    cout << endl;
  }

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 3; j++) {
      for (int k = 0; k < 6; k++) {
        cout << y[i][j][k] << " ";
      }
      cout << endl;
    }
    cout << endl;
  }

  return 10e-24;
}

void searchRectangles(rectangle rects[200]) {
  return;
}