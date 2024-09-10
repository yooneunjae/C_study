#include <stdio.h>

// IEEE 754 Standard에 따라 32비트 부동 소수점 값을 출력하는 함수
void printIEEE754(float num) {
    union {
        float f;
        unsigned int i;
    } converter;

    converter.f = num;
    unsigned int bits = converter.i;

    printf("32비트 IEEE 754 표현: ");
    for (int i = 31; i >= 0; i--) {
        printf("%u", (bits >> i) & 1);
        if (i == 31 || i == 23) printf(" "); // 부호 비트, 지수 비트와 가수 비트 구분
    }
    printf("\n");
}

// 10진수를 2진수로 변환하는 함수
void decimalToBinary(int n) {
    int binaryNum[32];

    int i = 0;
    while (n > 0) {
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }

    printf("2진수로 변환된 정수부분: ");
    if (i == 0) {
        printf("0"); // 정수부가 0인 경우
    }
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binaryNum[j]);
    }
}

// 10진수를 16진수로 변환하는 함수
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

    printf("16진수로 변환된 정수부분: ");
    if (i == 0) {
        printf("0"); // 정수부가 0인 경우
    }
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", hexNum[j]);
    }
}

// 정수 부분은 버리고 소수 부분만 2진수로 변환하는 함수
void decimalToBinaryWithFraction(double num) {
    // 정수 부분은 제거
    double decimalPart = num - (int)num;

    // 최대 10자리의 2진수로 표현
    int binary[10];

    // 소수부를 2진수로 변환
    for (int i = 0; i < 10; i++) {
        decimalPart *= 2;
        binary[i] = (int)decimalPart;
        decimalPart -= (int)decimalPart;
    }

    // 변환된 2진수 출력
    printf("\n2진수로 변환된 소수부분: ");
    for (int i = 0; i < 10; i++) {
        printf("%d", binary[i]);
    }
    printf("\n");
}

// 정수 부분은 버리고 소수 부분만 16진수로 변환하는 함수
void decimalToHexadecimalWithFraction(double num) {
    // 정수 부분은 제거
    double decimalPart = num - (int)num;

    // 최대 10자리의 16진수로 표현
    char hexNum[10];

    // 소수부를 16진수로 변환
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

    // 변환된 16진수 출력
    printf("\n16진수로 변환된 소수부분: ");
    for (int i = 0; i < 10; i++) {
        printf("%c", hexNum[i]);
    }
    printf("\n");
}

int main() {
    double num;
    int choice;
    int exit = 0; // 0을 false로, 그 외의 값은 true로 간주

    while (!exit) {
        printf("\n10진수 입력 (종료하려면 -1 입력): ");
        scanf_s("%lf", &num);

        if (num == -1) {
            exit = 1; // 종료 조건 설정
            continue;
        }

        printf("변환할 진법 선택 (2 또는 16): ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 2:
            // 정수 부분을 2진수로 변환하여 출력
            decimalToBinary((int)num);
            // 소수 부분을 2진수로 변환하여 출력
            decimalToBinaryWithFraction(num);
            break;
        case 16:
            // 정수 부분을 16진수로 변환하여 출력
            decimalToHexadecimal((int)num);
            // 소수 부분을 16진수로 변환하여 출력
            decimalToHexadecimalWithFraction(num);
            break;
        default:
            printf("잘못된 선택입니다.\n");
            break;
        }

        // 부동 소수점 값 출력
        printIEEE754((float)num);
    }

    return 0;
}
