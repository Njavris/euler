#include <iostream>
#include <vector>

using namespace std;

int main() {
	constexpr int limit = 1000000;
	vector<int> primes;

	primes.push_back(2);
	for (int i = 3; i < limit; i += 2) {
		bool pr = true;
		for (auto &p: primes) {
			if (!(i % p)) {
				pr = false;
				break;
			}
		}
		if (pr)
			primes.push_back(i);
	}

	int best = 0, best_start = 0, best_prime = 0;

	for (int i = 0; i < primes.size(); i++) {
		int sum = 0, len = 0, pr = 0;
		for (int j = i; j < primes.size(); j++) {
			sum += primes[j];
			if (sum >= limit)
				break;
			for (int k = j; k < primes.size(); k++) {
				if (sum == primes[k]) {
					len = j - i;
					pr = k;
					break;
				}
			}
			if (len > best) {
				best = len;
				best_start = i;
				best_prime = pr;
			}
		}
	}
	cout << primes[best_prime] << endl;

	return 0;
}
