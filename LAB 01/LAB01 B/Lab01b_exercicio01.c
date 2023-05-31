//Leonardo Fraga 32158841 CC Noturno 04N11 SO
#include <stdio.h>

int main(void) {
  //exercicio 1
  int n, linha, menor;
  
  printf("Digite a dimensão da matriz:\n");
  scanf("%d", &n);

  int matriz[n][n];
  
  
  for(int i=0;i<n;i++){ 
    for(int j=0; j<n; j++)
    {
      printf ("\n Digite o Elemento[%d][%d] = ", i, j);
      scanf ("%d", &matriz[i][j]);
    }
  }

  menor = matriz[0][0];

  for(int i=0;i<n;i++){ 
    for(int j=0; j<n; j++)
    {
      if(matriz[i][j] < menor){
        linha = i;
      }
    }
  }

  printf("\nA linha %d tem o menor numero",linha+1);
  
  return 0;
}