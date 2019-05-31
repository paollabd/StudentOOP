#include <cassert>
#include <iostream>
#include <string>
#include <vector>
#include "../my_code/basics.h"

using namespace std;

int main() {

    say("Hello!");

    // PASS COPY
    int j = 8;
    inc_pass_copy(j);
    cout << "j = " << j << endl;

    // PASS REFERENCE
    inc_pass_ref(j);
    cout << "j = " << j << endl;
    // Put this assertion back once you've written code:
    // assert(j == 9);

    // INT SQUARE
    int test_num = 10;
    int ret = square(test_num);
    assert(ret == (test_num * test_num));

    // DOUBLE SQUARE
    double test_dbl = 2.5;
    double dret = square(test_dbl);
    cout << "2.5 squared = " << dret << endl;
    assert(dret == (test_dbl * test_dbl));
    cout << "Int value of dret = " << (int)dret << endl;

    // ABSOLUTE VAL
    ret = my_abs(test_num);
    assert(ret == test_num);
    ret = 77;
    ret = my_abs(-test_num);
    assert(ret == test_num);

    // SUM 1
    ret = sum(test_num);
    assert(ret == 45);

    // SUM 2
    ret = sum2(test_num);
    assert(ret == 45);

    // FILL VECTOR
    vector<int> v = { 0 };
    fill_vector(v, test_num);
    // PRINT VECTOR
    print_vector(v);
    cout << "v[1] = " << v[1] << endl;

    // COORDINATES
    coord pos;
    pos.x = 7;
    pos.y = 8;
    print_coords(pos);

    // PULL STRING APART
    char c = 'A';
    string s = "C++ strings are collections of chars.";
    s += '!';
    pull_apart_string(s);
    assert(c < s[4]);
    c++;
    cout << "c = " << c << endl;
    cout << "Int val of c = " << (int)c << endl;

    // SAY
    say("Goodbye!");
    return 0;
}