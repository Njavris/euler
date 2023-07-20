#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int with_class(int start, int limit) {
class term {
public:
	int base;
	int power;
	term() : base(0), power(1) {};
	bool operator== (const term &their) {
		return their.base == base && their.power == power;
	};
};
	vector<int> integers, pows, bases;
	vector<term> terms, res;

	for (int i = start; i <= limit; i++) {
		for (int j = start; ; j++) {
			int v = pow(i, j);
			if (v > limit)
				break;
			if (find(begin(integers), end(integers), v) == end(integers)) {
				integers.push_back(v);
				pows.push_back(j);
				bases.push_back(i);
			}
		}
	}

	for (int i = start; i <= limit; i++) {
		term f;
		for (auto it = begin(integers); it != end(integers); it++) {
			if (*it == i) {
				int ii = distance(begin(integers), it);
				f.base = bases[ii];
				f.power = pows[ii];
			}
		}
		if (f.base == 0)
			f.base = i;
		for (int j = start; j <= limit; j++) {
			term t = f;
			t.power *= j;
			terms.push_back(t);
		}
	}
	for_each(begin(terms), end(terms), [&res](auto t) {
		if (find(begin(res), end(res), t) == end(res))
			res.push_back(t);
	});
	return res.size();
}

int analytically(int start, int limit) {
	vector<int> integers;
	int cnt = limit - (start - 1);
	int ret = cnt * cnt;
	int coef[5];
	coef[0] = 1;
	/*
		k^i = l^(2 * i) 	i = 2..50 => cnt / 2
	*/
	coef[1] = cnt / 2.0;
	/*
		k^i = l^(3 * i) = m^((3 / 2) * i)
		i = 2..33 				=> cnt / 3
		3/2 * i <= cnt				=> i <= cnt * 2 / 3
		3/2 * i > cnt / 2	i > cnt / 3	=> i >= (cnt + 1) / 3
		i = 34 .. 66				=> cnt / 3 ... 2 * cnt / 3
`		i += 2 =>  (cnt * 2 / 3 - cnt / 3 + 1/3) / 2	=> cnt / 6 + 1/6
		cnt / 3 + cnt / 6 + 1/6 = cnt / 2;
	*/
	coef[2] = cnt / 2.0 + 1/6.0;
	/*
		k^i = l^(4 * i) = m^(2 * i) = n^((4 / 3) * i)
		2i = 2..50 includes 4i = 2..20		=> cnt / 2
		4/3 * i <= cnt				=> i <= 3/4 * cnt
		4/3 * i > cnt / 2			=> i >= (cnt + 1) / 2 overlaps 2i
		i += 3 => ((3/4 - 1/2) * cnt + 1/4) / 3 = 1/12 * cnt + 1/4
		cnt/2 + cnt/12 + 1/4
	*/
	coef[3] = cnt / 2.0 + cnt / 12.0 + 1/4.0;
	/*
		k^i = l^5i = m^5i/2 = n^5i/3 = n^5i/4
		5i <= cnt				=> cnt / 5
		5/2 * i <= cnt				=> i <= 2 * cnt / 5
		overlaps 5i
		i += 2 => (2/5 * cnt - (cnt + 1) /5) / 2 = 1/10 * cnt - 1/10
		5/3 *i <= cnt				=> i <= 3/5 * cnt
		overlaps 5/i
		i += 6 => (3/5 * cnt - (cnt + 1)/5)/6 = 2/30*cnt - 1/30
		5/4 * i <= cnt				=> i <= 4 * cnt / 5
		too much overlaping...
		cnt/5 + cnt/10 - 1/10 + 2*cnt / 30 - 1/30 + ... == 48 for i = 2..100
	*/
	coef[4] = 48;
	coef[5] = 62;

	for (int i = start; i <= limit; i++) {
		for (int j = start; ; j++) {
			int v = pow(i, j);
			if (v > limit)
				break;
			if (find(begin(integers), end(integers), v) == end(integers)) {
				integers.push_back(v);
				ret -= coef[j - 1];
			}
		}
	}
	return ret;
}

int main() {
	constexpr int limit = 100;
	constexpr int start = 2;

	cout << "removing duplicates: " << with_class(start, limit) << endl;
	cout << "analytically: " << analytically(start, limit) << endl;
	return 0;
}
