#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(int c, char **v) {
	int limit = 2000000;
	uint64_t sum = 0;
	vector<int> primes;
	primes.push_back(2);
	for (int i = 3, isPrime = 1; i < limit; i += 2, isPrime = 1) {
		for (auto &p: primes)
			if (!(isPrime = i % p))
				break;
		if (isPrime) {
			sum += i;
			primes.push_back(i);
		}
	}
	cout << "Sum:" << sum << endl;
	return 0;
}
