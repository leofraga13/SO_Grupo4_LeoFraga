//Leonardo Fraga 32158841 CC Noturno 04N11 SO
#include <stdio.h>

struct pessoa{
  int idade;
  float peso;
  float altura;
};

int main(void) {
  //exercicio 7
  struct pessoa pessoas[3];

  for(int i=0; i<3; i++){
    printf("\nDigite a idade da %d pessoa:", i+1);
    scanf("%d", &pessoas[i].idade);

    printf("\nDigite o peso da %d pessoa:", i+1);
    scanf("%f", &pessoas[i].peso);

    printf("\nDigite a altura da %d pessoa:", i+1);
    scanf("%f", &pessoas[i].altura);
  }

  for(int i=0; i<3; i++){
    printf("\n\nA idade da %d pessoa: %d", i+1, pessoas[i].idade);

    printf("\nO peso da %d pessoa: %.1f", i+1,pessoas[i].peso);

    printf("\nA altura da %d pessoa: %.2f", i+1, pessoas[i].altura);
  }
  
  return 0;
}