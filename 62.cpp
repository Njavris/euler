#include <iostream>
#include <vector>

using namespace std;

class Cube {
	void str_add(string &n1, string &n2) {
		int l2 = n2.length();
		while(l2 > n1.length())
			n1.insert(begin(n1), '0');
		int l1 = n1.length();
		int r = 0, idx = l1 - 1;
		for (int i = 0; i < l1; i++, idx --) {
			if (i >= l2)
				break;
			int d = (n1[idx] - '0') + (n2[l2 - i - 1] - '0') + r;
			r = d / 10;
			d %= 10;
			n1[idx] = d + '0';
		}
		if (r && idx < 0)
			n1.insert(begin(n1), '1');
		else if (r)
			n1[idx] += r;
	};
	void str_mul(string &n1, string &n2, string &ret) {
		ret.clear();
		for (int i = n2.length(), off = 0; i-- > 0; off ++) {
			string tmp;
			int r = 0, d2 = n2[i] - '0';
			for (int j = n1.length(); j-- > 0;) {
				int d1 = n1[j] - '0';
				int d = d1 * d2 + r;
				r = d / 10;
				d %= 10;
				tmp.insert(begin(tmp), d + '0');
			}
			if (r)
				tmp.insert(begin(tmp), r + '0');
			for (int j = 0; j < off; j++)
				tmp.push_back('0');
			if (!off) {
				ret = tmp;
				continue;
			}
			str_add(ret, tmp);
		}
	};
	void str_pow(string num, int pow, string &ret) {
		ret.clear();
		string tmp = num;
		ret = !pow ? "1" : num;
		for (int i = 1; i < pow; i++) {
			str_mul(tmp, num, ret);
			tmp = ret;
		}
	};
public:
	string cube;
	string sorted;
	int base;
	Cube(int b) : base(b) {
		str_pow(to_string(b), 3, cube);
		sorted = cube;
		sort(begin(sorted), end(sorted));
	};
	bool operator< (const Cube &c) const {
		return sorted == c.sorted ? base < c.base : sorted < c.sorted;
	};
};

int main() {
	constexpr int limit = 5;
	vector<Cube> cubes;
	Cube *res = NULL;

	for (int i = 1, len = 1, found = 0; !found; i++) {
		Cube cube(i);
		if (len < cube.cube.length()) {
			sort(begin(cubes), end(cubes));
			string &curr = begin(cubes)->sorted;
			int cnt = 0;
			for (auto c = begin(cubes); c != end(cubes) && !found; c++) {
				cnt = (c->sorted != curr) ? 1 : cnt + 1;
				curr = c->sorted;
				if (cnt == limit) {
					res = &*(c - cnt + 1);
					found = 1;
				}
			}
			cubes.clear();
		}
		len = cube.cube.length();
		cubes.push_back(cube);
	}

	cout << res->cube << endl;
	return 0;
}
