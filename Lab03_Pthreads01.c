//Leonardo Fraga TIA:32158841 
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


int thread_count;  
int linha;
int coluna;  
double** A;  
double* x;  
double* y;  


void *Pth_mat_vect(void* rank) {
    long my_rank = (long) rank;
    int i, j;
    int local_m = linha / thread_count;
    int my_first_row = my_rank * local_m;
    int my_last_row = (my_rank + 1) * local_m - 1;

    for (i = my_first_row; i <= my_last_row; i++) {
        y[i] = 0.0;
        for (j = 0; j < coluna; j++) {
            y[i] += A[i][j] * x[j];
        }
    }
    return NULL;
}


int main(int argc, char* argv[]) {
    long thread;  
    pthread_t* thread_handles;  

   
    printf("Entre com as linhas da matriz A: ");
    scanf("%d ", &linha);

    printf("Entre com as colunas da matriz A: ");
    scanf("%d ", &coluna);
    A = malloc(linha * sizeof(double*));
    for (int i = 0; i < linha; i++) {
        A[i] = malloc(coluna * sizeof(double));
    }

    printf("Entre com a matriz A:\n");
    for (int i = 0; i < linha; i++) {
        for (int j = 0; j < coluna; j++) {
            scanf("%lf", &A[i][j]);
        }
    }

    x = malloc(linha * sizeof(double));

    printf("Entre com o vetor x:\n");
    for (int i = 0; i < coluna; i++) {
        scanf("%lf", &x[i]);
    }

    y = malloc(linha * sizeof(double));

    
    thread_count = strtol(argv[1], NULL, 10);
    thread_handles = malloc(thread_count * sizeof(pthread_t));
    for (thread = 0; thread < thread_count; thread++) {
        pthread_create(&thread_handles[thread], NULL, Pth_mat_vect, (void*) thread);
    }

   
    for (thread = 0; thread < thread_count; thread++) {
        pthread_join(thread_handles[thread], NULL);
    }

  
    printf("O resultado da multiplicacao matriz-vetor e:\n");
    for (int i = 0; i < linha; i++) {
        printf("%lf\n", y[i]);
    }

  
    free(thread_handles);
    free(y);
    free(x);
    for (int i = 0; i < linha; i++) {
        free(A[i]);
    }
    free(A);

    return 0;
}
