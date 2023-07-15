#include <stdio.h>

#define NTAB 8

int main(void) {
	int c, i;
	int cur;

	cur = 0;

	while ((c = getchar()) != EOF) {
		if (c == '\t') {
			for (i = NTAB - cur; i > 0; --i)
				putchar(' ');

			cur = 0;
		} else {
			putchar(c);
			cur++;
			if (cur > NTAB)
				cur = 0;
		}
	}
}
