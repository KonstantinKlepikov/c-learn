#include <stdio.h>

int bitcount(unsigned);

int main(void)
{
	printf("%d\n", bitcount(255));
	printf("%d\n", bitcount(15));
	printf("%d\n", bitcount(1));
	printf("%d\n", bitcount(0));
	printf("%d\n", bitcount(~0U));
}

int bitcount(unsigned x)
{
	/*
	Применительно к числам, в представлении которых использован
	дополнительный код,
	выражение х &= (х-1) уничтожает самую правую 1 в х.
	Объясните, почему. Используйте это наблюдение при
	написании более быстрого варианта функции bitcount.
	*/
	int b = 1;

	if (x == 0)
		b--;

	while (x &= (x-1))
		b++;


	return b;
}
