#include <iostream>

using namespace std;

int main(int c, char **v) {
	int sum = 0;
	int limit = 4000000;

	for (int i = 1, prev = 1, tmp = i; i < limit; tmp = i, i += prev, prev = tmp)
		if (!(i % 2))
			sum += i;
	cout << sum << endl;

	return 0;
}
