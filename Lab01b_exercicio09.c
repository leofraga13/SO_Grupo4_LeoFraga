//Leonardo Fraga 32158841 CC Noturno 04N11 SO
#include <stdio.h>


void nova_matriz(int linha, int coluna, int matriz[linha][coluna]){
  int nova[linha][coluna];

  for(int i=0;i<linha;i++){ 
    for(int j=0; j<coluna; j++)
    {
      if(matriz[i][j] >= 0){
        nova[i][j] = matriz[i][j];
      }
      else{
         nova[i][j] = matriz[i][j] * -1;
      }
    }
  }

  for (int i=0; i<linha; i++ ){ 
    for (int j=0; j<coluna; j++ )
    {
      printf ("%d ", nova[ i ][ j ]);
    }
    printf("\n");
  }
  
}

int main(void) {
  //exercicio 9
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
  
  nova_matriz(linha, coluna, matriz);

  return 0;
}