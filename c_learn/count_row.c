#include <stdio.h>

int main(void) {

    int count, simb;
    count = 0;

    while ((simb = getchar()) != EOF)
        if (simb == '\n') //double quotes is char, single quotes - ASCII code of char
            ++count;
    printf("%d\n", count);
    return 0;

}