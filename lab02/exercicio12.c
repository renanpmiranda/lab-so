#include <stdio.h>
#include <string.h>

int encontrarCaractere(const char *string, char caractere) {
    int tamanho = strlen(string);

    for (int i = 0; i < tamanho; i++) {
        if (string[i] == caractere) {
            return i; // Retorna a posição do caractere encontrado
        }
    }

    return -1; // Retorna -1 se o caractere não foi encontrado
}

int main() {
    char frase[100];
    char alvo;

    printf("Digite uma frase: ");
    fgets(frase, sizeof(frase), stdin);

    printf("Digite o caractere a ser encontrado: ");
    scanf("%c", &alvo);

    int posicao = encontrarCaractere(frase, alvo);

    if (posicao != -1) {
        printf("O caractere '%c' foi encontrado na posição %d.\n", alvo, posicao);
    } else {
        printf("O caractere '%c' não foi encontrado na frase.\n", alvo);
    }

    return 0;
}
