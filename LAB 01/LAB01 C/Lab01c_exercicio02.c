//Leonardo Fraga 32158841 -- CC Noturno 04N Sistemas Operacionais

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  FILE *arquivo1, *arquivo2;
  char c;

  arquivo1 = fopen(argv[1], "r");
  if (arquivo1 == NULL) {
    printf("\nErro: ao Abrir o Arquivo de Entrada!!\n");
       
  }
  arquivo2 = fopen(argv[2], "w");
  if (arquivo2 == NULL) {
    printf("\nErro: ao Criar Arquivo!!\n");
        
  }
  
  while ((c = fgetc(arquivo1)) != EOF) {
    fputc(c, arquivo2);
  }
  fclose(arquivo1);
  fclose(arquivo2);
  printf("\nArquivo Copiado com Sucesso!!\n");

  return 0;
}
