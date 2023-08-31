#include <stdio.h>

// Função para multiplicar uma linha da matriz por um número
void multiplicarLinha(int matriz[][100], int linhas, int colunas, int linha, int numero) {
    for (int j = 0; j < colunas; j++) {
        matriz[linha][j] *= numero;
    }
}

// Função para multiplicar uma coluna da matriz por um número
void multiplicarColuna(int matriz[][100], int linhas, int colunas, int coluna, int numero) {
    for (int i = 0; i < linhas; i++) {
        matriz[i][coluna] *= numero;
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

    int opcao;
    printf("Escolha a operação:\n");
    printf("1 - Multiplicar uma linha\n");
    printf("2 - Multiplicar uma coluna\n");
    scanf("%d", &opcao);

    int indice, numero;
    printf("Digite o número pelo qual deseja multiplicar: ");
    scanf("%d", &numero);

    switch (opcao) {
        case 1:
            printf("Digite o número da linha a ser multiplicada: ");
            scanf("%d", &indice);
            multiplicarLinha(matriz, linhas, colunas, indice, numero);
            break;
        case 2:
            printf("Digite o número da coluna a ser multiplicada: ");
            scanf("%d", &indice);
            multiplicarColuna(matriz, linhas, colunas, indice, numero);
            break;
        default:
            printf("Opção inválida.\n");
            return 1;
    }

    printf("Matriz resultante:\n");
    imprimirMatriz(matriz, linhas, colunas);

    return 0;
}
