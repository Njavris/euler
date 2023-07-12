#include <iostream>

using namespace std;

int main() {
	int s = 0;
	int start = 1901;
	int end = 2001;

	auto ly = [] (int y) -> int {	// Leap year
		return (!(y % 4) &&  ((y % 100) || !(y % 400))) ? 1 : 0;
	};
	auto lotm = [&ly] (int y, int m) -> int { // Length of the month
		return (int []){0, 31, 28 + ly(y), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }[m];
	};
	auto fdoty = [&ly] (int y) -> int { // First day of the year
		int d = 1;
		for (int i = 1900; i < y; d = (d +365 + ly(i++) % 7));
		return d % 7;
	};
	auto fdotm_s = [&lotm, &fdoty] (int y) -> int { // First day of the month is sunday
		int s = 0, d = fdoty(y);
		for (int m = 0; m < 12; m++) {
			if (!(d = (lotm(y, m) + d) % 7))
				s ++;
		}
		return s;
	};
	for (int i = start; i < end; s += fdotm_s(i++));
	cout << s << endl;
	return 0;
}
