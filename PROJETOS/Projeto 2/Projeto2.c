// Leonardo Fraga 32158841 -- Projeto 2 -- Sistemas Operacionais 04N11
#define _GNU_SOURCE
#include <stdlib.h>
#include <malloc.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <sched.h>
#include <stdio.h>
#include <pthread.h>

#define FIBER_STACK 1024*64
#define MAXIMO 100
pthread_mutex_t mutex;

struct c {
  int saldo;
};
typedef struct c conta;
conta from, to;
int valor;

int transferencia(void* arg) {
  pthread_mutex_lock(&mutex);
  //verifica se a conta from tem saldo para a transeferencia e realiza ela.
  if (from.saldo >= valor) {
    from.saldo -= valor;
    pthread_mutex_unlock(&mutex); // libera o mutex apos a transferencia.
    pthread_mutex_lock(&mutex);   // adquire novamente o mutex para a transferencia .
    to.saldo += valor;
    pthread_mutex_unlock(&mutex); // libera o mutex apos a transferencia .
    
  }//troca a conta que recebe e a que envia as transferencias.
  else if (to.saldo >= valor) {
    to.saldo -= valor;
    pthread_mutex_unlock(&mutex); 
    pthread_mutex_lock(&mutex);   
    from.saldo += valor;
    pthread_mutex_unlock(&mutex); 
    
  } 
  else {//caso nao for possivel fazer nenhuma transferencia, apenas libera o mutex.
    pthread_mutex_unlock(&mutex); 
  }

  printf("Transferência concluída com sucesso!\n");
  printf("Saldo de c1: %d\n", from.saldo);
  printf("Saldo de c2: %d\n", to.saldo);

  return 0;
}



int main() {
  void *stack;
  pid_t pid;

  //aloca memoria para uma pilha e verifica se a alocação de memoria deu certo.
  stack = malloc(FIBER_STACK);
  if (stack == 0) {
    perror("malloc: could not allocate stack");
    exit(1);
  }

  from.saldo = 100;
  to.saldo = 100;
  valor = 10;
  pthread_mutex_init(&mutex, NULL);//inicializando o mutex.

  int cont = 0;
  //criando varias threads que executam a função transferencia em paralelo.
  while (cont < MAXIMO) {
    pid = clone(&transferencia, (char *)stack + FIBER_STACK, SIGCHLD | CLONE_FS | CLONE_FILES | CLONE_SIGHAND | CLONE_VM, 0);
    
    if (pid == -1) {//se a chamada clone falhar, o prgrama é encerrado.
      perror("clone");
      exit(2);
    }

    usleep(1000); // Aguarda um pequeno yempo entre cada transferencia .

    cont++;
  }

  //liberando a memoria
  pthread_mutex_destroy(&mutex);
  free(stack);

  printf("Transferências concluídas e memória liberada.\n");
  return 0;
}