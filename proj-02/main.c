#include <stdio.h>
#include <stdlib.h>

int main() {
    for (int arquivoNum = 1; arquivoNum <= 58; arquivoNum++) {
        char nomeArquivo[20];
        sprintf(nomeArquivo, "input/E_%d", arquivoNum);

        FILE *arquivo = fopen(nomeArquivo, "r");
        if (arquivo == NULL) {
            printf("Não foi possível abrir o arquivo %s.\n", nomeArquivo);
            continue;
        }

        int N;
        fscanf(arquivo, "%d", &N);

        int ti, di;
        int tempoAtual = 0;
        int direcaoAtual = -1;
        int tempoFinalDirecaoAtual = 0;
        int tempoInicioEspera = 0;
        int direcaoEspera = -1;
        int emEspera = 0;

        for (int i = 0; i < N; i++) {
            fscanf(arquivo, "%d %d", &ti, &di);

            if (emEspera && ti >= tempoInicioEspera) {
                tempoAtual = tempoFinalDirecaoAtual;
                tempoFinalDirecaoAtual = tempoAtual + 10;
                direcaoAtual = direcaoEspera;
                emEspera = 0;
            }

            if (direcaoAtual == -1) {
                tempoAtual = ti;
                tempoFinalDirecaoAtual = ti + 10;
                direcaoAtual = di;
            } else if (di != direcaoAtual) {
                if (ti > tempoFinalDirecaoAtual) {
                    tempoAtual = ti;
                    tempoFinalDirecaoAtual = ti + 10;  
                    direcaoAtual = di;
                } else {
                    if (!emEspera) {
                        tempoInicioEspera = tempoFinalDirecaoAtual;
                        direcaoEspera = di;
                        emEspera = 1;
                    } else {
                        tempoInicioEspera = tempoFinalDirecaoAtual;
                    }
                }            
            } else if (ti <= tempoFinalDirecaoAtual) {
                tempoFinalDirecaoAtual = ti + 10;
                tempoInicioEspera = tempoFinalDirecaoAtual;
            } else {
                tempoAtual = ti;
                tempoFinalDirecaoAtual = ti + 10;
            }
        }

        if (emEspera) {
            tempoFinalDirecaoAtual += 10;
        }

        fclose(arquivo);

        printf("Tempo final para %s: %d\n", nomeArquivo, tempoFinalDirecaoAtual);
    }

    return 0;
}
