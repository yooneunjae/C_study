#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));  

    int d2 = 0;  
    int d12 = 0; 

    for (int i = 0; i < 1000000; ++i) {
        int dice1 = rand() % 6 + 1;
        int dice2 = rand() % 6 + 1;

        int sum = dice1 + dice2;

        if (sum == 2) {
            d2++;
        }
        else if (sum == 12) {
            d12++;
        }
    }
    double p2 = (double)d2 / 1000000.0;
    double p12 = (double)d12 / 1000000.0;

    printf("´«ÀÇ ÇÕÀÌ 2°¡ µÉ È®·ü: %lf\n", p2);
    printf("´«ÀÇ ÇÕÀÌ 12°¡ µÉ È®·ü: %lf\n", p12);

    return 0;
}