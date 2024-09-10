#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int a() {
    return rand() % 6 + 1; 
}

int b(int dice1, int dice2) {
    return (dice1 + dice2 == 2) || (dice1 + dice2 == 12);
}

int main() {
    srand(time(NULL));

    int dice1 = a();
    int dice2 = a();

    printf("첫 번째 주사위: %d\n", dice1);
    printf("두 번째 주사위: %d\n", dice2);

    if (b(dice1, dice2)) {
        printf("두 눈의 합이 2 또는 12입니다.\n");
    }
    else {
        printf("두 눈의 합이 2 또는 12가 아닙니다.\n");
    }

    return 0;
}