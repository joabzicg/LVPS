#ifndef LVP08_PEDIDO_H // Início do cabeçalho do arquivo LVP08_PEDIDO_H
#define LVP08_PEDIDO_H
struct Lista{ // Criando uma struct Lista para os dados dos Pedidos
    string nome;
    int quantidade;
    float valor_unitario, valor_total_produto;
};

class Pedido{ // Classe Pedido contendo os atributos e métodos necessários
    vector<Lista> pedidos; // Criando um vetor pedidos para o armazenamento dos dados em uma lista
    float valor_total_pedido; // Atributo para calcular o o valor total da lista de pedidos
public:
    Pedido(); // Construtor para definição inicial de variaveis
    void incluirProduto(Lista); // Método para incluir produto no vetor pedidos
    int retirarProduto(string); // Método para remover produto no vetor pedidos
    void calcularUnitario(string); // Método para calcular valor total de um produto pedido
    void calcularTotal(); // Método para calcular valor total da lista de pedidos
    float getTotal(); // Método para retornar o calculo do valor total da lista de pedidos
    void imprimirPedido(); // Método para impressão da lista de pedidos
};
#endif