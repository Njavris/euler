#include <iostream>
#include <vector>

using namespace std;

/*
	9! = 362880	6 digits
	7*9! = 2540160	7 digits
	8*9! = 2903040	7 digits
	-> probably less than 8 digits
*/

#define LIMIT	8

void solve(int *fs, int fs_sz, char *curr, int &ret, int depth = LIMIT) {
	if (!depth) {
		int v = atoi(curr);
		if (v < 3)
			return;

		int sum = 0;
		for (int i = 0, s = 0; i < LIMIT; i++) {
			int c = curr[i] - '0';
			if (!s && c)
				s = !s;
			if (!s)
				continue;
			sum += fs[c];
	}
		if (sum == v)
			ret += sum;
		return;
	}
	for (int i = 0; i < fs_sz; i++) {
		curr[LIMIT - depth] = i + '0';
		solve(fs, fs_sz, curr, ret, depth - 1);
	}
}

int main() {
	int fac[10];
	for (int i = 0, f = 1; i <= 9; f *= ++i)
		fac[i] = f;

	char c[LIMIT];
	int ret = 0;
	solve(fac, sizeof(fac)/sizeof(fac[0]), c, ret);

	cout << ret << endl;

	return 0;
}
