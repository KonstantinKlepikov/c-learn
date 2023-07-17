#include <stdio.h>

int lower(int);

int main(void)
{
	printf("%c\n", lower('S'));
	printf("%c\n", lower('A'));
	printf("%c\n", lower('Z'));
	printf("%c\n", lower('a'));
}

int lower(int c)
{
	/*
	Напишите функцию lower, которая переводит большие буквы в малые,
	используя условное выражение (а не конструкцию if-else).
	*/
	return (c >= 'A' && c <= 'Z') ? (c + 'a' - 'A') : c;
}

