//Faça um programa que verifique se vários números inteiros positivos são palíndromos.
//O programa recebe vários inteiros positivos e para, quando encontra um inteiro zero ou negativo. Para cada inteiro recebido, emite uma mensagem informando se o número lido é ou não um palíndromo
//Aluno: Joab da Silva Bezerra 
//Matrícula: 121110972

#include <iostream>
using namespace std;

long long int num = 1; // declarando variaveis
long long veripalin(int);

int main (){ // Programa principal
    int j = 1;
    cout<< "Bem vindo ao programa" << endl;
    while (j > 0){ // enquanto o programa não receber um numero negativo, ele rodará.
        long long int copia;
        long long int invert = 0;
        cout<<"Digite um numero inteiro positivo: "<<endl; 
        cin>>num;
        copia = num;

        if (num < 0 ){ // verificando se o numero é palindromo
            j = -1;
            cout<<"O programa recebeu um numero menor que 0 e ira parar!"<<endl;
            return 0;
        }   
        while (num >0){ // invertendo o numero
            invert = invert*10+num%10;
            num = num/10;
        }
        if (invert == copia){ // verificando se o numero é palindromo
            cout<<"O numero eh palindromo."<<endl;
        }
        else {
            cout<<"O numero nao eh palindromo"<<endl;
        }
    }
    return 0 ;
}

