#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
	vector<int> res;
	string set;
	for (int i = 1; i <= 9; set.push_back('0' + i++));

	do {
		/*
			A * B = C
			A: 1 and 2 digits;
			B: 3 and 4 digits;
			C: rest.
		*/
		for (int i = 1; i < 3; i++) {
			int a = stoi(set.substr(0, i));
			for (int j = i + 3; j < i + 5; j++) {
				int b = stoi(set.substr(i, j - i));
				int c = stoi(set.substr(j));
				if (a * b == c)
					res.push_back(c);
			}
		}
	} while (next_permutation(begin(set), end(set)));

	sort(begin(res), end(res));
	res.erase(unique(begin(res), end(res)), end(res));

	cout << accumulate(begin(res), end(res), 0)  << endl;
	return 0;
}
