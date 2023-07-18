#include <iostream>
#include <vector>

using namespace std;

/*
	n*n + a*n + b = n(n + a) + b
	-1000 < a < 1000
	-1000 <= b <= 1000
	a, b - primes

	topmost limits:
	a = b = n:
		n*n + n*n + n = n(2n + 1)
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

	cout << pr.size() << endl;
	int best_n = -1;
	int best = -1;
	int signs[][2] = { { 1, 1 }, { -1, 1 }, { 1, -1 }, { -1, -1 }};
	for (auto &a: pr) {
		if (a >= 1000)
			break;
		for (auto &b: pr) {
			if (b > 1000)
				break;
			for (auto &s: signs) {
				int n = 0;
				while (true) {
					int val = n * (n + s[0] * a) + s[1] * b;
					bool found = 0;
					for (auto &p: pr) {
						if (val < p)
							break;
						if (val == p) {
							found = true;
							break;
						}
					}
					if (!found)
						break;
					n++;
				}
				if (n > best_n) {
					best_n = n;
					best = s[0] * s[1] * a * b;
					cout << s[0] * a << " " << s[1] * b << " " << n << endl;;
				}
			}
		}
	}
	cout << best_n << " " << best << endl;

	return 0;
}
