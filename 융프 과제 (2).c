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

    printf("ù ��° �ֻ���: %d\n", dice1);
    printf("�� ��° �ֻ���: %d\n", dice2);

    if (b(dice1, dice2)) {
        printf("�� ���� ���� 2 �Ǵ� 12�Դϴ�.\n");
    }
    else {
        printf("�� ���� ���� 2 �Ǵ� 12�� �ƴմϴ�.\n");
    }

    return 0;
}