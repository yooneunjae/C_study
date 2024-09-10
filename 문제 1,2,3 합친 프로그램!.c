#include <stdio.h>

// IEEE 754 Standard�� ���� 32��Ʈ �ε� �Ҽ��� ���� ����ϴ� �Լ�
void printIEEE754(float num) {
    union {
        float f;
        unsigned int i;
    } converter;

    converter.f = num;
    unsigned int bits = converter.i;

    printf("32��Ʈ IEEE 754 ǥ��: ");
    for (int i = 31; i >= 0; i--) {
        printf("%u", (bits >> i) & 1);
        if (i == 31 || i == 23) printf(" "); // ��ȣ ��Ʈ, ���� ��Ʈ�� ���� ��Ʈ ����
    }
    printf("\n");
}

// 10������ 2������ ��ȯ�ϴ� �Լ�
void decimalToBinary(int n) {
    int binaryNum[32];

    int i = 0;
    while (n > 0) {
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }

    printf("2������ ��ȯ�� �����κ�: ");
    if (i == 0) {
        printf("0"); // �����ΰ� 0�� ���
    }
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binaryNum[j]);
    }
}

// 10������ 16������ ��ȯ�ϴ� �Լ�
void decimalToHexadecimal(int n) {
    char hexNum[32];

    int i = 0;
    while (n > 0) {
        int remainder = n % 16;
        if (remainder < 10) {
            hexNum[i] = remainder + '0';
        }
        else {
            hexNum[i] = remainder - 10 + 'A';
        }
        n = n / 16;
        i++;
    }

    printf("16������ ��ȯ�� �����κ�: ");
    if (i == 0) {
        printf("0"); // �����ΰ� 0�� ���
    }
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", hexNum[j]);
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
    printf("\n2������ ��ȯ�� �Ҽ��κ�: ");
    for (int i = 0; i < 10; i++) {
        printf("%d", binary[i]);
    }
    printf("\n");
}

// ���� �κ��� ������ �Ҽ� �κи� 16������ ��ȯ�ϴ� �Լ�
void decimalToHexadecimalWithFraction(double num) {
    // ���� �κ��� ����
    double decimalPart = num - (int)num;

    // �ִ� 10�ڸ��� 16������ ǥ��
    char hexNum[10];

    // �Ҽ��θ� 16������ ��ȯ
    for (int i = 0; i < 10; i++) {
        decimalPart *= 16;
        int digit = (int)decimalPart;
        if (digit < 10) {
            hexNum[i] = digit + '0';
        }
        else {
            hexNum[i] = digit - 10 + 'A';
        }
        decimalPart -= digit;
    }

    // ��ȯ�� 16���� ���
    printf("\n16������ ��ȯ�� �Ҽ��κ�: ");
    for (int i = 0; i < 10; i++) {
        printf("%c", hexNum[i]);
    }
    printf("\n");
}

int main() {
    double num;
    int choice;
    int exit = 0; // 0�� false��, �� ���� ���� true�� ����

    while (!exit) {
        printf("\n10���� �Է� (�����Ϸ��� -1 �Է�): ");
        scanf_s("%lf", &num);

        if (num == -1) {
            exit = 1; // ���� ���� ����
            continue;
        }

        printf("��ȯ�� ���� ���� (2 �Ǵ� 16): ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 2:
            // ���� �κ��� 2������ ��ȯ�Ͽ� ���
            decimalToBinary((int)num);
            // �Ҽ� �κ��� 2������ ��ȯ�Ͽ� ���
            decimalToBinaryWithFraction(num);
            break;
        case 16:
            // ���� �κ��� 16������ ��ȯ�Ͽ� ���
            decimalToHexadecimal((int)num);
            // �Ҽ� �κ��� 16������ ��ȯ�Ͽ� ���
            decimalToHexadecimalWithFraction(num);
            break;
        default:
            printf("�߸��� �����Դϴ�.\n");
            break;
        }

        // �ε� �Ҽ��� �� ���
        printIEEE754((float)num);
    }

    return 0;
}
