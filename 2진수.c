#include <stdio.h>

void decimalToBinary(int n) {
    int binaryNum[32]; 

    int i = 0;
    while (n > 0) {
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }

    printf("2������ ��ȯ�� �����κ� : ");
    if (i == 0) {
        printf("0"); // �����ΰ� 0�� ���
    }
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binaryNum[j]);
    }
}

// ���� �κ��� ������ �Ҽ� �κи� 2������ ��ȯ�ϴ� �Լ�
void decimalToBinaryWithFraction(double num) {
    // ���� �κ��� ����
    double decimalPart = num - (int)num;

    // �ִ� 10�ڸ��� 2������ ǥ��
    int binary[10];

    // �Ҽ��θ� 2������ ��ȯ
    for (int i = 0; i < 10; i++) {
        decimalPart *= 2;
        binary[i] = (int)decimalPart;
        decimalPart -= (int)decimalPart;
    }

    // ��ȯ�� 2���� ���
    printf("\n2������ ��ȯ�� �Ҽ��κ� : ");
    for (int i = 0; i < 10; i++) {
        printf("%d", binary[i]);
    }
    printf("\n");
}

int main() {
    double num;
    printf("10���� �Է� : ");
    scanf_s("%lf", &num);

    int integerPart = (int)num; // ���� �κ� ����
    decimalToBinary(integerPart); // ���� �κ��� 2������ ��ȯ�Ͽ� ���
    decimalToBinaryWithFraction(num); // �Ҽ� �κ��� 2������ ��ȯ�Ͽ� ���

    return 0;
}
