#include <stdio.h>

void existeOuNao(char *vetorP, char *cp){
  int existe;
  for(int i=0; i<13; i++){
    if(*vetorP == *cp){
      existe = 1;
    }
    vetorP++;
  }

  if(existe == 1){
    printf("EXISTE");
  }
  else{
    printf("NÂO EXISTE");
  }
}

int main(){
  char c;
  char *cp;
  cp = &c;

  char vetorChar[13] = {'b','d','f','h','j','l','m','o','q','s','u','w','y'};
  char *vetorP;
    vetorP = vetorChar;
  int existe = 0;

  int option;
  while(option != 0){
  printf("\n Digite 1 para executar o programa");
  printf("\n Digite 0 para encerrar");
  printf("\nOpção: ");
    scanf("%i", &option);

  if (option == 1){
  printf("Digite a letra que deseja procurar no vetor: ");
    setbuf(stdin,NULL);
    scanf("%c", cp);
    existeOuNao(vetorChar, cp);
  }

  }
  printf("Saindo !!!");
  return 0;
}