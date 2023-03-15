#include "LVP09_CLIENTE.h" // Incluindo arquivos de cabeçalho LVP09_CLIENTE.h e LVP09_MESA
#include "LVP09_MESA.h"

Cliente::Cliente(string nome, int codigo, int numeropessoas){//Construtor que inicializa as o objeto Cliente com os dados iniciais.
    this->nome = nome;
    this->codigo=codigo;
    this->numeropessoas= numeropessoas;
}\

void Cliente::set_nome(string nome){ // Métodos para setar atributos da classe Cliente
    this->nome = nome;
}

void Cliente::set_acompanhantes(int acompanhantes){ 
    numeropessoas = acompanhantes;
}

void Cliente::set_codigo(int cod){
    codigo = cod;
}

string Cliente::get_nomecliente() const{ // Métodos para retornar atributos da classe Cliente
    return nome;
}

int Cliente::get_numeropessoas() const{
    return numeropessoas;
}

int Cliente::get_codigo() const{
    return codigo;
}

