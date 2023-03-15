/*
>Discente: Joab da Silva Bezerra
>Matrícula: 121110972
>Período: 21.1
>Curso: Engenharia Elétrica
>Disciplina: Técnicas de Programação
>Turma: 02
>Professor: Marcus Salerno
>Unidade 1: LVP 05
>Compilado e programado no Visual Studio Code

Descrição do lvp : Um programa que exibe o horario formatado em horas, minutos e segundos, utilizando-se de 3 arquivos.
*/

#include <iostream> // Biblioteca para entrada e saída de dados
#include <locale> // Biblioteca para o idioma português 
#include <cstring> // Biblioteca para uso de strings
#include <ctime> // Biblioteca para pegar o horário do sistema

using namespace std;

#include "LVP05.cpp"  // Incluindo arquivo com as classes definidas

int main(){
    setlocale(LC_ALL,"Portuguese"); // Iniciação do idioma português

    Horario hor1(22,59,59), hor2(8,60,50), hor3(70,23,49), hor4(20,50,60), hor5, hor6; // Instaciando objetos na classe Horario
    int hora, minuto, segundos; // Variaveis temporarias para o teste dos métodos get e set

    cout<<"---Testandos métodos da classe---\nHorário no primeiro objeto com o método converteString:"<<endl<<hor1.converteString()<<endl; // Conjunto de Couts para teste do métood converteString
    cout<<"Horário no segundo objeto (Com os minutos acima de 60):"<<endl<<hor2.converteString()<<endl;
    cout<<"Horário no terceiro objeto (Com as horas acima de 24): "<<endl<<hor3.converteString()<<endl;
    cout<<"Horário no quarto objeto (com segundo acima de 60): "<<endl<<hor4.converteString()<<endl;
    cout<<"Horário no quarto objeto (Horário dado pelo sistema): "<<endl<<hor5.converteString()<<endl;

    for(int i=0;i<2;i++){ // Laço de repetição para adicionar um total de 2 segundos ao objeto hor1
        hor1.adicionaSegundo(); // Chamando a função para adicionar 1 segundo ao objeto hor1
    }

    cout<<"\nHorário no primeiro objeto acrescido de 2 segundos:"<<endl<<hor1.converteString()<<endl;

    // Preenchimento das Variaveis temporarias para o teste dos métodos get e set
    hora = 20;
    minuto = 30;
    segundos = 23;

    hor6.setHora(hora);
    hor6.setMinuto(minuto);
    hor6.setSegundo(segundos); // Testando métodos set

    cout<<"\nHorário no objeto com hora, minutos e segundos setados:"<<endl<<hor6.converteString()<<endl; // Testando métodos get
    cout<<"Hora no objeto com o método get: "<<hor6.getHora()<<endl<<"Minutos com método get: "<<hor6.getMinuto()<<endl<<"Segundos com método get: "<<hor6.getSegundo()<<endl;
    return 0;
}

