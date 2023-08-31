#include <stdio.h>

int main() {
    int n;

     printf("Digite a ordem da matriz quadrada: ");
     scanf("%d", &n);

     int matriz[n][n];

     //Lendo os elementos da matriz
     printf("Digite os elementos da matriz:\n");
     for (int i = 0; i < n; i++) {
         for (int j = 0; j < n; j++) {
             scanf("%d", &matriz[i][j]);
         }
     }

     int menorValor = matriz[0][0];
     int linhaMenorValor = 0;

     //Encontrando o menor valor e sua linha correspondente
     for (int i = 0; i < n; i++) {
         for (int j = 0; j < n; j++) {
             if (matriz[i][j] < menorValor) {
                 menorValor = matriz[i][j];
                 linhaMenorValor = i;
             }
         }
     }

     printf("A linha com o menor valor é: %d\n", linhaMenorValor + 1);

     return 0;
 }
