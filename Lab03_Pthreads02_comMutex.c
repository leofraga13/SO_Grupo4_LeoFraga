#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 1024

long thread_count;
long long n;
double sum = 0.0;
pthread_mutex_t mutex;

void* Thread_sum(void* rank) {
    long my_rank = (long) rank;
    double factor;
    long long i;
    long long my_n = n/thread_count;
    long long my_first_i = my_n*my_rank;
    long long my_last_i = my_first_i + my_n;

    if(my_first_i % 2 == 0){
        factor = 1.0;
    } else {
        factor = -1.0;
    }

    for(i = my_first_i; i < my_last_i; i++, factor = -factor) {
        pthread_mutex_lock(&mutex);
        sum += factor/(2*i+1);
        pthread_mutex_unlock(&mutex);
    }

    return NULL;
}

int main(int argc, char* argv[]) {
    long thread;
    pthread_t* thread_handles;
    double factor = 1.0;
    double pi;
    int log_threads = 1;
    int log_pi = 1;

    if (argc == 2) {
        n = strtol(argv[1], NULL, 10);
        thread_count = MAX_THREADS;
    } else if (argc == 3) {
        n = strtol(argv[1], NULL, 10);
        thread_count = strtol(argv[2], NULL, 10);
    } else {
        printf("%s <n> <num threads>\n", argv[0]);
        exit(0);
    }

    thread_handles = malloc(thread_count * sizeof(pthread_t));
    pthread_mutex_init(&mutex, NULL);

    for (thread = 0; thread < thread_count; thread++) {
        pthread_create(&thread_handles[thread], NULL, Thread_sum, (void*) thread);
    }

    for (thread = 0; thread < thread_count; thread++) {
        pthread_join(thread_handles[thread], NULL);
    }

    pi = 4.0 * sum;
    

    if (log_threads) {
        printf("\nNumero de threads = %ld\n", thread_count);
    }

    if (log_pi) {
        printf("pi = %.6f\n", pi);
    }

    pthread_mutex_destroy(&mutex);
    free(thread_handles);

    return 0;
}


