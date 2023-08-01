#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	constexpr int limit = 6;
	int res;

	auto test = [&limit] (int n) -> bool {
		int t = n, cn = 0;
		vector<int> nv;
		for (; t; t /= 10, cn++);
		for (t = n; t; t /= 10)
			nv.push_back(t % 10);
		sort(begin(nv), end(nv));
		for (int m = 2; m <= limit; m++) {
			int cnm = 0, nm = m * n;
			vector<int> nmv;

			for (t = nm; t; t /= 10, cnm++);
			if (cnm != cn)
				return false;

			for (; nm; nm /= 10)
				nmv.push_back(nm % 10);
			sort(begin(nmv), end(nmv));
			if (nv != nmv)
				return false;
		}
		return true;
	};

	for (res = 1; !test(res); res++);

	cout << res << endl;
	return 0;
}
