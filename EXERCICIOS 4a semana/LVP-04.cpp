/*
>Discente: Joab da Silva Bezerra
>Matrícula: 121110972
>Período: 21.1
>Curso: Engenharia Elétrica
>Disciplina: Técnicas de Programação
>Turma: 02
>Professor: Marcus Salerno
>Unidade 1: LVP 04
>Compilado e programado no Visual Studio Code

Descrição do lvp : Um programa que calcula dados sobre dois corpos celestes.
*/

#include <iostream>  // Biblioteca para saída e entrada de dados 
#include <iomanip> // Biblioteca para manipulação da saída de dados 
#include <locale> // Biblioteca para a ativação do idioma portuguese 
#include <cmath> //  Biblioteca com funções matemáticas

using namespace std;

struct CorpoCeleste{ // Struct para criar um tipo CropoCelestes para os corpos.
    string nome;
    double raioPlaneta, massa;
};

class Sistema_Interestelar{ // Classe com atributos e métodos do sistema interestelar. 
    private:
        CorpoCeleste corpo1, corpo2;
        double distancia, forca_g, campo_g, vel_orb, vel_escape;
        const double constante;
    public:
        Sistema_Interestelar(CorpoCeleste, CorpoCeleste, double); // Construtor para receber dados dos dois corpos celestes
        bool ComparaMassa(); // Método para comparar a massa entre os planetas
        void calcula_Campo(); // Método para calcular o campo gravitacional do planeta de maior massa
        void calcula_Forca(); // Método para calcular a força gravitacional entre os planetas
        void calcula_VelocidadeEscape(); // Método para calcular a velocidade de escape em relação ao corpo de maior massa
        void calcula_VelocidadeOrbita(); // Método para calcular a velocidade em orbita do corpo de massa menor em relação ao corpo de maior massa;
        double get_Campo(); // Método para retornar o valor do campo gravitacional do planeta de maior massa
        double get_Forca(); // Método para retornar o valor da força gravitacional entre os planetas
        double get_VelocidadeEscape(); // Método para retornar a velocidade de escape em relação ao corpo de maior massa
        double get_VelocidadeOrbita(); // Método para retornar a velocidade em orbita do corpo de massa menor em relação ao corpo de maior massa;
        ~Sistema_Interestelar(); // Destrutor para destruir os objetos.
};

Sistema_Interestelar::Sistema_Interestelar(CorpoCeleste corpo1, CorpoCeleste corpo2, double distancia) : constante(6.67e-11){ // Construtor para definir os valores iniciais das variaveis.
    this->distancia = distancia;
    this->corpo1.nome = corpo1.nome;
    this->corpo1.raioPlaneta = corpo1.raioPlaneta;
    this->corpo1.massa = corpo1.massa;
    this->corpo2.nome = corpo2.nome;
    this->corpo2.raioPlaneta = corpo2.raioPlaneta;
    this->corpo2.massa = corpo2.massa;
} 


Sistema_Interestelar::~Sistema_Interestelar(){ // Destrutor
    cout << "************ MENSAGEM DO DESTRUTOR *************"<<endl;
}


bool Sistema_Interestelar::ComparaMassa(){ // Método para comparar massa dos corpos
    if (corpo1.massa > corpo2.massa){
        return true;
    }
    return false;
}

void Sistema_Interestelar::calcula_Forca(){ // Métodos para calcular os valores, de força, campo gravitacional, velocidade de órbita e velocidade de escape
    forca_g = constante*((corpo1.massa*corpo2.massa)/(pow(distancia, 2)));
}

void Sistema_Interestelar::calcula_Campo(){
    if (ComparaMassa() == 1){
        campo_g = constante*((corpo1.massa)/(pow(corpo1.raioPlaneta, 2)));
        return;
    }
    else {
        campo_g = constante*((corpo2.massa)/(pow(corpo2.raioPlaneta, 2)));
        return;
    }
}

void Sistema_Interestelar::calcula_VelocidadeOrbita(){

    if (ComparaMassa() == 1){
        vel_orb = (sqrt(constante*((corpo1.massa)/(distancia))))/1000;
        return;
    }
    else {
        vel_orb = (sqrt(constante*((corpo2.massa)/(distancia))))/1000;
        return;
    }

}

void Sistema_Interestelar::calcula_VelocidadeEscape(){
    if (ComparaMassa() == true){
        vel_escape = (sqrt((2*constante*((corpo1.massa)/(corpo1.raioPlaneta)))))/1000;
        return;
    }
    else {
        vel_escape = (sqrt((2*constante*((corpo2.massa)/(corpo2.raioPlaneta)))))/1000;
        return;
    }
}

double Sistema_Interestelar::get_Campo(){ // Métodos para retornar os valores calculados.
    return campo_g;
}

double Sistema_Interestelar::get_Forca(){
    return forca_g;
}

double Sistema_Interestelar::get_VelocidadeEscape(){
    return vel_escape;
}

double Sistema_Interestelar::get_VelocidadeOrbita(){
    return vel_orb;
}

int main(){ // Função principal para a entrada de dados, chamadas de funções de calculo e impressão dos resultados.
    setlocale(LC_ALL,"Portuguese"); // ativação do idioma português para os Couts

    CorpoCeleste corpo_1, corpo_2; // Variáveis temporárias para a guarda de dados
    double distancia;

    cout << "Bem vindo ao programa." << endl; // Conjunto de couts para entrada de dados 
    cout << "******* PREENCHA OS DADOS DOS CORPOS CELESTES *******o " << endl<< "***************** CORPO  CELESTE 1 *****************"<<endl;
    cout << "Nome:"<<endl;
    cin >> corpo_1.nome;
    cout << "Massa:"<<endl;
    cin >> corpo_1.massa;
    cout << "Raio: "<<endl;
    cin >> corpo_1.raioPlaneta;
    cout << "***************** CORPO  CELESTE 2 *****************"<<endl<<"Nome: "<<endl;
    cin >> corpo_2.nome;
    cout << "Massa:"<<endl;
    cin >> corpo_2.massa;
    cout << "Raio: "<<endl;
    cin >> corpo_2.raioPlaneta;
    cout << "Digite a distância entre os corpos: "<<endl;
    cin >> distancia;

    Sistema_Interestelar sistema1(corpo_1, corpo_2, distancia); // Criando objeto sistema1 na classe  Sistema_Interestelar


    sistema1.ComparaMassa(); // Chamando funções para calcular os valores
    sistema1.calcula_Campo();
    sistema1.calcula_Forca();
    sistema1.calcula_VelocidadeEscape();
    sistema1.calcula_VelocidadeOrbita();

    cout << "A força gravitacional é: "<<fixed<<scientific<<setprecision(2)<<sistema1.get_Forca()<<" N"<< endl; // Conjunto de couts para impressão dos resultados
    cout << "O campo gravitacional do maior corpo celeste é : "<<fixed<<scientific<<setprecision(2)<<sistema1.get_Campo()<< " m/s²"<<endl;
    cout << "A velocidade de escape do maior corpo é: : "<<fixed<<scientific<<setprecision(2)<<sistema1.get_VelocidadeEscape()<<" km/s"<<endl;
    cout << "A velocidade em orbita do menor corpo em relação ao maior é "<<fixed<<scientific<<setprecision(2)<<sistema1.get_VelocidadeOrbita()<<" km/s"<<endl;
    return 0;
}