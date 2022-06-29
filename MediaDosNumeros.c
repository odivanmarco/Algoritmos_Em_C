#include <stdio.h>


int main(){
  int numero = 0,contador = 0, total =0;
  int *cont;
  int *num;
  int *tot;
  num = &numero;
  cont = &contador;
  tot = &total;
  int option = 9;
  while(option != 0){
    printf("\nDigite 1 para executar o programa");
    printf("\nDigite 0 para sair do programa");
    printf("\nOpção: ");
      scanf("%i", &option);

  if (option == 1)
  {
      while(*num >= 0){
    printf("Digite um número: ");
      scanf("%i",num);
      if(*num>=0){
      *tot += *num;  
      *cont+=1;
      }
  }
  *tot = *tot/(*cont);
  
  printf("A média é: %i", *tot);
  }
  
  }
  printf("Saindo!!!");
return 0;
}
