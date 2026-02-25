#include <iostream>
#include <string>

/*
sum [x | x <- [1..999], x `mod` 3 == 0 || x `mod` 5 == 0]
*/

int main(int argc, char **argv) {
	int limit = 10;
	int sum = 0;

	if (argc == 2)
		limit = std::stoi(argv[1]);

	for (int i = 1; i * 3 < limit; i++) {
		int mul3 = i * 3;
		int mul5 = i * 5;
		sum += mul3;
		if (mul5 < limit && mul5 % 3)
			sum += mul5;
	}
	std::cout << sum << std::endl;

	return 0;
}
