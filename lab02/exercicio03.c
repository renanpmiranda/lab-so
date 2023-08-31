#include <stdio.h>

int main() {
    int maxNumber;

    printf("Digite o número máximo ímpar: ");
    scanf("%d", &maxNumber);

    if (maxNumber % 2 == 0) {
        printf("O número deve ser ímpar.\n");
        return 1;
    }

    for (int i = 1; i <= maxNumber; i += 2) {
        for (int j = 1; j <= (i - 1) / 2; j++) {
            printf("   ");
        }
        for (int j = i; j <= maxNumber; j++) {
            printf("%2d ", j);
        }
        printf("\n");
    }

    return 0;
}
