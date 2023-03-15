#ifndef LVP08_VENDEDOR_H // Início do cabeçalho do arquivo LVP08_VENDEDOR_H
#define LVP08_VENDEDOR_H

class Vendedor { // Criando uma classe chamada Vendedor, contendo um atributo produtos do tipo vector.
	vector<Produto> produtos; // Criando um vetor produtos para o armazenamento dos dados dos produtos
public: 
    Vendedor(); // Construtor para posicionamento dos atributos iniciais.
    void insere(Produto); // Método para inserir os objetos do tipo Produto em uma lista
    bool pesquisaProduto(string); // Método para pesquisar uma string na lista contendo os Produtos
    void printLista(); // Método para imprimir a lista dos Produtos
    void venderProduto(string, int); // Método para a venda de produtos
    bool retirarQPedido(string, int); // Método para retirar a quantidade feita em um pedido
    void VoltaQntPedido(string, int); // Método para voltar a quantidade original depois de removido o pedido
    float getValorU(string); // Método para retornar valor unitario de um produto
};

#endif // LVP08_VENDEDOR_H