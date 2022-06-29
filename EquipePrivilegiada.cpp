#include <iostream>
using namespace std;

int main(){
    int quantEntrevistados;
    char privilegiada;
    int ferrari = 0, mercedes = 0, redbull = 0, outro=0;
    cout << "Quantos serão os entrevistados? " <<endl;
        cin >> quantEntrevistados;
    for (int i = 0; i < quantEntrevistados; i++)
    {
        cout << "Na sua opinião qual equipe foi mais privilegiada" <<endl;
        cout << " F = Ferrari, R = Red Bull e M= Mercedes"<<endl;
            cin >> privilegiada;
            privilegiada = toupper(privilegiada);
        if (privilegiada == 'F')
        {
            ferrari++;
        }else
        if (privilegiada == 'R')
        {
            redbull++;
        }else
        if (privilegiada == 'M')
        {
            mercedes++;
        }else
        {
            outro++;
        }
    }

    cout << "Opinões a favor da equipe Ferrari: " << ferrari <<endl;
    cout << "Opinões a favor da equipe Mercedes: " << mercedes  <<endl;
    cout << "Opinões a favor da equipe Redbull: " << redbull <<endl;

    if(outro > (ferrari + mercedes + redbull)){
        cout <<  "Outra equipe privilegiada: " << outro <<endl;
    }

    return 0;
}