/*
>Discente: Joab da Silva Bezerra
>Matrícula: 121110972
>Período: 21.1
>Curso: Engenharia Elétrica
>Disciplina: Técnicas de Programação
>Turma: 02
>Professor: Marcus Salerno
>Unidade 1: LVP 06
>Compilado e programado no Visual Studio Code

Descrição do lvp : Um programa que calcula o valor de estacionamento para carros, utilizando-se de 3 arquivos.
*/

#include <iostream> // Biblioteca para entrada e saída de dados
#include <cmath> // Biblioteca para funções matemáticas
#include <locale> // Biblioteca para o idioma português 
#include <cstring> // Biblioteca para uso de strings

using namespace std;

#include "LVP06_class.cpp" // Incluindo arquivo com as classes definidas

int main(){
    setlocale(LC_ALL, "Portuguese"); // Iniciação do idioma português

    Hora hora_e, hora_s; // Variaveis temporarias para a entrada de dados na classe
    string placa, nome; 

    Estacionamento carro1; // Instaciando objeto carro1 na classe Estacionamento

    cout<<"Bem vindo ao programa!"<<endl;
    cout<<"Digite a placa do veículo: "<<endl; // Conjunto de Couts para entrada de dados nas variáveis temporárias
    getline(cin, placa);
    cout<<"Digite o nome do condutor do veículo: "<<endl;
    getline(cin, nome);
    cout<<"Digite o horário de entrada do veículo no estacionamento\nDa seguinte forma: horas (dê enter), minutos (dê enter), segundos (dê enter) : "<<endl;
    cin>>hora_e.hora;
    cin>>hora_e.minuto;
    cin>>hora_e.segundo;
    cout<<"Digite o horário de saída do veículo no estacionamento\nDa seguinte forma: horas (dê enter), minutos (dê enter), segundos (dê enter) : "<<endl;
    cin>>hora_s.hora;
    cin>>hora_s.minuto;
    cin>>hora_s.segundo;
    
    carro1.set_dados(placa, nome); // Entrando com dados na classe via método set
    carro1.set_horas(hora_e, hora_s);

    cout<<"Placa: "<<carro1.get_placa()<<endl; // Pegando valores da classe pelo método get
    cout<<"Nome do Proprietário: "<<carro1.get_nome()<<endl;
    cout<<"Horas ocupadas: "<<carro1.get_horas()<<endl;
    cout<<"Valor a ser pago: R$"<<carro1.calculavalor()<<endl; 
    
    return 0;
}