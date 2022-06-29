// Bibliotecas utilizadas
#include <stdio.h>
#include <string.h>

// struc Animal para representar os animaizinhos para adoção
typedef struct{
    char nome[15];
    int sexo;
    int tipo;
    float peso;
    int porte;
}Animal;

// Cria um animal, com todos os seus dados inserido do teclado
Animal criarAnimal(){
    Animal animal;
        printf("\nDigite os dados corretamente, por favor!\n");
        printf("\nNome: ");
            scanf("%s", animal.nome);
        printf("\nSexo: 1 = macho, 2 = femea\n");
            setbuf(stdin,NULL);
            scanf("%i", &animal.sexo);
        printf("\nTipo: 1 = cão, 2 = gato\n");
            scanf("%i", &animal.tipo);
        printf("\nPeso:");
            scanf("%f",&animal.peso);
        printf("\nPorte: 1 = pequeno, 2 = médio 3 = grande ");
            scanf("%i", &animal.porte);    
    return animal;
}
// vai dar ao usuário o poder de escolher algumas características
Animal animalEscolhido(){
    // Tipo animal para carregar alguns dados sobre o animal
    Animal animal; 
    printf("\nDigite os dados corretamente, por favor!\nQue tipo de animal vc está procurando?");
    // printf("\nNome: ");
    //     scanf("%s", animal.nome);
    printf("\nTipo: 1 = cão, 2 = gato\n");
        scanf("%i", &animal.tipo);
    printf("\nSexo: 1 = macho, 2 = femea\n");
        setbuf(stdin,NULL);
        scanf("%i", &animal.sexo);
    printf("\nPorte: 1 = pequeno, 2 = médio 3 = grande ");
        scanf("%i", &animal.porte);    
    // Será retornado para utilizar na comparação da função pesquisarAnimal
    return animal;
}

void cadastrarAnimalNoArquivo(int tamanho){
        // Cria um ponteiro de manipulação de arquivo
    FILE *arq;
    // Abre o arquivo para escrita
    arq = fopen("animais.txt", "w");
    Animal animal;
    for(int i=0; i<tamanho;i++){
        animal = criarAnimal();
        fprintf(arq,"%s", animal.nome);
        fprintf(arq," %i",animal.tipo);
        fprintf(arq," %i",animal.sexo);
        fprintf(arq," %.2f",animal.peso);
        fprintf(arq," %i\n",animal.porte);
    }
    fclose(arq);
}

Animal pesquisarAnimal(Animal *vetor,int tamanho){
    Animal escolhido;
    //Recebe uma variavel do tipo animal com as escolhas do usuário
    escolhido = animalEscolhido(); 
    // Esse *for* ercorre nosso vetor de animais, que é passado por referência
    for (int i = 0; i < tamanho; i++)
    {
        if (vetor[i].tipo == escolhido.tipo && (vetor[i].porte == escolhido.porte || vetor[i].sexo == escolhido.sexo)){
            printf("\nO animal %s é perfeito para você de acordo com suas escolhas", vetor[i].nome);
        }   
    }
}

// Essa função é a que carrega s dados do arquivo para o vetor de registros
void preencheVetorComDadosDoArquivo(Animal *vetor, int tamanho){
    // Cria um ponteiro de manipulação de arquivo
    FILE *arq;
    // Abre o arquivo para leitura
    arq = fopen("animais.txt", "r");
        // Percorre o vetor carregado nas variaveis os valores presentes no arquivo
        for(int i=0; i<tamanho; i++){        
            fscanf(arq,"%s", vetor[i].nome);
            fscanf(arq,"%i", &vetor[i].tipo);
            fscanf(arq,"%i", &vetor[i].sexo);
            fscanf(arq,"%f", &vetor[i].peso);
            fscanf(arq,"%i", &vetor[i].porte);    
        }
    fclose(arq);
}
// Imprime nosso vetor de animais
void imprimeVetorComDadosDoArquivo(Animal *vetor, int tamanho){
    printf("Animais para adoção\n");
    printf("\nTipo: 1 = cão, 2=gato");    
    printf("\nSexo: 1 = macho, 2 = femea");
    printf("\nPorte: 1 = pequeno, 2 = media, 3 = grande\n");
    // Percorre o vetor
    for (int i = 0; i < tamanho; i++)
    {
        printf("\n\nNome: %s", vetor[i].nome);
        printf("\nTipo: %i",vetor[i].tipo);
        printf("\nSexo: %i",vetor[i].sexo);
        printf("\nPeso: %.2f Kg",vetor[i].peso);
        printf("\nPorte: %i",vetor[i].porte);
    }
    
}

int main(){
    // Quantidade de cadastros que irá realizar
    int quantos_cadastros;
        printf("Quantos cadastros quer realizar?");
            scanf("%i", &quantos_cadastros);
    // Cria vetor vazio de structs do tipo Animal
    Animal adocao[quantos_cadastros];

    // Chamada das funções criadas acima
    cadastrarAnimalNoArquivo(quantos_cadastros);
    preencheVetorComDadosDoArquivo(adocao, quantos_cadastros);
    imprimeVetorComDadosDoArquivo(adocao, quantos_cadastros);
    pesquisarAnimal(adocao, quantos_cadastros);

    return 0;
}