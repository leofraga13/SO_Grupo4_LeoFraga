//Leonardo Fraga 32158841 -- CC Noturno 04N Sistemas Operacionais

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  char c;
  FILE *arquivo = fopen(argv[1], "r");
  
  if (arquivo == NULL) {
    printf("Falha ao abrir o arquivo!!!!\n");
  }

   printf("\n\n");
  while ((c = fgetc(arquivo)) != EOF) {
      putchar(c);
  }
  
  fclose(arquivo);
  return 0;
}