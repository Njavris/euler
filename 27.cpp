#include <iostream>
#include <vector>

using namespace std;

/*
	n*n + a*n + b = n(n + a) + b
	-1000 < a < 1000
	-1000 <= b <= 1000
	a, b - primes

	edgecases:
	n = 0:
		p = b => b - prime and b >= 2;
*/

int main() {
	vector<int> pr;
	pr.push_back(2);
	int limit = 1000;
	for (int i = 3; pr.size() < limit; i += 2) {
		int n_pr = 0;
		for (auto &p: pr) {
			if (!(i % p)) {
				n_pr = 1;
				break;
			}
		}
		if (!n_pr)
			pr.push_back(i);
	}

	int best_n = -1;
	int best = -1;
	int signs[] = { 1, -1 };
	for (int a = 0; a < 1000; a++) {
		for (auto &b: pr) {
			if (b > 1000)
				break;
			for (auto &s: signs) {
				int n = 0;
				while (true) {
					int val = n * (n + s * a) + b;
					bool found = 0;
					for (auto &p: pr) {
						if ((found = (val == p)) || (val < p))
							break;
					}
					if (!found)
						break;
					n++;
				}
				if (n > best_n) {
					best_n = n;
					best = s * a * b;
				}
			}
		}
	}
	cout << best << endl;

	return 0;
}
