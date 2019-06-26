#include <cassert>
#include <iostream>
#include <string>
#include <vector>
#include "../my_code/template_ll.h"

using namespace std;

ostream& operator<<(ostream& os, const vector<int> v){
	for (int i : v) {
		os << i << " ";
	}
	os << endl;
	return os;
}

int main() {
	/* INTEGER LL */
	Node<int>* ihead = nullptr;
	ihead = new Node<int>(8, nullptr);
 	add_at_end(ihead, 16);
	print_list(cout, ihead);
	// now reverse it:
    Node<int>* ireversed = reverse(ihead, (Node<int>*)nullptr); // cast: (Node<int>*), fills the place of nullptr
    cout << "Reversed int lst: \n";
    print_list(cout, ireversed);
    assert(ireversed->data == 16);
    cout << endl;


	/* STRING LL */
	Node<string>* shead = nullptr;
	shead = new Node<string>("Hello", nullptr);
	string s = " world!";
	add_at_end(shead, s);
	print_list(cout, shead);
	// now reverse it:
    Node<string>* sreversed = reverse(shead, (Node<string>*)nullptr); // cast: (Node<int>*), fills the place of nullptr
    cout << "Reversed string lst: \n";
    print_list(cout, sreversed);
    assert(sreversed->data == s);
    cout << endl;


	/* DOUBLE LL */
	Node<double>* dhead = nullptr;
	dhead = new Node<double>(34.2, nullptr);
	add_at_end(dhead, 65.4);
	print_list(cout, dhead);
	// now reverse it:
    Node<double>* dreversed = reverse(dhead, (Node<double>*)nullptr); // cast: (Node<int>*), fills the place of nullptr
    cout << "Reversed double lst: \n";
    print_list(cout, dreversed);
    assert(dreversed->data == 65.4);
    cout << endl;


	/* VECTOR LL (template of templates) */ 
	vector<int> v1 = {0, 1, 2};
	vector<int> v2 = {3, 4, 5};
	Node<vector<int>>* vhead = nullptr;
	vhead = new Node<vector<int>>(v1, nullptr);
	add_at_end(vhead, v2);
	print_list(cout, vhead);
	cout << endl;
	// now reverse it:
    Node<vector<int>>* vreversed = reverse(vhead, (Node<vector<int>>*)nullptr); // cast: (Node<int>*), fills the place of nullptr
    cout << "Reversed vector lst: \n";
    print_list(cout, vreversed);
    assert(vreversed->data == v2);
}