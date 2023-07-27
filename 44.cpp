#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

/*
Pn = n * (3 * n - 1) / 2
n = (1 +- sqrt(24 * Pn + 1) / 6
*/

int main() {
	vector<int> pents;
	int res = -1;
	auto isPent = [&pents] (int num) -> bool {
		double n = (1.0 + sqrt(24.0 * num + 1.0)) / 6.0;
		if ((int)n == n)
			return true;
		return false;
	};

	for (int j = 0, found = 0; !found; j++) {
		int pj = j * (3 * j - 1) / 2;
		pents.push_back(pj);
		for (int k = 1; k < j && !found; k++) {
			int pk = pents[k];
			int sum = pj + pk;
			int diff = pj - pk;
			diff *= diff < 0 ? -1 : 1;
			if (isPent(sum) && isPent(diff)) {
				res = diff;
				cout << pj << " " << pk << " ";
				cout << j << " " << k << " " << sum << " " << diff << endl;
				found++;
			}
		}
	}
	cout << res << endl;
	return 0;
}
