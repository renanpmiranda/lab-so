#include <stdio.h>

// Função para imprimir a matriz
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

    int numero;
    printf("Digite o número pelo qual deseja multiplicar: ");
    scanf("%d", &numero);

    int indice;

    switch (opcao) {
        case 1:
            printf("Digite o número da linha a ser multiplicada: ");
            scanf("%d", &indice);
            for (int j = 0; j < colunas; j++) {
                matriz[indice][j] *= numero;
            }
            break;
        case 2:
            printf("Digite o número da coluna a ser multiplicada: ");
            scanf("%d", &indice);
            for (int i = 0; i < linhas; i++) {
                matriz[i][indice] *= numero;
            }
            break;
        default:
            printf("Opção inválida.\n");
            return 1;
    }

    printf("Matriz resultante:\n");
    imprimirMatriz(matriz, linhas, colunas);

    return 0;
}
