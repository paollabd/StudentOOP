#include <iostream>

using namespace std;

void f(int i)
{
	cout << i << endl;
	f(i + 1);
}

int main()
{
	f(0);
}