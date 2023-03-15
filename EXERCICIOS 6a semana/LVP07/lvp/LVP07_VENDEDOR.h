#ifndef LVP07_VENDEDOR_H // Início do cabeçalho do arquivo LVP07_VENDEDOR_H
#define LVP07_VENDEDOR_H

class Vendedor { // Criando uma classe chamada Vendedor, contendo os atributos *produtos, do tipo Produto, tam, para definir o tamanho da lista, e n.
	Produto *produtos;
    int tam; // Atributo para o tamanho da lista
    int n; // Atributo para conseguir a posição na lista
public: 
    Vendedor(int); // Construtor para posicionamento dos atributos iniciais.
    ~Vendedor(); // Destrutor para excluir os dados após a utilização do programa
    void insere(Produto); // Método para inserir os objetos do tipo Produto em uma lista
    void pesquisaProduto(string); // Método para pesquisar uma string na lista contendo os Produtos
    void printLista(); // Método para imprimir a lista dos Produtos
    void venderProduto(string, int); // Método para a venda de produtos
};

#endif // LVP07_VENDEDOR_H