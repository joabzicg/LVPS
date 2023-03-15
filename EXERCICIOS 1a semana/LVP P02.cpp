// Escreva um programa que leia um conjunto inteiro de 10 elementos e um valor para ser pesquisado neste conjunto.
//O programa informará se o valor pesquisado está presente ou não no conjunto. Utilizará uma função para ler o conjunto e utilizará uma função para fazer a pesquisa. 
//A função quando encontra o valor procurado, retorna a posição do valor no conjunto e retorna -1, caso o valor não seja encontrado.
//Nome: Joab da Silva Bezerra
//Matrícula: 121110972
#include <iostream>

using namespace std;

void lerConjunto(int []);
int procura(int [], int);

int main(){ // Programa principal
    cout<<"Bem vindo ao programa" << endl;
    int v[10], valor, valorproc;
    lerConjunto(v);
    cout<<"Digite um numero a ser procurado na lista: "<<endl;
    cin>>valor;
    valorproc = procura(v, valor);
    if (valorproc==-1)
        cout<<"O valor procurado nao existe! "<<endl;
    else
        cout<<"O valor procurado esta na posicao: "<<valorproc<<endl;     
    return 0;
}

void lerConjunto(int vetor[]){ // função para ler um conjunto de numeros
    int i;
    cout<<("Digite 10 numeros ( a cada numero inserido aperte enter):" )<<endl;
    for(i=0;i<=10;i++)
        cin>>vetor[i];

}

int procura(int vetor[], int posicao){ // função para realizar a procura do número escolhido
    int i;
	for (i=0;i<20;i++)
		if (vetor[i]==posicao)
			return i;
    return -1;
}