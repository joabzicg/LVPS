#ifndef LVP08_PRODUTO_H // Início do cabeçalho do arquivo LVP08_PRODUTO_H
#define LVP08_PRODUTO_H

class Produto { // Criando uma classe chamada Produto, contendo os atributos nome, quantidade.
	string nome;
    int quantidade;
    double valor;
public:
    Produto(); // Construtor para posicionamento dos atributos iniciais.
    void setNome(string); // Método para setar o nome de um objeto do tipo produto
    void setQuantidade(int); // Método para setar a quantidade de um objeto do tipo produto
    void setValorU(double); // Método para setar o valor unitario de um objeto do tipo produto
    int venderProduto(int); // Método para a venda do produto, subtraindo com uma quantidade previamente definida
    string getNome(); // Método que retorna a string do nome do Produto
    int getQuantidade(); // Método que retorna a quantidade do Produto
    double getValorU(); // Método que retorna o valor unitario do Produto
};

#endif // LVP08_PRODUTO_H