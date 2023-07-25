#include <iostream>
#include <cmath>
#include <map>

using namespace std;

/*
*/

int main() {
	constexpr int limit = 1000;
	map<int,int> pers;
	for (int a = 1; a < limit; a++) {
		int b = a;
		for (; b < limit; b++) {
			int sqr = a * a + b * b;
			int c = sqrt(sqr);
			if (c * c != sqr)
				continue;
			int p = a + b + c;
			if (p > limit)
				break;
			pers[p] ++;
		}
		if (b - 2 == a)
			break;
	}

	int best = 0;
	for (const auto& [k, v] : pers)
		if (v > pers[best])
			best = k;

	cout << best << endl;
	return 0;
}
