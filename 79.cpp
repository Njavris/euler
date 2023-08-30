#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int solve(vector<string> &numbers) {
	int ret = 0;
	sort(begin(numbers), end(numbers));
	numbers.erase(unique(begin(numbers), end(numbers)), end(numbers));
	for (auto &iv: numbers) {
		for (auto &jv: numbers) {
			if (iv == jv)
				continue;
			if (iv[iv.size() - 2] == jv[jv.size() - 3] && iv[iv.size() - 1] == jv[jv.size() - 2]) {
				iv.push_back(jv[jv.size() - 1]);
				ret ++;
			}
			for (int i = 0; i < iv.size() - 1; i++) {
				for (int j = 0; j < jv.size() - 2; j++) {
					if (iv[i] == jv[j] && iv[i + 1] == jv[j + 2]) {
						iv.insert(begin(iv) + i + 1, jv[j + 1]);
						ret ++;
					}
				}
			}
		}
	}
	return ret;
}

int main() {
	vector<string> digits, tmp;
	ifstream ifs("0079_keylog.txt");
	string l;
	while (getline(ifs, l))
		digits.push_back(l);
	tmp = digits;

	while (solve(tmp));

	for_each(begin(digits), end(digits), [&tmp] (const auto &dgt) {
		for (auto it = begin(tmp); it != end(tmp);) {
			auto &v = *it;
			bool del = false;
			auto prev = begin(v);
			for (auto &d: dgt) {
				if ((prev = find(prev, end(v), d)) == end(v)) {
					it = tmp.erase(it);
					del = true;
					break;
				}
			}
			if (!del)
				it ++;
		}
	});

	sort(begin(tmp), end(tmp));
	for (auto &d: tmp)
		cout << d << endl;
	return 0;
}
