#include <stdio.h>

#define MAXLINE 1024

int myGetlineV(char line[], int maxline);

int main(void)
{
	int len;
	char line[MAXLINE];

	while ((len = myGetlineV(line, MAXLINE)) > 0) {
		printf("%s", line);
	}

	return 0;
}

int myGetlineV(char s[], int lim)
{
	int c, i;

	for (i = 0; i < lim - 1; ++i) {
		if ((c = getchar()) == '\n')
			break;
		if (c == EOF)
			break;

		s[i] = c;
	}

	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}
