#include "Ficcao.h" // Incluindo arquivos de cabeçalho LVP09_CLIENTE.h e LVP09_MESA

Ficcao::Ficcao(string tipoficcao, string narrativa){ // Construtor com parametros iniciais para os atributos
    this->tipoficcao = tipoficcao;
    this->narrativa = narrativa;
}

void Ficcao::setTipoficcao(string tipoficcao){ // Métodos para setar valores dos atributos
    this->tipoficcao = tipoficcao;
}

void Ficcao::setNarrativa(string narrativa){
    this->narrativa = narrativa;
}

string Ficcao::getTipoficcao() const{ // Métodos para retornar valores dos atributos
    return tipoficcao;
}

string Ficcao::getNarrativa() const{
    return narrativa;
}

Ficcao::~Ficcao(){ // Destrutor

}

