#include <stdio.h>

typedef struct{
  int dia;
  int mes;
  int ano;
}Data;

int bissexto (int ano) {
	return (ano % 4 == 0) && ((ano % 100 != 0) || (ano % 400 == 0));
}

int dias_mes[2][13] = {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                       {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

unsigned long dist_dias (Data inicio, Data fim) {
	unsigned long idias, fdias;	/* guarda qtos dias tem da data */
					/* ate o comeco do ano */
	unsigned long def_anos = 0;	/* guarda diferenca entre anos das */
					/* datas inicio e fim medida em dias */
	register int i;
	int dbissexto;

	idias = inicio.dia;
	dbissexto = bissexto (inicio.ano);
	for (i = inicio.mes - 1; i > 0; --i)
		idias += dias_mes[dbissexto][i];

	fdias = fim.dia;
	dbissexto = bissexto (fim.ano);
	for (i = fim.mes - 1; i > 0; --i)
		fdias += dias_mes[dbissexto][i];

	while (inicio.ano < fim.ano)
		def_anos += 365 + bissexto(inicio.ano++);

	return def_anos - idias + fdias;
}


int main(void) {
Data inicio,fim;
int option=9;
while(option != 0){
    printf("\n Digite um para executar o programa");
    printf("\n Digite 0 para encerrar");
    printf("\nOpção: ");
      scanf("%i", &option);
		if(option == 1){
		printf("Qual a data inicial?");
		scanf("%i/%i/%i", &inicio.dia, &inicio.mes, &inicio.ano);
		printf("Qual a data final?");
		scanf("%i/%i/%i", &fim.dia, &fim.mes, &fim.ano);

		printf("A distancia em dias: %lu\n", dist_dias(inicio, fim));
		}
}
printf("Saindo!!!");
  
  return 0;
}

