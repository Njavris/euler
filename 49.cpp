#include <iostream>
#include <vector>

using namespace std;

int main() {
	constexpr int limit = 4;
	vector<int> primes, suspects;

	primes.push_back(2);
	for (int i = 3; i < 10000; i += 2) {
		bool pr = true;
		for (auto &p: primes) {
			if (!(i % p)) {
				pr = false;
				break;
			}
		}
		if (pr) {
			primes.push_back(i);
			if (i > 1000)
				suspects.push_back(i);
		}
	}

	auto is_perm = [] (int a, int b, int c) -> bool {
		string sa = to_string(a);
		string sb = to_string(b);
		string sc = to_string(c);
		if (sa.length() != sb.length() || sb.length() != sc.length())
			return false;

		while (char c = sa[0]) {
			auto pos = sa.find(c);
			if (pos == string::npos)
				return false;
			sa.erase(pos, 1);
			pos = sb.find(c);
			if (pos == string::npos)
				return false;
			sb.erase(pos, 1);
			pos = sc.find(c);
			if (pos == string::npos)
				return false;
			sc.erase(pos, 1);
		}
		if (!sa.length() && !sb.length() && !sc.length())
			return true;
		return false;
	};

	for (int i = 0; i < suspects.size(); i ++) {
		int a = suspects[i];
		for (int j = i + 1; j < suspects.size(); j++) {
			int b = suspects[j];
			int dab = b - a;
			for (int k = j + 1; k < suspects.size(); k++) {
				int c = suspects[k];
				int dbc = c - b;
				if (dab != dbc)
					continue;
				if (is_perm(a, b, c)) {
					cout << "\"" << a << "\" + \" " << b;
					cout << "\" + \" " << c << "\" = \"";
					cout << a << b << c << "\"" <<endl;
				}
			}
		}
	}

	return 0;
}
