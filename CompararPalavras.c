#include <stdio.h>
  
int main(){
char palavra1[20],palavra2[20];
char *str1; 
char *str2;
  str1 = palavra1;
  str2 = palavra2;

int option = 9;
while(option != 0){
    printf("\n Digite 1 para executar o programa");
    printf("\n Digite 0 para encerrar");
    printf("\nOpção: ");
        scanf("%i", &option);
    if (option == 1){
      printf("Digite a primeira palavra: ");
        scanf("%s", palavra1);
      printf("Digite a segunda palavra: ");
        scanf("%s", palavra2);
      int iguais = 0;
        while (*str1 == *str2)
        {
            if (*str1 == '\0' && *str2 == '\0')
                iguais = 1;
            str1++;
            str2++;
        }      
      if(iguais == 1){
        printf("IGUAIS");
      }else{
        printf("DIFERENTES");
      }
    }
}
printf("Saindo!!!");
  return 0;
}
