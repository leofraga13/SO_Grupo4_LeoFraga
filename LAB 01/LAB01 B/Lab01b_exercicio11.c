//Leonardo Fraga 32158841 CC Noturno 04N11 SO
#include <stdio.h>
void soma(int linha, int coluna, int matriz[linha][coluna]){
  int soma = 0;
  int multiplicacao = 1;
  for(int i=0;i<linha;i++){ 
    for(int j=0; j<coluna; j++)
    {
      if(i == 0 || i == 1){
        soma = soma + matriz[i][j];
        multiplicacao = multiplicacao * matriz[i][j];
      }
    }
  }

    printf("\nL1 + L2: %d", soma);
    printf("\nL1 * L2: %d", multiplicacao);
}

int main(void) {
  //exercicio 11
 int linha, coluna;
  
  printf("\nDigite o numero de linha(s) da matriz:");
  scanf("%d", &linha);

  printf("\nDigite o numero de coluna(s) da matriz:");
  scanf("%d", &coluna);

  int matriz[linha][coluna];

  for(int i=0;i<linha;i++){ 
    for(int j=0; j<coluna; j++)
    {
      printf ("\n Digite o Elemento[%d][%d] = ", i, j);
      scanf ("%d", &matriz[i][j]);
    }
  }

  soma(linha, coluna, matriz);
  return 0;
}