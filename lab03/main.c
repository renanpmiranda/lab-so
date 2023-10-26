#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

double **A;   // matriz
double *x;    // vetor
double *y;    // vetor resultado
int m, n;     // dimensões da matriz e vetor
int thread_count;

void *Pth_mat_vect(void* rank);

int main(int argc, char* argv[]) {
    long       thread;
    pthread_t* thread_handles;

    printf("Digite o número de linhas m da matriz: ");
    scanf("%d", &m);
    printf("Digite o número de colunas n da matriz (e tamanho do vetor x): ");
    scanf("%d", &n);

    // Alocando e inicializando a matriz A
    A = malloc(m * sizeof(double*));
    for (int i = 0; i < m; i++) {
        A[i] = malloc(n * sizeof(double));
        for (int j = 0; j < n; j++) {
            A[i][j] = i + j;
        }
    }

    // Alocando e inicializando o vetor x
    x = malloc(n * sizeof(double));
    for (int j = 0; j < n; j++) {
        x[j] = j;
    }

    // Alocando o vetor resultado y
    y = malloc(m * sizeof(double));

    thread_count = strtol(argv[1], NULL, 10);
    thread_handles = malloc(thread_count * sizeof(pthread_t));

    for (thread = 0; thread < thread_count; thread++) {
        pthread_create(&thread_handles[thread], NULL, Pth_mat_vect, (void*) thread);
    }

    for (thread = 0; thread < thread_count; thread++) {
        pthread_join(thread_handles[thread], NULL);
    }

    // Imprime o vetor resultado y
    printf("Vetor Resultado y:\n");
    for (int i = 0; i < m; i++) {
        printf("%.2f ", y[i]);
    }
    printf("\n");

    // Libera a memória alocada
    for (int i = 0; i < m; i++) {
        free(A[i]);
    }
    free(A);
    free(x);
    free(y);
    free(thread_handles);
    return 0;
}

void *Pth_mat_vect(void* rank) {
    long my_rank = (long) rank;
    int i, j;
    int local_m = m / thread_count;
    int my_first_row = my_rank * local_m;
    int my_last_row = my_first_row + local_m - 1;

    // Se m não for divisível por thread_count, as últimas threads processarão uma linha extra
    if (my_rank == thread_count - 1) {
        my_last_row = m - 1;
    }

    for (i = my_first_row; i <= my_last_row; i++) {
        y[i] = 0.0;
        for (j = 0; j < n; j++)
            y[i] += A[i][j] * x[j];
    }

    return NULL;
}

