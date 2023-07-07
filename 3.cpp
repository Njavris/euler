#include <iostream>
#include <cmath>

using namespace std;

int main(int c, char **v) {
	int64_t number = 600851475143;
//	int64_t number = 13195;
	int inc = 1;

	for (int i = 2; i <= sqrt(number); i += inc) {
		while (!(number % i)) {
			number /= i;
			if (i < 5)
				inc *= i;
		}
	}

	cout << number << endl;
	return 0;
}
