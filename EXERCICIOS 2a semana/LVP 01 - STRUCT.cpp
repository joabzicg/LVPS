/*
>Discente: Joab da Silva Bezerra
>Matrícula: 121110972
>Período: 21.1
>Curso: Engenharia Elétrica
>Disciplina: Técnicas de Programação
>Turma: 02
>Professor: Marcus Salerno
>Unidade 1: LVP 01 - STRUCT

Descrição do lvp : Escreva um programa que crie uma Struct chamada Triângulo, contendo os dois catetos e a hipotenusa. Declare 4 triângulos, leia os respectivos valores dos catetos
e calcule a hipotenusa de cada um. Apresente no final o valor da hipotenusa de cada triângulo, com precisão de duas casas decimais.
*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <locale>

using namespace std;

struct Triangulo { // criando struct
	float cateto_a, cateto_b, hipotenusa;
};
	
float multiplica (float, float); // prototipo da funcao

int main() { // funcao principal do programa

    setlocale(LC_ALL, "Portuguese");

	Triangulo triangulo[4];
    cout << "Bem vindo ao programa"<<endl;
    for(int i=0;i<4;i++){ // recebendo dados dos triangulos
        cout << "Digite o valor do cateto adjacente do triângulo "<< i + 1 <<endl;
        cin >> triangulo[i].cateto_a;
        cout << "Digite o valor do cateto oposto do triângulo " << i + 1 <<endl;
        cin >> triangulo[i].cateto_b;
        triangulo[i].hipotenusa = multiplica(triangulo[i].cateto_a, triangulo[i].cateto_b);
    }
    for (int b=0;b<4;b++){ // saida dos resultados
        cout << "O resultado da hipotenusa do triângulo "<< b + 1 <<" é: "<<endl;
        cout <<fixed<<setprecision(2)<< triangulo[b].hipotenusa<<" é: "<<endl;
    }

    return 0;
}

float multiplica (float catetoa, float catetob){ // Função para calcular a hipotenusa do triangulo
	float calctriang;
	
	calctriang = sqrt((catetoa * catetoa) + (catetob * catetob));

	return calctriang;
}