#include <stdio.h>

int main(int argc, char **argv) {
	FILE *f;
	if (argc < 2)
		return -1;

	f = fopen(argv[1], "r");
	int r = 0, cnt = 0;
	while (r != EOF) {
		int a_x, a_y, b_x, b_y, c_x, c_y;
		if (fscanf(f, "%d,%d,%d,%d,%d,%d\n",
				&a_x, &a_y, &b_x, &b_y, &c_x, &c_y) == EOF)
			break;
		float area = (b_y - c_y) * (a_x - c_x) + (c_x - b_x) * (a_y - c_y);
		float a = (- c_x * (b_y - c_y) - c_y * (c_x - b_x)) / area;
		float b = (- c_x * (c_y - a_y) - c_y * (a_x - c_x)) / area;
		float c = 1 - a - b;
		if (a >= 0 && b >= 0 && c>= 0)
			cnt ++;
	}
	fclose(f);

	printf("count: %d\n", cnt);
	return 0;
}
