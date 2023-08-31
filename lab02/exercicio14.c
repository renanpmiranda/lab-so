#include <stdio.h>
#include <string.h>

void inserirCaractere(char str[], int posicao, char caractere) {
    int tamanho = strlen(str);

    if (tamanho < 99 && posicao >= 0 && posicao <= tamanho) {
        for (int i = tamanho; i >= posicao; i--) {
            str[i + 1] = str[i];
        }
        str[posicao] = caractere;
    }
}

int main() {
    char str[100];
    char caractere;
    int posicao;

    printf("Digite uma string: ");
    fgets(str, sizeof(str), stdin);

    printf("Digite o caractere a ser inserido: ");
    scanf(" %c", &caractere); // Usamos um espaço antes do %c para consumir a quebra de linha

    printf("Digite a posição do caractere a ser inserido: ");
    scanf("%d", &posicao);

    inserirCaractere(str, posicao, caractere);

    printf("String após inserir o caractere: %s\n", str);

    return 0;
}
