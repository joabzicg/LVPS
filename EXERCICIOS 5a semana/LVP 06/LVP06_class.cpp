#include "LVP06.h" // Incluindo cabeçalho LVP06.h

Estacionamento::Estacionamento(){ // Setando atributos iniciais com o construtor
    placa = "";
    nome = "";
    hora_e.hora = 0;
    hora_e.minuto = 0;
    hora_e.segundo = 0;
    hora_s.hora = 0;
    hora_s.minuto = 0;
    hora_s.segundo = 0;
    valor_h = 1.50;
};

void Estacionamento::set_dados(string placa, string nome){ // Recebendo dados da placa, do nome e do horario pelo método set, e colocando nos devidos atributos
    this->placa = placa;
    this->nome = nome;
}

void Estacionamento::set_horas(Hora hora_e, Hora hora_s){
    this->hora_e.hora = hora_e.hora;
    this->hora_e.minuto = hora_e.minuto;
    this->hora_e.segundo = hora_e.segundo;
    this->hora_s.hora = hora_s.hora;
    this->hora_s.minuto = hora_s.minuto;
    this->hora_s.segundo = hora_s.segundo;
}

string Estacionamento::get_placa(){ // Métodos get para retorno de valores 
    return placa;
}

string Estacionamento::get_nome(){
    return nome;
}

double Estacionamento::get_horas(){ // Método que converte e retorna o total de horas que o carro esteve no estacionamento
    hora_convertida = double((((hora_s.hora*3600)+(hora_s.minuto*60)+(hora_s.segundo))-((hora_e.hora*3600)+(hora_e.minuto*60)+(hora_e.segundo))))/3600;
    hora_convertida = ceil(hora_convertida);
    return hora_convertida;
}

double Estacionamento::calculavalor(){ // Método para calcular o custo do estacionamento.
    custo = hora_convertida*valor_h;
    return custo;
}
