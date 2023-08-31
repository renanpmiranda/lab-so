#include <stdio.h>

// Função para calcular a transposta de uma matriz
void calcularTransposta(int matriz[][100], int linhas, int colunas, int transposta[][100]) {
    for (int i = 0; i < colunas; i++) {
        for (int j = 0; j < linhas; j++) {
            transposta[i][j] = matriz[j][i];
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
    int transposta[100][100];

    // Lendo a matriz do teclado
    printf("Digite os elementos da matriz:\n");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    // Calculando a matriz transposta
    calcularTransposta(matriz, linhas, colunas, transposta);

    printf("Matriz original:\n");
    imprimirMatriz(matriz, linhas, colunas);

    printf("\nMatriz transposta:\n");
    imprimirMatriz(transposta, colunas, linhas);

    return 0;
}
