#include <stdio.h>
#include <string.h>

// Definição da estrutura Pessoa
struct Pessoa {
    char nome[50];
    int idade;
    float peso;
    float altura;
};

int main() {
    struct Pessoa pessoas[3]; // Vetor de pessoas

    printf("Digite os dados de 3 pessoas:\n");

    for (int i = 0; i < 3; i++) {
        printf("Pessoa %d:\n", i + 1);

        printf("Nome: ");
        scanf("%s", pessoas[i].nome);

        printf("Idade: ");
        scanf("%d", &pessoas[i].idade);

        printf("Peso: ");
        scanf("%f", &pessoas[i].peso);

        printf("Altura: ");
        scanf("%f", &pessoas[i].altura);

        printf("\n");
    }

    printf("Dados das pessoas:\n");
    for (int i = 0; i < 3; i++) {
        printf("Pessoa %d:\n", i + 1);
        printf("Nome: %s\n", pessoas[i].nome);
        printf("Idade: %d\n", pessoas[i].idade);
        printf("Peso: %.2f\n", pessoas[i].peso);
        printf("Altura: %.2f\n", pessoas[i].altura);
        printf("\n");
    }

    return 0;
}
