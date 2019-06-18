#include <iostream>
#include "vector.h"

using namespace std;

// PRINT VECTOR
void print_vector(vector v)
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}

// DEFAULT CONSTRUCTOR
vector::vector()
{
	sz = 0;
	capacity = DEF_CAPACITY;
	data = new int[DEF_CAPACITY];
}

// COPY CONTROL:

// COPY CONSTRUCTOR
vector::vector(const vector&v2)
{
	copy_fields(v2); // defined in line 108
}
// DESTRUCTOR
vector::~vector()
{
	if (data != nullptr) delete[] data; // just precaution 
	// delete[] data; 
}
// ASSIGNMENT OPERATOR
// * Has to do what the destructor does and then do what the copy constructor does
// * You can't call a Destructor and the Copy Constructor will create another object instead of changing yours
vector& vector::operator=(const vector& v2)
{
	if (&v2 != this) // make sure it is not your own data (a self assignment)
	{ 
		delete[] data;
		copy_fields(v2); // defined in line 108
	}
	return *this;
}


// PUSH BACK
void vector::push_back(int val)
{
	if (sz == capacity) // we should not be able to write beyond our capacity
	{
		// cout << "Increasing capacity\n";
		capacity *= 2; // get new array of capacity * 2
		int* new_data = new int[capacity]; // grab the memory of double capacity
		for (int i = 0; i < size(); i++) // copy over existing data
		{
			new_data[i] = data[i];
		}
		delete[] data; // delete old array
		data = new_data; // set pointer to new array
	}
	data[sz++] = val; // Post-increment --> after we store element, we up the size
					  // In py, this line would be written as:
					  // * data[sz] = val
					  // * sz += 1
}

// OVERRIDING THE [] OPERATOR

// BY VALUE
int vector::operator[](int i) const // returns integer - used when we need to get smth out of the vector
{
	return data[i]; // the name of a C Array is a POINTER to the FIRST ELEMENT
}

// BY REFERENCE
int& vector::operator[](int i) // reference to the address of the vector so that we can change it (like double it)
{
	return data[i];
}

// OVERRIDING THE == OPERATOR

bool operator==(vector& v1, vector& v2)
{
	if (v1.size() != v2.size())
	{
		return false;
	}
	else
	{
		for (int i = 0; i < v1.size(); i++)
		{
			if (v1[i] != v2[i])
			{
				return false;
			}
		}
	}
	return true;
}

// COPY FIELDS
void vector::copy_fields(const vector& v2)
{
	// Copying all members of v2:
	capacity = v2.capacity;
	sz = v2.size();
	data = new int[capacity]; // data member of the class
	// Copying over existing data:
	for (int i = 0; i < size(); i++)
	{
		data[i] = v2.data[i];
	}
}