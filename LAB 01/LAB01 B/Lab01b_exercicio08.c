//Leonardo Fraga 32158841 CC Noturno 04N11 SO
#include <stdio.h>

void transposta(int linha, int coluna, int matriz[linha][coluna]){
  int transposta[coluna][linha];
  
  for(int i=0;i<linha;i++){ 
    for(int j=0; j<coluna; j++)
    {
      transposta[j][i] = matriz[i][j];
    }
  }

  printf("\n\nMatriz Transposta:\n");
  for (int i=0; i<linha; i++ ){ 
    for (int j=0; j<coluna; j++ )
    {
      printf ("%d ", transposta[ i ][ j ]);
    }
    printf("\n");
  }
}


int main(void) {
  //exercicio 8
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

  transposta(linha, coluna, matriz);
  return 0;
}