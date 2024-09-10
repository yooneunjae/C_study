#include <stdio.h>

int main() {
 
    int s = 0;
    int k;
    int term;

    for (k = 1; k <= 50; k++) {
        term = (2 * k + 3) * (2 * k + 3);
        s += term;
    }

    printf("s °ª: %d\n", s);

    return 0;
}