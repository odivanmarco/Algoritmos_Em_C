#include <stdio.h>

typedef struct
{
    float peso;
    float altura;
    float imcC;
}IMC;


int main(){
    int tamanho = 4;
    IMC imc[tamanho];
    
char option;
while(option != '0'){
    printf("\nDigite 1 para registrar os dados!");
    printf("\nDigite 2 para listar os dados (apenas se estiver cadastrado antes) !");
    printf("\nDigite 3 para calcular os IMCs");
    printf("\nDigite 0 para encerrar o programa!");
    printf("\nOpção: ");
    scanf(" %c", &option);  

    if (option == '1')
    {
        for(int i=0; i<tamanho; i++){
            printf("Digite o seu peso: ");
                scanf("%f", &imc[i].peso);
            printf("Digite a sua altura: ");
                scanf("%f", &imc[i].altura);
                setbuf(stdin,NULL);
    }
    }
    
     if (option == '2')
    {
        for (int i = 0; i < tamanho; i++)
        {
            printf("\nPeso: %.2f", imc[i].peso);
            printf("\nAltura: %.2f", imc[i].altura);
            setbuf(stdin,NULL);
        }   
    }

    if(option == '3'){
        for (int i = 0; i < tamanho; i++)
        {   
            imc[i].imcC = imc[i].peso/(imc[i].altura * imc[i].altura);
            printf("\nO IMC da pessoa %i é: %.2f", i+1, imc[i].imcC);
        }
    }

    if (option == '0')
    {
        printf("Saindo");
    }
}   
    

    return 0;
}