#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	auto genPrimes = [] (vector<int> &res, int limit) {
		vector<int> primes;
		auto isPrime = [&primes] (int num) -> bool {
			for (int i = 0; i < primes.size() && primes[i] <= num; i++) {
				if (primes[i] == num)
					return true;
				if (!(num % primes[i]))
					return false;
			}
			return false;
		};
		auto isTruncPrime = [&primes, isPrime] (int num) -> bool {
			string str = to_string(num);
			for (int i = 1; i < str.length(); i++) {
				string l = str.substr(0, str.length() - i);
				string r = str.substr(i);
				if (!isPrime(stoi(l)) || !isPrime(stoi(r)))
					return false;
			}
			return true;
		};

		primes.push_back(2);

		for (int i = 3; res.size() < limit; i += 2) {
			bool isPr = true;
			for (auto &p: primes) {
				if (!(i % p)) {
					isPr = false;
					break;
				}
			}
			if (isPr) {
				primes.push_back(i);
				if (isTruncPrime(i) && i > 10)
					res.push_back(i);
			}
		}
	};

	vector<int> truncble;
	constexpr int limit = 11;
	int sum = 0;

	genPrimes(truncble, limit);

	for (auto &t: truncble)
		sum += t;
	cout << sum << endl;

	return 0;
}
