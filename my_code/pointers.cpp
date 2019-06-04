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
	// new -> allocates new heap memory
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
	cout << endl;
}

void delete_all_things(Thing** things, int n) {
	// cout << "deleted" << endl;
	// delete -> frees heap memory
	for (int i = 0; i < n; i++) {
		delete things[i];
	}
	delete[] things;
}


void assignTA(Student* s, Student* ta) {
	// uses pointer syntax to point to the ta field
	s->ta = ta;
}

void printTAs(vector<Student*>& students) {
	// uses vector of student pointers
	// ta is a pointer to a student
	// student is a pointer to a ta
	for (Student* student : students){
		// if pointer is null, they don't have a ta
		if (student->ta == nullptr) {
			cout << student->name << " does not have a TA." << endl;
		}
		// if pointer is not null, they have a ta
		else{
			cout << student-> name << " has TA " << student->ta->name << endl;
		}
	}
	cout << endl;
}