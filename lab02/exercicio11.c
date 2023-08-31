#include <stdio.h>

// Função para somar os elementos das linhas L1 e L2 e armazenar o resultado em L2
void somarLinhas(int matriz[][100], int colunas, int L1, int L2) {
    for (int j = 0; j < colunas; j++) {
        matriz[L2][j] += matriz[L1][j];
    }
}

// Função para multiplicar os elementos das linhas L1 e L2 e armazenar o resultado em L2
void multiplicarLinhas(int matriz[][100], int colunas, int L1, int L2) {
    for (int j = 0; j < colunas; j++) {
        matriz[L2][j] *= matriz[L1][j];
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

    int L1, L2;
    printf("Digite o número da linha L1: ");
    scanf("%d", &L1);

    printf("Digite o número da linha L2: ");
    scanf("%d", &L2);

    // Somando os elementos das linhas L1 e L2 e armazenando em L2
    somarLinhas(matriz, colunas, L1, L2);

    printf("Matriz após somar os elementos das linhas L1 e L2:\n");
    imprimirMatriz(matriz, linhas, colunas);

    // Multiplicando os elementos das linhas L1 e L2 e armazenando em L2
    multiplicarLinhas(matriz, colunas, L1, L2);

    printf("Matriz após multiplicar os elementos das linhas L1 e L2:\n");
    imprimirMatriz(matriz, linhas, colunas);

    return 0;
}
