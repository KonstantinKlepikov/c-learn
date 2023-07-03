#include <stdio.h>

int main(void) {

    #define START 300

    int fahr;
    for (fahr = START; fahr >= 0; fahr = fahr - 20) {
        printf("%3d %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));
    }
    return 0;
}
