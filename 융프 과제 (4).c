#include <stdio.h>

int main() {
    int s = 0;
    int k;
    int terms[50];

    for (k = 1; k <= 50; k++) {
        terms[k - 1] = (2 * k + 3) * (2 * k + 3);
    }

    for (k = 0; k < 50; k++) {
        s += terms[k];
    }

    printf("s °ª: %d\n", s);

    return 0;
}