#include <stdio.h>

int main() {
    long long num;

    printf("30�� �̻��� ������ �Է��ϼ���:  ");
    scanf_s("%lld", &num);

    printf("õ ������ comma�� �߰��� ���: ");

    long long temp = num;
    long long comma = 1;
    int count = 0;

    while (temp != 0) {
        temp /= 10;
        count++;
    }

    while (count > 3) {
        comma *= 1000;
        count -= 3;
    }

    printf("%lld", num / comma);

    while (comma > 1) {
        comma /= 1000;
        printf(",%03lld", (num / comma) % 1000);
    }

    printf("\n");

    return 0;
}