#include <iostream>
#include <cmath>

using namespace std;

/*
Tn=n(n + 1)/2
Pn=n(3n - 1)/2
Hn=n(2n - 1)

i(i + 1)/2 = j(3j - 1)/2
=> k = (j + 1) / 2;
i(i + 1)/2 = k(2k - 1)
=> j = (1 + sqrt(12*i*i + 12*i + 1)) / 6
*/

int main() {
	for (int i = 2, found = 0; found < 2 ; i++) {
		double k = (i + 1) / 2.0;
		double j = (1.0 + sqrt(12.0 * i * i + 12.0 * i + 1.0)) / 6.0;
		if ((int)k != k || (int)j != j)
			continue;
		if (found > 0) {
			uint64_t Ti = i / 2 * (i + 1);
			uint64_t Pj = j * (3 * j - 1) / 2;
			uint64_t Hk = k * (2 *k - 1);
			cout << "i=" << i << " j=" << j << " k=" << k << endl;
			cout << "T" << i << "=" << Ti << endl;
			cout << "P" << j << "=" << Pj << endl;
			cout << "H" << k << "=" << Hk << endl;
		}
		found ++;
	}
	return 0;
}
