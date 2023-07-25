#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	int res = 0;
	auto genPrimes = [&res] (int limit) {
		vector<int> primes;
		primes.push_back(2);
		auto isPandigital = [] (string &s, int limit) -> bool {
			if (s.length() != limit)
				return false;
			for (int i = 1; i <= limit; i++) {
				if (s.find('0' + i) == string::npos)
					return false;
			}
			cout << s << endl;
			return true;
		};

		for (int i = 3; i < limit; i += 2) {
			bool isPr = true;
			for (auto &p: primes) {
				if (!(i % p)) {
					isPr = false;
					break;
				}
			}
			if (isPr) {
				primes.push_back(i);
				string s = to_string(i);
				if (isPandigital(s, s.length()))
					res = i;
			}
		}
	};

	genPrimes(10000000);
	cout << res << endl;
	return 0;
}
