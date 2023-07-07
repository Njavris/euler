#include <iostream>

using namespace std;

int main(int c, char **v) {
	int limit = 100;
	int sqSum = 0, sum = 0;
	for (int i = 1; i <= limit; sum += i, sqSum += i * i, i++);

	cout << sum * sum - sqSum << endl;
	return 0;
}
