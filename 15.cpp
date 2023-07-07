#include <iostream>

using namespace std;


/*
	P = (n * n)! / (n! * n!)
*/

int fact(int i) { return i * ((i == 1) ? 1 : fact(i - 1)); }

int main(int c, char **v) {
	int limit = 2;
	int res = fact(limit * limit);
	res /= fact(limit)*fact(limit);

	cout << res << endl;

	return 0;
}
