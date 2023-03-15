/*
>Discente: Joab da Silva Bezerra
>Matrícula: 121110972
>Período: 21.1
>Curso: Engenharia Elétrica
>Disciplina: Técnicas de Programação
>Turma: 02
>Professor: Marcus Salerno
>Unidade 1: LVP 02 - UNION

Descrição do lvp : Escreva um programa que converta uma velocidade, recebida como entrada do usuário, para uma determinada unidade. 
*/

#include <iostream>
#include <iomanip>
#include <locale>

using namespace std;

union velocidade {
    float ms, kmh, mh;

};

int main(){
    int opcao;
    velocidade vel;

    setlocale(LC_ALL, "Portuguese");
    
    cout<<"Bem vindo ao programa"<<endl;;
    cout<<"Digite um numero para conversão de: \n 1. De km/h para m/s \n 2. De m/s para km/h \n 3. De m/h para km/h"<<endl;
    cin>>opcao;

    switch(opcao){
    case 1:

        cout<<"Digite o valor da velocidade em km/h:"<<endl;
        cin>>vel.kmh;
        vel.ms = vel.kmh/3.6;
        cout<<"O valor da velocidade em m/s é igual a: "<<fixed<<setprecision(2)<<vel.ms<<" m/s"<<endl;
        break;

    case 2:

        cout<<"Digite o valor da velocidade em m/s:"<<endl;
        cin>>vel.ms;
        vel.kmh = vel.ms*3.6;
        cout<<"O valor da velocidade em m/s é igual a: "<<fixed<<setprecision(2)<<vel.ms<<" km/h"<<endl;
        break;

    case 3:

        cout<<"Digite o valor da velocidade em m/h:"<<endl;
        cin>>vel.mh;
        vel.kmh = vel.mh/1000;
        cout<<"O valor da velocidade em km/h é igual a: "<<fixed<<setprecision(2)<<vel.kmh<<" km/h"<<endl;
        break;


    default:
    
        cout<<"Opção invalida, tente novamente!"<<endl;
        break;

    }

    return 0;
}