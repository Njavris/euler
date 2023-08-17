#include <iostream>
#include <vector>

using namespace std;

int main() {
	constexpr int limit = 10000000;
	vector<int> primes;

	primes.push_back(2);
	for (int i = 3; i < limit; i += 2) {
		bool prime = true;
		for (int n = 3; prime && n * n <= i; prime = ( i % n), n += 2);
		if (prime)
			primes.push_back(i);
	}

	int min_val = 0;
	float min = 0;
	for (int i = 3; i <= limit; i++) {
		int n = i, phi = i;
		for (int j = 0; n >= primes[j] * primes[j]; j++)
			if (!(n % primes[j]))
				for (phi -= phi / primes[j]; !(n % primes[j]); n /= primes[j]);
		if (n > 1)
			phi -= phi / n;
		float tot = (float)i / phi;
		if (min && tot > min)
			continue;

		string num = to_string(i);
		string p = to_string(phi);
		if (num.length() != p.length())
			continue;

		sort(begin(num), end(num));
		sort(begin(p), end(p));
		if (p != num)
			continue;

		if (!min || tot < min) {
			min = tot;
			min_val = i;
		}
	}

	cout << min << " " << min_val << endl;

	return 0;
}
