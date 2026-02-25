#include <iostream>
#include <string>

/*
isPaly = (((==) <*> reverse) . show)
paly lim = maximum $ [ a * b | a <- [1..lim], b <- [1..lim], isPaly (a * b)]
*/

int main() {
	int len = 3;
	int limit = 1;
	for (int i = 0; i < len; i++, limit *= 10);
	limit -= 1;


	int best = 0;
	for (int i = limit; i > 0; i--) {
		for (int j = limit; j > 0; j--) {
			int num = i * j;
			if (num < best)
				break;

			std::string s = std::to_string(num);
			if (s.size() < len * 2)
				continue;

			bool plyn = true;
			for (int k = 0; k < s.size() / 2; k++) {
				if (s[k] != s[s.size() - 1 - k]) {
				    	plyn = false;
					break;
				}
			}

			if (!plyn)
				continue;

			if (num > best)
				best = num;
		}
	}
	std::cout << best << std::endl;

	return 0;
}
