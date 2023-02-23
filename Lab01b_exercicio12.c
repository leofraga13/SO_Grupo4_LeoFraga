//Leonardo Fraga 32158841 CC Noturno 04N11 SO
#include <stdio.h>
#include <string.h>

int posicao(char palavra[4], char letra, int n){
  for(int i=0; i<n;i++){
    if(letra == palavra[i]){
      printf("%d", i);
      return 0;
     
    }
  }
  printf("Letra não encontrada na palvra!");
  return 0;
}

int main(void) {
  //exercicio 12
  char palavra[4] = "leao";
  char letra = 'a';
  
  posicao(palavra, letra, 4);
  return 0;
}