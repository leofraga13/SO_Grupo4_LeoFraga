//Leonardo Fraga 32158841 CC Noturno 04N11 SO
#include <stdio.h>

int main(void) {
  //exercicio 3
  int n_max;

  printf("Digite o numero maximo(Numero deve ser impar):");
  scanf("%d", &n_max);

  while(n_max%2 == 0){
    printf("\nO NUMERO DEVE SER IMPAR\n\n");
    printf("\nDigite o numero maximo(Numero deve ser impar):");
    scanf("%d", &n_max);
  }

  for(int i = 0; i<= (n_max / 2) + 1; i++){
    for ( int j = i + 1; j <= n_max - i; j++ )
    {
      printf("%d ",j);
    }
    
    printf("\n");
    for ( int j = 0; j < (i + 1) * 2; j++ ){ 
      printf(" ");
    }
  }
    
  return 0;
}