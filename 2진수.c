#include <stdio.h>

void decimalToBinary(int n) {
    int binaryNum[32]; 

    int i = 0;
    while (n > 0) {
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }

    printf("2진수로 변환된 정수부분 : ");
    if (i == 0) {
        printf("0"); // 정수부가 0인 경우
    }
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binaryNum[j]);
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
    printf("\n2진수로 변환된 소수부분 : ");
    for (int i = 0; i < 10; i++) {
        printf("%d", binary[i]);
    }
    printf("\n");
}

int main() {
    double num;
    printf("10진수 입력 : ");
    scanf_s("%lf", &num);

    int integerPart = (int)num; // 정수 부분 추출
    decimalToBinary(integerPart); // 정수 부분을 2진수로 변환하여 출력
    decimalToBinaryWithFraction(num); // 소수 부분을 2진수로 변환하여 출력

    return 0;
}
