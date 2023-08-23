#include <iostream>
#include <vector>

using namespace std;

int main() {
	constexpr int limit = 1000000;
	vector<int> primes;

	primes.push_back(2);
	for (int i = 3; i < limit; i += 2) {
		bool prime = true;
		for (int n = 3; prime && n * n <= i; prime = ( i % n), n += 2);
		if (prime)
			primes.push_back(i);
	}

	int64_t num_els = 2;
	for (int i = 2; i <= limit; i++) {
		int n = i, phi = i;
		for (int j = 0; n >= primes[j] * primes[j]; j++)
			if (!(n % primes[j]))
				for (phi -= phi / primes[j]; !(n % primes[j]); n /= primes[j]);
		if (n > 1)
			phi -= phi / n;
		num_els += phi;

	}
	cout << num_els - 2 << endl;

	return 0;
}
