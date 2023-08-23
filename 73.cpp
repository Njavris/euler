#include <iostream>

int fracts(int l[2], int u[2], int limit) {
	int m[] = { u[0] + l[0], u[1] + l[1]};
	return (m[1] > limit) ? 0 : fracts(l, m, limit) + fracts(m, u, limit) + 1;
}

int main() {
	constexpr int limit = 12000;
	int fracs[][2] = {{1, 3}, {1, 2}};
	std::cout << fracts(fracs[0], fracs[1], limit) << std::endl;
	return 0;
}
