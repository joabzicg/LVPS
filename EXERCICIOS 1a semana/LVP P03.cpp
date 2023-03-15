//Escreva uma função que receba um elemento real R e um elemento inteiro N (N≥ 0) e retorne o valor de RN (o cálculo da potência deve ser realizado por multiplicação sucessiva). 
//No programa principal, leia vários valores para R e N e chame a função para calcular a potência. O programa para quando for lido um valor negativo para N.
//Aluno: Joab da Silva Bezerra
//Matrícula: 121110972

#include <iostream>
#include <iomanip>

using namespace std;

float calculapot(long double real, int n);

int main(){ // Programa principal
    cout<< "Bem vindo ao programa. " << endl;
    int j=0;
    while (j >= 0){ // enquanto houver números positivos o programa rodará
        long double real, resultado;
        int n;
        cout<<"Digite um numero real: "<<endl;
        cin>>real;
        cout<<"Digite um elemento inteiro positivo N: "<<endl;
        cin>>n;
        if (n < 0){
            cout<<"O N eh menor que 0, o programa ira parar!"<<endl;
            j = -1;
            return 0;
        }
        resultado = calculapot(real, n);
        std::cout<<"O resultado da potencia eh: "<<std::fixed<<std::setprecision(5)<<resultado<<" !"<<endl;
    }
}
float calculapot(long double nreal, int npot){ // função para calcular potência.

    int i;
    long double somapot=1;

    for(i=1;i<=npot;i++){
        somapot *= nreal;
    }
    return somapot;
}