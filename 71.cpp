#include <iostream>

using namespace std;

int main() {
	constexpr int limit = 1000000;
	int fracs[6] = { 3, 7, 2, 5, 0, 0 };
	int *u = &fracs[0], *l = &fracs[2], *m = &fracs[4];
	while (1) {
		int *tmp = l;
		m[0] = u[0] + l[0];
		m[1] = u[1] + l[1];
		if (m[1] > limit) {
			cout << l[0] << endl;
			return 0;
		}
		l = m;
		m = tmp;
	}
	return 0;
}
