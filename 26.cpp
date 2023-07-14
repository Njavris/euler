#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;




int main() {
	constexpr int limit = 1000;
	constexpr int prec = 10 * limit;
	int best_n = 0, best_len = -1;
	vector<int> pr;
	pr.push_back(2);
	for (int i = 3; i < limit; i += 2) {
		int n_pr = 0;
		for (auto &p: pr) {
			if (!(i % p)) {
				n_pr = 1;
				break;
			}
		}
		if (!n_pr)
			pr.push_back(i);
	}
	pr.erase(find(begin(pr), end(pr), 2));
	pr.erase(find(begin(pr), end(pr), 5));

	auto rep = [] (string num) -> int{
		int len = num.length();
		for (int i = 0; i < len; i++) {
			string c = num.substr(i, len - i);
			int it1 = 0, it2 = 0, d = 0, l = c.length();
			while ((d = c.find(c[0], d + 1)) != string::npos) {
				string s1 = c.substr(0, d);
				string s2 = c.substr(d, d);
				if (s1.length() && s1 == s2 && d > l / 3) {
					if (!it1 && !it2)
						it1 = s1.length();
					else if (!it2)
						it2 = s1.length();
					else
						break;
				}
			}
			if (it1 && it2)
				return it2 - it1;
		}
		return -1;
	};
	auto fract = [&rep] (int n, int prec) -> int {
		string o;
		int r = 1;
		for (int i = 0; i < prec; i++) {
			r *= 10;
			int v = r / n;
			r %= n;
			o.push_back('0' + v);
		}
		return rep(o);
	};

	for (int i = 3; i < limit; i++) {
		for (auto &p: pr) {
			if (!(i % p)) {
				int r = fract(i, prec);
				if (r > best_len) {
					best_len = r;
					best_n = i;
				}
			}
		}
	}
	cout << best_n << endl;

	return 0;
}
