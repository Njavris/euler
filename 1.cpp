#include <iostream>

using namespace std;

int main(int c, char **v) {
	int sum = 0;
	int limit = 1000;
	for (int i = 1; i < limit; i++) {
		if (!(i % 3) || !(i % 5))
			sum += i;
	}

	cout << sum << endl;
	return 0;
}
