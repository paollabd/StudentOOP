#include <cassert>
#include <iostream>
#include <fstream>
#include "../my_code/date.h"
#include "../my_code/weather.h"

using namespace std;

#include <cassert>
#include <iostream>
#include <fstream>
#include "../my_code/weather.h"

using namespace std;

void get_wreadings(string filenm, Weather& w) {
    ifstream rfile(filenm);
    if (!rfile) {
        cout << "Could not read input file: " << filenm << endl;
        exit(1);
    }
    int m, d, y;
    double temp, hum, ws;
    while (rfile >> m >> d >> y >> temp >> hum >> ws) {
        WReading wr = WReading(Date(d, m, y), temp, hum, ws);
        w.add_reading(wr);
    }
    rfile.close();
}


int main() {
    WReading test_temps = WReading(Date(1, 1, 2019), 0, 50, 10);
    double freezingF = test_temps.get_tempF();
    assert(freezingF == 32.0);
    WReading test_temps = WReading(Date(1, 1, 2019), 100, 50, 10);
    double freezingF = test_temps.get_tempF();
    assert(freezingF == 212.0);

    Weather irkutsk = Weather("Irkutsk", GPS(46.3, 67.2));

    string filenm;
    cout << "Input the name of the new readings file:\n";
    cin >> filenm;

    get_wreadings(filenm, irkutsk);

//    cout << irkutsk << endl;
}


/*
string get_input_file() {
	string filenm;

	cout << "Input the name of the new readings file:\n";
	cin >> filenm;
	return filenm;
}

void get_wreadings(Weather& w) {
	// WReading test_temps = WReading(Date(1, 1, 2019), 0, 50, 10);
	// double freezingF = test_temps.get_tempF();
	// assert(freezingF == 32.0);
	// WReading test_temps = WReading(Date(1, 1, 2019), 100, 50, 10);
	// double freezingF = test_temps.get_tempF();
	// assert(freezingF == 212.0);

	string filenm;

	ifstream rfile(get_input_file());
    while (!rfile) { // testing if file stream is broken somehow
        	cout << "Could not read input file. " << endl;
        	rfile.open(get_input_file());
    }
    int m, d, y;
    double temp, hum, ws;
    while (rfile >> m >> d >> y >> temp >> hum >> ws) {
        WReading wr = WReading(Date(d, m, y), temp, hum, ws);
        w.add_reading(wr);
    }
    rfile.close();
}


int main() {
    Weather irkutsk = Weather("Irkutsk", GPS(46.3, 67.2));
 	// string filenm;

	// cout << "Input the name of the new readings file:\n";
	// cin >> filenm;

    get_wreadings(irkutsk);

    cout << irkutsk << endl;
}
*/

/* 
// NOTES:

int main() {
	GPS loc = GPS(46.3, 67.2);
    Weather irkutsk = Weather("Irkutsk", loc);
    // irkutsk.set_rating(2);

	// Getting input form user:
	string filenm;
	cout << "Input the name of the new readings file:\n";
	cin >> filenm;
	// cout << filenm << endl;

	ifstream rfile(filenm);
	if (!rfile) {
		cout << "Could not read input file: " << filenm << endl;
		exit(1);  // exit w/ a non-zero value
	}
	int m, d, y;
	double temp, hum, ws;
	while (rfile >> m >> d >> y >> temp >> hum >> ws) {
		WReading wr = WReading(Date(d, m, y), temp, hum, ws);
		irkutsk.add_reading(wr);
	}
	rfile.close();

	// Date test_date = Date(15, 12, 2019);
	// // this is why we don't put endl at the end when overloading the operator on the weather.cpp file
	// cout << test_date << endl;

	//WReading wr(test_date, 78.2, 43.6, 12.3);
	// or forget/delete Date and use:
	//WReading wr(Date(15, 12, 2019), 78.2, 43.6, 12.3);
	// cout << wr << endl;

    // next line raises exceptions:
    cout << irkutsk << endl; // .get_name() << endl'
    // to fix this we are going to overload the output operator
}

*/

