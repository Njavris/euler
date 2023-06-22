#include <stdio.h>
#include <string.h>

int main() {
	int sz = 1, res = 0, fact[200] = { 1 };
	for (int i = 1, c = 0; i < 100; i++) {
		for (int j = 0, t = fact[0] * i + c; j < sz; t = fact[++j] * i + c) {
			fact[j] = t % 10;
			c = t / 10;
		}
		for (; (fact[sz] = c % 10) || c; sz++ && (c /= 10));
	}
	for (int i = 0; i < sz; i++) {
		char tmp[32];
		sprintf(tmp, "%d", fact[i]);
		for (int j = 0; j < strlen(tmp); j++)
			res += tmp[j] - '0';
	}
	printf("answer = %d\n", res);
	return 0;
}
