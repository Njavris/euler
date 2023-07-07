#include <iostream>
#include <string>

using namespace std;

int main(int c, char **v) {
	auto isPalindrome = [] (int n) -> bool {
		string tmp = to_string(n);
		for (int i = 0; i < tmp.size(); i++)
			if (tmp[i] != tmp[tmp.size() - i - 1])
				return false;
		return true;
	};

	int best = 0;
	for (int i = 100; i < 1000; i++)
		for (int j = i; j < 1000; j++)
			if (isPalindrome(i * j) && i * j > best)
				best = i * j;
	std::cout << best << endl;

	return 0;
}
