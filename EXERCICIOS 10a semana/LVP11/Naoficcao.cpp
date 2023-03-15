#include "Naoficcao.h" // Incluindo arquivos de cabeçalho LVP09_CLIENTE.h e LVP09_MESA

Naoficcao::Naoficcao(string tipo, string tipomidia, int ranking){ // Construtor para valores iniciais dos atributos
    this->tipo= tipo;
    this->tipomidia= tipomidia;
    this->ranking = ranking;
}

string Naoficcao::getTipo() const{ // Métodos get para retornar os valores dos atributos
    return tipo;
}

void Naoficcao::setRanking(int ranking){ // Métodos set para colocação dos dados nos atributos
    this->ranking = ranking;
}

void Naoficcao::setTipo(string tipo){
    this->tipo = tipo;
}
void Naoficcao::setTipomidia(string tipomidia){
    this->tipomidia = tipomidia;
}

string Naoficcao::getTipomidia() const{
    return tipomidia;
}

int Naoficcao::getRanking() const{
    return ranking;
}

string Naoficcao::compararanking(int ranking){ // Método para comparar o ranking 
    if (ranking >= 1 && ranking <= 10){ // Caso o ranking esteja entre 1 e 10, o método retorna a string ótimo
        return "Ótimo";
    }
    if (ranking >= 11 && ranking <=20){ // Caso o ranking esteja entre 11 e 20, o método retorna a string muito bom
        return "Muito bom";
    }
    return "Não classificado"; // Caso esteja fora das outras opções, retorna a string "Não classificado"
}

Naoficcao::~Naoficcao(){ // Destrutor

}