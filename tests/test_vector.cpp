#include <cassert>
#include <iostream>
#include <string>
#include "../my_code/vector.h"

using namespace std;

int copy_vector(vector v)
{
	vector local_v = v;
	return local_v.size();
} // vector local_v is defined in this block, which means it GOES OUT OF SCOPE (and calls the destructor)

int main()
{
 	/*
 	 * Variables
 	*/
 	vector v1 = vector();
 	vector v3;

 	/*
 	 * Inserting 10 items in v1, filling up capacity (prev push_back implementation)
 	*/
 	for (int i = 0; i < 200; i++)
 	{
 		v1.push_back(i);
 		copy_vector(v1); // testing the ~destructor by calling it 200 times
 	}
 	assert(v1[199] == 199);

 	/*
 	 * Doubling values inside vector
 	*/
 	for (int i = 0; i < 200; i++)
 	{
 		v1[i] *= 2;
 	}
 	assert(v1[199] == 398);

 	/*
 	 * Inserting items in v3
 	*/
 	for (int i = 9; i < 100; i += 9) // count by 9 up to 99
 	{
 		v3.push_back(i);
 	}
 	assert(v3[1] == 18);

 	/*
 	 * Output generators
 	*/
    vector v2 = v1;
    print_vector(v2);
    assert(v2 == v1);

    v2 = v3;
    print_vector(v2);
    assert(v2 == v3);

    for (int i : v3) {
        assert((i % 9) == 0);
    }

    vector v4 = vector(10, 20);
    for (int i : v4) {
        assert(i == 20);
    }
}







































// #include <cassert>
// #include <iostream>
// #include "../my_code/vector.h"

//  using namespace std;

// int copy_vector(vector v)
// {
// 	vector local_v = v;
// 	return local_v.size();
// } // vector local_v is defined in this block, which means it GOES OUT OF SCOPE (and calls the destructor)

// int main()
// {
//  	/*
//  	 * Variables
//  	*/
//  	vector v1 = vector();
//  	vector v3;

//  	/*
//  	 * Inserting 10 items in v1, filling up capacity (prev push_back implementation)
//  	*/
//  	for (int i = 0; i < 200; i++)
//  	{
//  		v1.push_back(i);
//  		copy_vector(v1); // testing the ~destructor by calling it 200 times
//  	}
//  	assert(v1[199] == 199);

//  	/*
//  	 * Doubling values inside vector
//  	*/
//  	for (int i = 0; i < 200; i++)
//  	{
//  		v1[i] *= 2;
//  	}
//  	assert(v1[199] == 398);

//  	/*
//  	 * Inserting items in v3
//  	*/
//  	for (int i = 9; i < 100; i += 9) // count by 9 up to 99
//  	{
//  		v3.push_back(i);
//  	}
//  	assert(v3[1] == 18);

//  	/*
//  	 * Output generators
//  	*/
//     vector v2 = v1;
//     print_vector(v2);
//     assert(v2 == v1);

//     v2 = v3;
//     print_vector(v2);
//     assert(v2 == v3);

// }














/*
 * Variables
*/
 	// int* squashed1 = new int;
 	// *squashed1 = 42;
 	// int* squashed2 = new int;
 	// *squashed2 = 99;

/*
 * Reckless for loop:
 * It will let me insert 10000 items, but it's not safe
 * (prev push_back implementation)
*/
 	// for (int i = 0; i < 10000; i++)
 	// {
 	// 	v.push_back(i);
 	// }

/*
 * Output generators
*/
 	// cout << "squashed1 = " << *squashed1 << endl; // output: 12 (using reckless for loop)
 	// cout << "squashed2 = " << *squashed2 << endl; // output: 20 (using reckless for loop)
 	// this happens because we overwrote the memory with the for loop