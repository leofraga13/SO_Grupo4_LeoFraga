#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

long long n;
int thread_count;
double sum = 0.0;

void* Thread_sum(void* rank) {
    long my_rank = (long) rank;
    double factor;
    long long i;
    long long my_n = n/thread_count;
    long long my_first_i = my_n*my_rank;
    long long my_last_i = my_first_i + my_n;
    double my_sum = 0.0;

    if(my_first_i % 2 == 0){
        factor = 1.0;
    } else {
        factor = -1.0;
    }

    for(i = my_first_i; i < my_last_i; i++, factor = -factor) {
        my_sum += factor/(2*i+1);
    }

    sum += my_sum;

    return NULL;
}

int main(int argc, char* argv[]) {
    long thread;
    pthread_t* thread_handles;
    double pi;
    long long term_count = 0;

    n = strtoll(argv[1], NULL, 10);
    thread_count = strtol(argv[2], NULL, 10);
    

    thread_handles = malloc (thread_count*sizeof(pthread_t));

    for (thread = 0; thread < thread_count; thread++){
        pthread_create(&thread_handles[thread], NULL, Thread_sum, (void*) thread);
    }

    for (thread = 0; thread < thread_count; thread++){
        pthread_join(thread_handles[thread], NULL);
    }

    pi = 4.0*sum;

    printf("Threads = %d\n", thread_count);
    printf("pi = %f\n", pi);

    free(thread_handles);

    return 0;
}
