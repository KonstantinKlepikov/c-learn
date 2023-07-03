#include <stdio.h>

int main(void) {

    int result = getchar();
    printf ("%d, %d\n", (result != EOF), EOF);

}