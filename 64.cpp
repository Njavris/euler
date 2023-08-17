#include <iostream>
#include <vector>

using namespace std;

int main() {
	constexpr int limit = 10000;
	int res = 0;

	int closest = 1;
	int next = (closest + 1) * (closest + 1);
	for (int i = 2; i <= limit; i++) {
		if (next == i) { // To avoid sqrt
			closest ++;
			next = (closest + 1) * (closest + 1);
		}
		if (closest * closest == i)
			continue;
		vector<int> as, ms, ds;
		for (int d = 1, m = 0, a = closest;;) {
			m = d * a - m;
			d = (i - m * m) / d;
			a = (closest + m) / d;
			ms.push_back(m);
			ds.push_back(d);
			as.push_back(a);
			if (!(as.size() % 2)) {
				int off = as.size() / 2;
				int found = true;
				for (int j = 0; found && j < off;
					found = !(as[j] != as[off + j] ||
					ms[j] != ms[off + j] ||
					ds[j] != ds[off + j]),
					j++);
				if (found) {
					res += off % 2;
					break;
				}
			}
		}
	}
	cout << res << endl;
	return 0;
}
