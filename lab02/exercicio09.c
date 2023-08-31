#include <stdio.h>
#include <stdlib.h>

// Função para substituir números negativos pelo seu módulo na matriz
void substituirNegativosPorModulo(int matriz[][100], int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            if (matriz[i][j] < 0) {
                matriz[i][j] = abs(matriz[i][j]); // Função abs() retorna o valor absoluto
            }
        }
    }
}

// Função para imprimir uma matriz
void imprimirMatriz(int matriz[][100], int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int linhas, colunas;

    printf("Digite o número de linhas da matriz: ");
    scanf("%d", &linhas);

    printf("Digite o número de colunas da matriz: ");
    scanf("%d", &colunas);

    int matriz[100][100];

    // Lendo a matriz do teclado
    printf("Digite os elementos da matriz:\n");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    // Substituindo números negativos pelo módulo
    substituirNegativosPorModulo(matriz, linhas, colunas);

    printf("Matriz após substituição de negativos pelo módulo:\n");
    imprimirMatriz(matriz, linhas, colunas);

    return 0;
}
