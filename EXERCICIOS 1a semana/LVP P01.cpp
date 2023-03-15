//Aluno: Joab da Silva Bezerra
//Matrícula: 121110972
// Faça um programa que leia 10 inteiros positivos e mostre, no final, a soma dos números pares e a soma dos números ímpares
#include <iostream>
using namespace std;

int main()

{
	int i, num = 0;
	float somaPar = 0;
	float somaImpar = 0; // Recebendo os números 
	cout << "Bem vindo ao programa. " << endl;
	
    cout<<("Digite 10 numeros ( a cada numero inserido aperte enter):" )<<endl;
    for(i=0;i<=9;i++){
        cin >> num;
		if (num%2 != 0){
			somaImpar += num;
		}
		else {
			somaPar += num;
		}
	}

	cout << "A soma dos numeros pares eh : " << somaPar << endl <<"A soma dos numeros impares eh : " << somaImpar;


	return 0;
}

