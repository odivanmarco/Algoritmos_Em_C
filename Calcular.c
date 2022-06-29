#include <stdio.h>

void calculadora(){
    char operador;
    int numero;
    int total = 0;
    while (operador != '=')
    {
        printf("\nDigite 1 para adição ");
        printf("\n       2 para subtração ");
        printf("\n       3 para multiplicação");
        printf("\n       4 para divisão");
        printf("\n       = para imprimir o resultado acumulado e sair");
        printf("\nOpção: ");
            setbuf(stdin,NULL);
            scanf("%c", &operador);
 
        if(operador == '='){
                printf("O total é: %i", total);
        }else {
                printf("Agora digite um número: ");
                    setbuf(stdin,NULL);
                    scanf("%i", &numero);
                if(operador == '1'){
                    total += numero;
                }
                else
                    if(operador == '2'){
                        total -= numero;
                }
                else 
                    if(operador == '3'){
                        total *= numero;
                }
                    if(operador == '4'){
                        total /= numero;
                }
            }
    }


}

int main(){

    calculadora();
    return 0;
}