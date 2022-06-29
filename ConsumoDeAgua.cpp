#include <iostream>
#include <string>
using namespace std;

int main(){
    float consumo;
    int ano;
    string meses[] = {"janeiro","fevereiro", "março", "abril","maio","junho", "julho","agosto","setembro","outubro","novembro","dezembro"};
    int numero_mes;
    while (true){
        cout << "Quantos metros quadrados de água você costuma gastar?" <<endl;
            cin >> consumo;
        if (consumo>=0)
            break;
        else
            cout << "Digite um valor não negativo por favor" <<endl;    
    }

    cout << "Digite o número do mês" <<endl;
        cin >> numero_mes;
    cout <<"Agora digite o ano:";
        cin >> ano;    
    cout <<"No mês de " << meses[numero_mes-1] << "\nNo ano de: " << ano <<endl;  
    if((ano % 400 == 0) || ( (ano % 4 == 0) && (ano % 100 != 0) )){
        cout << "Bissexto" << endl;
    }
    else{
        cout << "Não é bissexto" << endl;
    }
    cout << "Seu consumo foi de: " << consumo <<endl;  
    if(consumo <= 2.1){
        cout << "Categoria de consumo: BAIXO" <<endl;
    }
    if(consumo > 2.1 && consumo <= 6.1){
        cout << "Categoria de consumo: NORMAL" <<endl;
    }
    if (consumo > 6.1 && consumo <= 10.5){
        cout << "Categoria de consumo: ALTO" <<endl;
    }
    if (consumo > 10.5){
        cout << "Categoria de consumo: EXAGERADO" <<endl;
    }
    return 0;
}