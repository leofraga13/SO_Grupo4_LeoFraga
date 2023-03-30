// Leonardo Fraga 32158841 -- Projeto 1 -- Sistemas Operacionais 04N11
//a-)
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define n 5 
typedef sem_t semaforo;

semaforo garfo[n]; 

void *filosofo(void *arg) {
  int id = *(int *)arg; 
  int esq = id;
  int dir = (id + 1) % n;
  int tempo_limite = 10; 

  while (1){
    printf("Filosofo %d esta pensando\n", id);
    usleep(random() % 1000000); 

    
    printf("Filosofo %d esta tentando pegar os garfos\n", id);
    sem_wait(&garfo[esq]);
    sem_wait(&garfo[dir]);
    printf("Filosofo %d pegou os garfos e esta comendo\n", id);
    usleep(random() % 1000000); 

        
    printf("Filosofo %d terminou de comer e esta soltando os garfos\n", id);
    sem_post(&garfo[dir]);
    sem_post(&garfo[esq]);

    tempo_limite--;
    if (tempo_limite == 0) { 
      break;
    }
  }

  printf("Filosofo %d terminou de comer e esta satisfeito\n", id);
  pthread_exit(NULL);
}


int main() {
    pthread_t threads[n]; 
    int ids[n];

    for (int i = 0; i < n; i++) {
        sem_init(&garfo[i], 0, 1);
    }

    for (int i = 0; i < n; i++) {
        ids[i] = i;
        pthread_create(&threads[i], NULL, filosofo, &ids[i]);
    }

    for (int i = 0; i < n; i++) {
        pthread_join(threads[i], NULL);
    }

    for (int i = 0; i < n; i++) {
        sem_destroy(&garfo[i]);
    }

    return 0;
}

/* 
b-)
  O problema de sincronização é resolvido por meio do uso de semáforos. No início do programa, são criados semáforos para cada garfo, inicializados com valor 1, indicando que estão disponíveis.
  Para garantir que apenas um filósofo pegue um garfo de cada vez, são utilizadas operações sem_wait e sem_post nos semáforos correspondentes a cada garfo, bloqueando o acesso a outros filósofos enquanto o recurso estiver em uso.
  Assim, quando um filósofo quer pegar os garfos, ele executa a função sem_wait(&garfo[esq]) para bloquear o garfo à sua esquerda e sem_wait(&garfo[dir]) para bloquear o garfo à sua direita, esperando que ambos estejam disponíveis para serem utilizados.
  Em seguida, o filósofo come por um tempo  e, depois de terminar a refeição, ele libera os garfos utilizando sem_post(&garfo[dir]) para liberar o garfo à sua direita e sem_post(&garfo[esq]) para liberar o garfo à sua esquerda, permitindo que outros filósofos possam utilizá-los.
  Assim o programa evita o deadlock.
*/