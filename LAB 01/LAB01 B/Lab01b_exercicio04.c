//Leonardo Fraga 32158841 CC Noturno 04N11 SO
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  //exercicio 4
  char nome1[15];
  char nome2[15];
  int comparacao;

  printf("Digite o Primeiro Nome: ");
  scanf("%s", nome1);

  printf("\nDigite o Segundo Nome: ");
  scanf("%s", nome2);

  comparacao = strcoll(nome2, nome1);
  
  if(comparacao == 1){
    printf("\n%s, %s", nome1,nome2);
  }
  else{
    printf("\n%s, %s", nome2,nome1);

  }

  return 0;
}