#include <stdio.h>
#include <string.h>

enum {
	e_1,
	e_2,
	e_3,
	e_4,
	e_5,
	e_6,
	e_7,
	e_8,
	e_9,
	e_10,
	e_11,
	e_12,
	e_13,
	e_14,
	e_15,
	e_16,
	e_17,
	e_18,
	e_19,
	e_20,
	e_30,
	e_40,
	e_50,
	e_60,
	e_70,
	e_80,
	e_90,
	e_100,
	e_1000,
	e_and,
};

char *names[] = {
	[e_1] = "one",
	[e_2] = "two",
	[e_3] = "three",
	[e_4] = "four",
	[e_5] = "five",
	[e_6] = "six",
	[e_7] = "seven",
	[e_8] = "eight",
	[e_9] = "nine",
	[e_10] = "ten",
	[e_11] = "eleven",
	[e_12] = "twelve",
	[e_13] = "thirteen",
	[e_14] = "fourteen",
	[e_15] = "fifteen",
	[e_16] = "sixteen",
	[e_17] = "seventeen",
	[e_18] = "eighteen",
	[e_19] = "nineteen",
	[e_20] = "twenty",
	[e_30] = "thirty",
	[e_40] = "forty",
	[e_50] = "fifty",
	[e_60] = "sixty",
	[e_70] = "seventy",
	[e_80] = "eighty",
	[e_90] = "ninety",
	[e_100] = "hundred",
	[e_1000] = "thousand",
	[e_and] = "and",
};

int num_to_str(int num) {
	int ret = 0;
	int thousands = num / 1000;
	int hundreds = (num % 1000) / 100;
	int tens = (num % 100) / 10;
	int ones = (num % 10);
	if (thousands)
		ret += strlen(names[e_1 + thousands - 1]) + strlen(names[e_1000]);
	if (hundreds)
		ret += strlen(names[e_1 + hundreds - 1]) + strlen(names[e_100]);
	if ((thousands || hundreds) && (tens || ones))
		ret += strlen(names[e_and]);
	if (tens && tens < 2)
		ret += strlen(names[e_1 + (num % 20) - 1]);
	else if (tens)
		ret += strlen(names[e_20 + tens - 2]);
	if (ones && (!tens || tens > 1))
		ret += strlen(names[e_1 + ones - 1]);
	return ret;
}

int main() {
	int sum = 0;
	for (int i = 1; i <= 1000; i++)
		sum += num_to_str(i);
	printf("total: %d\n", sum);
	return 0;
}
