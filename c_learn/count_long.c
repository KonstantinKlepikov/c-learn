#include <stdio.h>

int main(void) {

    long int count;
    count = 0;

    while (getchar() != EOF)
        ++count;
    printf("%ld\n", count);
}