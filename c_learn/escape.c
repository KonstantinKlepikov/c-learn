#include <stdio.h>

#define MAX_LEN 1000

void escape(char[], char[]);

int main(void)
{

	/*
	Напишите функцию escape(s, t), которая при копировании текста из t в s
	преобразует такие символы, как новая строка и табуляция в "видимые
	последовательности символов" (вроде \n и \t). Используйте инструкцию switch.
	Напишите функцию, выполняющую обратное преобразование эскейп-
	последовательностей в настоящие символы.
	*/
	char t[] = "Hello\tWorld\r\n\v";
	printf("%s\n", t);
	char s[MAX_LEN];
	escape(s, t);
	printf("%s\n", s);

	return 0;
}

void escape(char s[], char t[])
{
	int i, j, n;
	for (i = 0, j = 0; t[j] != '\0'; i++, j++) {
		switch(t[j]) {
			case '\a':
				s[i++] = '\\';
				n = 'a';
				break;
			case '\b':
				s[i++] = '\\';
				n = 'b';
				break;
			case '\f':
				s[i++] = '\\';
				n = 'f';
				break;
			case '\n':
				s[i++] = '\\';
				n = 'n';
				break;
			case '\r':
				s[i++] = '\\';
				n = 'r';
				break;
			case '\t':
				s[i++] = '\\';
				n = 't';
				break;
			case '\v':
				s[i++] = '\\';
				n = 'v';
				break;
			default:
				n = t[j];
				break;
		}
		s[i] = n;
	}
	s[i] = '\0';
}
