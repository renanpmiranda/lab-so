#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4     // Número de threads
#define NUM_TERMS 1000000 // Número de termos na série

double sum = 0.0;         // Soma global para acumular os resultados das threads
pthread_mutex_t sum_mutex; // Mutex para proteger a variável global sum

void* Thread_sum(void* rank) {
    long my_rank = (long) rank;
    double factor;
    long long i;
    long long my_n = NUM_TERMS/NUM_THREADS;
    long long my_first_i = my_n*my_rank;
    long long my_last_i = my_first_i + my_n;

    if (my_first_i % 2 == 0) factor = 1.0;
    else factor = -1.0;

    printf("\nThread %ld iniciando cálculo para termos %lld até %lld.\n", my_rank, my_first_i, my_last_i-1);

    for (i = my_first_i; i < my_last_i; i++, factor = -factor) {
        pthread_mutex_lock(&sum_mutex);
        sum += factor/(2*i+1);
        pthread_mutex_unlock(&sum_mutex);
    }

    printf("\nThread %ld terminou.\n", my_rank);

    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    pthread_mutex_init(&sum_mutex, NULL);
    double pi_estimate = 0.0;

    printf("Calculando pi usando %d threads e %d termos.\n", NUM_THREADS, NUM_TERMS);

    for (long t = 0; t < NUM_THREADS; t++) {
        pthread_create(&threads[t], NULL, Thread_sum, (void*) t);
    }

    for (long t = 0; t < NUM_THREADS; t++) {
        pthread_join(threads[t], NULL);
    }

    pi_estimate = 4.0*sum;

    printf("\nEstimativa de pi = %f\n", pi_estimate);

    pthread_mutex_destroy(&sum_mutex);
    return 0;
}
