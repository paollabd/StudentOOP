#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

/*
 * CAPACITY:
 * Our capcacity is generally going to be larger than our size.
 * We don't want to keep allocating memory all the time - only when necessary - when it's full.
 *
 * CONST:
 * Helps with debugging. Compiler blocks us form changing the objects inside the const function.
*/


const int DEF_CAPACITY = 10;
const int CAPACITY_MULT = 2;

// template <typename T>
class vector {
    public:
        class Iterator { 
        /*
         * This class supports ranged for loops.
         * It includes:
         * Iterator(int*)
         * operator++
         * operator*
         * operator!=
         * */
            friend bool operator!=(Iterator& rhs, Iterator& lhs) {
                return rhs.iptr != lhs.iptr;
            }

        public:
            Iterator(int* ip) : iptr(ip) {}

            Iterator& operator++() {
            	iptr++; // moving pointer up a few bytes to point to the next data
                return *this;
            }

            int operator*() { return *iptr; }

        private:
            int* iptr;
    };

        vector();
        vector(int sz, int val=0);

        // copy control:
        vector(const vector& v2);
        ~vector();
        vector& operator=(const vector& v2);

        void push_back(int val);
        int size() const { return sz; }
        int operator[](int i) const;
        int& operator[](int i);
        Iterator begin() const;
        Iterator end() const;

    private:
        int* data;
        int sz;
        int capacity;
        void copy_fields(const vector& v2);
};


void print_vector(const vector& v);

bool operator==(vector& v1, vector& v2);

#endif





















// const int DEF_CAPACITY = 10; // initial capacity

// class vector
// {
//  private:
//  	int* data;
//  	int sz;
//  	int capacity;
//  	void copy_fields(const vector& v2);
//  public:
//  	class Iterator
//  	{
//  		friend bool operator!=(Iterator& rhs, Iterator& lhs) 
//  		{
//  			return rhs.iptr != lhs.iptr;
//  		}

//  		// friend bool operator==(Iterator& rhs, Iterator& lhs) 
//  		// {
//  		// 	return rhs.iptr == lhs.iptr;
//  		// }
//  	 public:
//  		Iterator(int* ip) : iptr(ip) {}
//  		Iterator& operator++()
//  		{
//  			iptr++;
//  			return *this;
//  		}
//  		int operator*() { return *iptr; }
//  	 private:

//  	}

//  	vector(); //default constructor

//  	// COPY CONSTRUCTOR
//  	vector(const vector& v2);
//  	// DESTRUCTOR
//  	~vector();
//  	// ASSIGNMENT OPERATOR
//  	vector& operator=(const vector& v2);

//  	void push_back(int val);
//  	int size() const { return sz; } // compiler will inline this, so we won't have the cost of a function call
//  	int operator[](int i) const; // Used to access the element 
//  	// We can't set using this because we are returning a copy.
//  	// We can change the copy but that won't change the original)
//  	// We need a const method for when we are not going to change things
//  	int& operator[](int i); // set the element
//  	Iterator begin() const;
//  	Iterator end() const;
// };

// void print_vector(const vector v);

// bool operator==(vector& v1, vector& v2);

// #endif








































// #ifndef VECTOR_H
// #define VECTOR_H

// #include <iostream>

// /*
//  * CAPACITY:
//  * Our capcacity is generally going to be larger than our size.
//  * We don't want to keep allocating memory all the time - only when necessary - when it's full.
//  *
//  * CONST:
//  * Helps with debugging. Compiler blocks us form changing the objects inside the const function.
// */

// const int DEF_CAPACITY = 10; // initial capacity

// class vector
// {
//  private:
//  	int* data;
//  	int sz;
//  	int capacity;
//  	void copy_fields(const vector& v2);
//  public:
//  	vector(); //default constructor

//  	// COPY CONSTRUCTOR
//  	vector(const vector& v2);
//  	// DESTRUCTOR
//  	~vector();
//  	// ASSIGNMENT OPERATOR
//  	vector& operator=(const vector& v2);

//  	void push_back(int val);
//  	int size() const { return sz; } // compiler will inline this, so we won't have the cost of a function call
//  	int operator[](int i) const; // Used to access the element 
//  	// We can't set using this because we are returning a copy.
//  	// We can change the copy but that won't change the original)
//  	// We need a const method for when we are not going to change things
//  	int& operator[](int i); // set the element
// };

// void print_vector(const vector v);

// bool operator==(vector& v1, vector& v2);

// #endif