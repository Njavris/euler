#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <math.h>

int g_max_num = 0;
float g_max_tot = 0;

void sig_handler(int sig) {
	char c;
	signal(sig, SIG_IGN);
	printf("curr_max_num: %d %lf\n", g_max_num, g_max_tot);
	printf("What to do?\n"
		"\te - exit\n"
		"\tany key - continue\n"
		"Your choice:");

	c = getchar();
	if (c == 'e')
		exit(0);
	while ((c = getchar()) != '\n' && c != EOF);
	signal(SIGINT, sig_handler);
	printf("continuing\n");
}

int gen_primes(int limit, int **primes) {
	int p_cnt;
	int max_cnt = sqrt(limit);
	*primes = (int *)malloc(max_cnt * sizeof(int));
	(*primes)[0] = 2;
	(*primes)[1] = 3;

	for (int i = 3, p_cnt = 2; p_cnt < max_cnt; i += 2) {
		int pr = 0, f = 0;
		for (int j = 0; j < p_cnt; j++) {
			pr = !(i % (*primes)[j]);
			if (pr)
				break;
		}
		if (!pr)
			(*primes)[p_cnt++] = i;
	}
	return p_cnt;
}

int phi_cnt(int n, int *primes, int p_cnt) {
	int r = n;
	for (int i = 0; n >= primes[i] * primes[i]; i++)
		if (!(n % primes[i]))
			for (r -= r / primes[i]; !(n % primes[i]); n /= primes[i]);
	if (n > 1)
		r -= r / n;
	return r;
}

int main() {
	signal(SIGINT, sig_handler);

	int limit = 1000000, *primes, p_cnt = gen_primes(limit, &primes);

	if (!primes)
		return -1;

	for (int i = 1; i <= limit; i++) {
		int phi = phi_cnt(i, primes, p_cnt);
		float tot = (float)i / phi;
//		if (!(i % (limit / 100)))
//			printf("%d%% curr_max:\ttot:%f num:%d\n", (i * 100 / limit), g_max_tot, g_max_num);
		if (tot > g_max_tot) {
			g_max_tot = tot;
			g_max_num = i;
		}
	}

	printf("best: %d %f\n", g_max_num, g_max_tot);

	free(primes);
	return 0;
}
