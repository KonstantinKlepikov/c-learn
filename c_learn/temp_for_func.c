#include <stdio.h>

float transform(int fahr);

int main(void) {

    int fahr;
    for (fahr = 0; fahr <= 300; fahr = fahr + 20) {
        printf("%3d %6.1f\n", fahr, transform(fahr));
    }
    return 0;
}

float transform(int fahr) {
    return (5.0 / 9.0) * (fahr - 32);
}
