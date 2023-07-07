#include <iostream>
#include <vector>

using namespace std;

int main(int c, char **v) {
	int number = 1, limit = 20;
	vector<int> primes, primeCnt;

	for (int i = 2, isPrime = 1; i <= limit; i++, isPrime = 1) {
		for (auto &p: primes) {
			if (!(isPrime = i % p))
				break;
		}
		if (isPrime)
			primes.push_back(i);
	}

	primeCnt.resize(primes.size(), 0);
	for (int i = 2, tmp = i; i <= limit; tmp = ++i) {
		for (int i = 0, cnt = 0; i < primes.size(); i++, cnt = 0) {
			while (!(tmp % primes[i])) {
				tmp /= primes[i];
				cnt++;
			}
			if (cnt > primeCnt[i])
				primeCnt[i] = cnt;
		}
	}
	for (int i = 0; i < primes.size(); i++)
		for (int j = 0; j < primeCnt[i]; j++)
			number *= primes[i];

	std::cout << number << endl;
	return 0;
}
