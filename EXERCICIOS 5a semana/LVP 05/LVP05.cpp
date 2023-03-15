#include "LVP05.h" // Incluindo arquivo da definição da classe
// Arquivo da definição dos métodos da classe

Horario::Horario(int hora, int minuto, int segundo){ // Construtor para atribuição dos dados de horario
    if (0<=hora && hora<24){ // Realizando testes para que a hora/minuto/segundo inserido fora da faixa correta seja substituido por 0
        this->hora = hora; // Inserindo valor de hora ao atributo
    }
    else {
        this->hora = 0;  }

    if (0<=hora && minuto<60){
        this->minuto = minuto; // Inserindo valor de minuto ao atributo
    }
    else {
        this->minuto = 0;
    }

    if (0<=segundo && segundo<60){
        this->segundo = segundo; // Inserindo valor de segundo ao atributo
    }
    else {
        this->segundo = 0;
    }
}

Horario::Horario(){ // Construtor para atribuição dos dados de horario a partir do sistema
    time_t t; // Utilização da biblioteca ctime para atribuição do horario a partir do sistema
    tm tempoSis;
    time(&t);
    tempoSis = *localtime(&t);  
    
    hora = tempoSis.tm_hour; // Atribuindo valor de hora ao atributo, a partir do sistema
    minuto = tempoSis.tm_min; // Atribuindo valor de minuto ao atributo, a partir do sistema
    segundo = tempoSis.tm_sec; // Atribuindo valor de segundo ao atributo, a partir do sistema
}

void Horario::setHora(int hora){ // Métodos set para atribuir os valores aos atributos, a partir da main.
    if (0<=hora && hora<24){
        this->hora = hora;
    }
    else{
        this->hora = 0;
    }
    
}

void Horario::setMinuto(int minuto){
    if (0<=minuto && minuto<60){
        this->minuto = minuto;
    }
    else{
        this->minuto = 0;
    }
}

void Horario::setSegundo(int segundo){
    if (0<=segundo && segundo<60){
        this->segundo = segundo;
    }
    else{
        this->segundo = 0;
    }
}

int Horario::getHora(){ // Métodos get para recepção dos valores dos atributos, a partir da main.
    return hora;
}

int Horario::getMinuto(){
    return minuto;
}

int Horario::getSegundo(){
    return segundo;
}

string Horario::converteString(){ // Método converteString para formatação do horario.
    return to_string(hora)+":"+to_string(minuto)+":"+to_string(segundo);
}

void Horario::adicionaSegundo(){ // Método para adicionar segundo ao horario 
    if(segundo == 59 && minuto == 59){ // Evitando valores errôneos ao adicionar o segundo ao horario
        minuto = 0;
        segundo = 0;
        hora++;
    }
    else if (segundo == 59){
        segundo = 0;
        minuto++;
    }
    else{
        segundo++;
    }
}