#include <cassert>
#include <iostream>
#include "../my_code/weather.h"

using namespace std;

int main() {
    GPS loc = GPS(46.3, 67.2);
    Weather irkutsk = Weather("Irkutsk", loc);
    irkutsk.set_rating(2);
    // next line raises exceptions:
    cout << irkutsk << endl; // .get_name() << endl'
    // to fix this we are going to overload the output operator
}