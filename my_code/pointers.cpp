#include <iostream>
#include "pointers.h"

using namespace std;

// int x; -- defines
// &x -- address of x
// int* iptr = &x -- assigns adress to pointer
// * iptr = 7; -- dereferences
// x = *iptr

void inc_by_value(int n) {
	++n;
}


void inc_with_pointer(int* iptr) {
	++(*iptr);
}


void inc_with_reference(int& n) {
	++n;
}


Thing** create_array_of_things(int n) {
    Thing** thing_arr = new Thing*[n];
	for (int i = 0; i < n; i++) {
		thing_arr[i] = new Thing(i);
	}
	return thing_arr;
}

void print_all_things(Thing** things, int n) {
	for (int i = 0; i < n; i++) {
		cout << things[i]->val << " ";
	}
	cout << endl;
}

void double_all_things(Thing** things, int n) {
	for (int i = 0; i < n; i++) {
		things[i]->val *= 2;
	}
}

void delete_all_things(Thing** things, int n) {
	//cout << "deleted" << endl;
	for (int i = 0; i < n; i++) {
		delete things[i];
	}
	delete[] things;
}


// void assignTA(Student& s, Student& ta) {
// }

// void printTAs(vector<Student> students) {
// }