//Leonardo Fraga 32158841 CC Noturno 04N11 SO
#include <stdio.h>
#include <string.h>



int main(void) {
  //exercicio 12
  char Str[100] = "orn*ito**rr*in**co*";
  char caracter = '*';

  printf("Palavra: %s\n", Str);
  int n = strlen(Str);
  for(int i=0; i<n; i++){
    if(Str[i] == caracter){
      Str[i] == '';
    }
  }

   printf("Palavra Modificada: %s\n", Str);
  
  return 0;
}