#include <iostream>
#include <vector>

using namespace std;

int main() {
	constexpr int limit = 1000000;
	int res = 0;
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

	for (auto &p: pr) {
		bool circular = true;
		string s = to_string(p);
		for (int i = 0; i < s.length() && circular; i++) {
			rotate(begin(s), begin(s) + 1, end(s));

			int rot = stoi(s);
			bool found = false;
			for (auto &p: pr) {
				if (p == rot)
					found = true;
				if (p >= rot)
					break;
			}
			circular = found;
		}
		if (circular)
			res++;
	}

	cout << res << endl;

	return 0;
}
