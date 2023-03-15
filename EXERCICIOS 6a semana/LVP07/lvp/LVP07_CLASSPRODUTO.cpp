#include "LVP07_PRODUTO.h"

Produto::Produto(){//Inicializa os atributos simples da classe Produto
    nome = "";
    quantidade = 0;
}

void Produto::setNome(string nome){ // Método para setar o nome de um objeto do tipo produto
    this->nome = nome;
}

void Produto::setQuantidade(int quantidade){ // Método para setar a quantidade de um objeto do tipo produto
     this->quantidade = quantidade;
}

int Produto::venderProduto(int venda){ // Método para a venda do produto
    if (venda <= quantidade){
        quantidade = quantidade-venda; // Será igual a quantidade - a quantidade venda, definida na main
    }
    else{
        return 0;
    }
    return 1;
}

string Produto::getNome(){ // Método que retorna a string do nome do Produto
    return nome;
}

int Produto::getQuantidade(){ // Método que retorna a quantidade do Produto
    return quantidade;
}