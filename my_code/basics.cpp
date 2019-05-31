#include <iostream>
#include <string>
#include <vector>
#include "basics.h"

using namespace std;

/*
 * increment arg passed by copy
 * */
void inc_pass_copy(int j) {
	++j;
}

/*
 * increment arg passed by reference
 * */
void inc_pass_ref(int& j) {
	++j;
	// cout << "in inc_pass_ref " << j << endl;
}

/*
 * Fill a vector with n elements from 1 to n.
 * 1st item == 1, 2nd item == 2, etc.
 * 0 filled for you.
 * Use `push_back()` to fill the vector.
 * */
void fill_vector(vector<int>& v, int n) {
	for (int i = 0; i <= n; i ++){
		// cout << "Filling v with " << i << endl;
		v.push_back(i);
	}
}

/*
 * Print all elements in a vector. Use a ranged for!
 * */
void print_vector(const vector<int>& v) {
	cout << "In print v\n";
	for (int i : v){
		cout << i << " ";
	}
	cout << endl;
}

/*
 * Print a pair of coordinates.
 * Output should look like x = 7, y =8
 * */
void print_coords(coord pos) {
	cout << "x = " << pos.x << ", y = " << pos.y << endl;
}

/*
 * Square an integer.
 * */
int square(int n) {
	n*=n;
    return n;
}

/*
 * Square a double.
 * */
double square(double d) {
	d*=d;
    return d;
}

/*
 * Get the absolute value of a number.
 * */
int my_abs(int n) {
	if (n < 0){
		n = n * (-1);
	}
	return n;
}

/*
 * Sum from 0 to n using a `while` loop.
 * */
int sum(int n) {
	int add = 0;
	int curr = 0;
	while (curr < n){
		add += curr;
		curr++;
	}
    return add;
}

/*
 * Sum from 0 to n using a `for` loop.
 * */
int sum2(int n) {
	int add = 0;
	for (int i = 0; i < n; i ++){
		add += i;
	}
    return add;
}

/*
 * say() is built for you!
 * */
void say(std::string s) {
    cout << s << endl;
}


/*
 * Use a ranged for to pull a string apart into its bits.
 * */
void pull_apart_string(std::string s) {
	for (char c : s){
		cout << c;
	}
}