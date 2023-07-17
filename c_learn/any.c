#include <stdio.h>

int any(char[], char[]);

int main(void)
{
	int p;
	p = any("test", "test");
	printf("p: %d\n", p);

	p = any("test", "es");
	printf("p: %d\n", p);

	p = any("test", "s1");
	printf("p: %d\n", p);

	p = any("test", "123");
	printf("p: %d\n", p);

	return 0;
}

int any(char s1[], char s2[])
{
	/*
	Напишите функцию any(s1, s2), которая возвращает либо ту позицию в s1,
	где стоит первый символ, совпавший с любым из символов в s2, либо -1
	(если ни один символ из s1 не совпадает с символами из s2).
	(Стандартная библиотечная функция strpbrk делает то же самое, но выдает
	не номер позиции символа, а указатель на символ.)
	*/
	int i, j;
	int result = -1;

	for(i = 0; s1[i] != '\0'; i++) {
		for (j = 0; s2[j] != '\0'; j++) {
			if (s1[i] == s2[j]) {
				result = i;
				break;
			}
		}

		if (result != -1)
			break;
	}

	return result;
}

