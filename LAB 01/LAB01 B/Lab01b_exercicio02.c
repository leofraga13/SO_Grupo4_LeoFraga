//Leonardo Fraga 32158841 CC Noturno 04N11 SO
#include <stdio.h>

int main(void) {
  //exercicio 2
  float n1, n2, n3, me, media;
  
  printf("Digite a nota da N1:");
  scanf("%f", &n1);

  printf("\nDigite a nota da N2:");
  scanf("%f", &n2);

  printf("\nDigite a nota da N3:");
  scanf("%f", &n3);

  printf("\nDigite a nota da ME:");
  scanf("%f", &me);

  media = (n1 + n2*2 + n3*3 + me)/7;

  if(media < 4){
    printf("\nE");
  }
  else if(media >= 4 && media < 6){
    printf("\nD");
  }
  else if(media >= 6 && media < 7.5){
    printf("\nC");
  }
  else if(media >= 7.5 && media < 9){
    printf("\nB");
  }
  else if(media >= 9){
    printf("\nA");
  }

  
  return 0;
}