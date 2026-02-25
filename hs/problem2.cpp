#include <iostream>
#include <string>

/*
fibs = sum $ filter even $ takeWhile( <= 4000000) fi
    where fi = 0 : 1 : zipWith (+) fi (tail fi)
*/

int main(int argc, char *argv[]) {
	int limit = 10;
	if (argc == 2)
		limit = std::stoi(argv[1]);

	int prev2 = 1;
	int prev1 = 1;
	int sum = 0;

	for (int prev2 = 1, prev1 = 1;;) {
		int curr = prev1 + prev2;
		if (curr >= limit)
			break;
		prev2 = prev1;
		prev1 = curr;
		if (!(curr % 2))
			sum += curr;
	}
	std::cout << sum << std::endl;
	return 0;
}
