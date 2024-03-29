#include <stdio.h>

unsigned rightrot(unsigned, unsigned);

int main(void)
{
	int a = rightrot(255, 32);
	printf("%d\n", a);

	int b = rightrot(1, 30);
	printf("%d\n", b);
}

unsigned rightrot(unsigned x, unsigned n)
{
	/*
	Напишите функцию rightrot(х, n), которая циклически
	сдвигает x вправо на n разрядов.
	*/
	while (n-- > 0) {
		if (x & 1 == 1) {
			x = (x >> 1) | ~(~0U >> 1);
		} else {
			x = x >> 1;
		}
	}

	return x;
}

