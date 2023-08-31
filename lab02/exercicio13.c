#include <stdio.h>
#include <string.h>

void removerCaractere(char str[], int posicao) {
    int tamanho = strlen(str);

    if (posicao >= 0 && posicao < tamanho) {
        for (int i = posicao; i < tamanho - 1; i++) {
            str[i] = str[i + 1];
        }
        str[tamanho - 1] = '\0'; // Adiciona o terminador nulo no final
    }
}

int main() {
    char str[100];
    int posicao;

    printf("Digite uma string: ");
    fgets(str, sizeof(str), stdin);

    printf("Digite a posição do caractere a ser removido: ");
    scanf("%d", &posicao);

    removerCaractere(str, posicao);

    printf("String após remover o caractere: %s\n", str);

    return 0;
}
