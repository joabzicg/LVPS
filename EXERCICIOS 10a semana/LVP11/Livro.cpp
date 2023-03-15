#include "Livro.h" // Incluindo arquivos de cabeçalho LVP09_CLIENTE.h e LVP09_MESA

Livro::Livro(string nome, string autor, string isbn, double preco, int ano){ // Construtor com parametros iniciais para os atributos
    this->nome = nome;
    this->autor = autor;
    this->isbn = isbn;
    this->preco = preco;
    this->ano = ano;
}

string Livro::getNome() const{ // Funções get para retornar valores dos atributos
    return nome;
}

void Livro::setAno(int ano){ // Funções set para setar valores dos atributos
    this->ano = ano;
}

void Livro::setAutor(string autor){
    this->autor = autor;
}

void Livro::setIsbn(string isbn){
    this->isbn = isbn;
}

void Livro::setNome(string nome){
    this->nome = nome;
}

void Livro::setPreco(double preco){
    this->preco = preco;
}

string Livro::getAutor() const{
    return autor;
}

string Livro::getIsbn() const{
    return isbn;
}

double Livro::getPreco() const{
    return preco;
}

int Livro::getAno() const{
    return ano;
}

Livro::~Livro(){ // Destrutor

}
