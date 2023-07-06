#include <stdio.h>

#define HISIL 26

int main(void) {
	int histogram[HISIL];
	int c, i, j;

	for (i = 0; i < HISIL; ++i)
		histogram[i] = 0;

	while ((c = getchar()) != EOF) {
		if (c >= 'a' && c <= 'z') {
			histogram[c - 'a']++;
		}
	}

	for (i = 0; i < HISIL; ++i) {
		printf("%c: ", 'a' + i);
		for (j = 0; j < histogram[i]; ++j) {
			putchar('#');
		}
		putchar('\n');
	}
    return 0;
}