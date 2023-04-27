//Leonardo Fraga TIA:32158841 04N11 -- Lab04-Memória
#include <stdio.h>
#include <stdlib.h>

struct reg {
    int conteudo;
    struct reg *prox;
};
typedef struct reg celula;

void imprime(celula *p) {
    while (p != NULL) {
        printf("%d ", p->conteudo);
        p = p->prox;
    }
}

void remover(celula *p) {
    celula *aux;
    while (p != NULL) {
        aux = p;
        p = p->prox;
        free(aux);
    }
}

int main() {
  //1-)Considerando a estrutura de dados celula, crie três instâncias do objeto célula (três valores na lista); 
  celula *c1 = (celula*) malloc(sizeof(celula));
  c1->conteudo = 1;
  celula *c2 = (celula*) malloc(sizeof(celula));
  c2->conteudo = 2;
  celula *c3 = (celula*) malloc(sizeof(celula));
  c3->conteudo = 3;
    
  c1->prox = c2;
  c2->prox = c3;
  c3->prox = NULL;
    
  //2-)Construa uma função que imprima todos os valores da lista; 
  imprime(c1);

  
  //3-)Calcule a quantidade de memória gasta por cada instância da célula
  printf("\nTamanho de cada célula: %ld bytes\n", sizeof(celula));

  
  //4-)Construa uma função que remove os elementos da lista;
  //5-)Incremente sua função liberando a memória quando um elemento é liberado;
  remover(c1);

  //6-)Calcule o máximo de elementos possíveis na fila, considerando a memória disponível no computador.
  int tamanho_memoria;
  int max_elementos;
  
  printf("Digite a quantidade de memoria do computador:");
  scanf("%d", &tamanho_memoria);
  
  max_elementos = (tamanho_memoria*1000000000 )/16;
  printf("O máximo de elementos possíveis na fila: %d", max_elementos);
    
    
  return 0;
}
