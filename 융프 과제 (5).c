#include <stdio.h>

int main() { 
    int s = 50;

    int k1, k2, k3, k4, k5, k6, k7, k8, k9, k10,
        k11, k12, k13, k14, k15, k16, k17, k18, k19, 
        k20, k21, k22, k23, k24, k25, k26, k27, k28, k29,
        k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, 
        k40, k41, k42, k43, k44, k45, k46, k47, k48, k49, k50;

    for (k1 = 1; k1 <= 50; k1++) {
        s += (2 * k + 3) * (2 * k + 3);
    }

    printf("s ��: %d\n", s);

    return 0;
}