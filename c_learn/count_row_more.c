#include <stdio.h>

int main(void) {

    int count, simb;
    count = 0;

    while ((simb = getchar()) != EOF)
        if ((simb == '\n') || (simb == ' '))
            ++count;
    printf("%d\n", count);
    return 0;

}