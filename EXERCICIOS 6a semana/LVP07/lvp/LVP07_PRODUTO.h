#ifndef LVP07_PRODUTO_H // Início do cabeçalho do arquivo LVP07_PRODUTO_H
#define LVP07_PRODUTO_H

class Produto { // Criando uma classe chamada Produto, contendo os atributos nome, quantidade.
	string nome;
    int quantidade;
public:
    Produto(); // Construtor para posicionamento dos atributos iniciais.
    void setNome(string); // Método para setar o nome de um objeto do tipo produto
    void setQuantidade(int); // Método para setar a quantidade de um objeto do tipo produto
    int venderProduto(int); // Método para a venda do produto, subtraindo com uma quantidade previamente definida
    string getNome(); // Método que retorna a string do nome do Produto
    int getQuantidade(); // Método que retorna a quantidade do Produto
};

#endif // LVP07_PRODUTO_H