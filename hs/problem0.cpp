#include <iostream>
#include <string>

/*
sum $ [x * x | x <- [1..858000], x `mod` 2 == 1]
*/

int main(int argc, char* argv[]) {
	int limit = 5;
	unsigned long long sum = 0;

	if (argc == 2)
		limit = std::stoi(argv[1]);

	for (unsigned long int i = 0; i <= limit; i++) {
	    unsigned long long sq = i * i;
	    if (sq % 2) {
		sum += sq;
	    }
	}
	std::cout << sum << std::endl;

	return 0;
}
