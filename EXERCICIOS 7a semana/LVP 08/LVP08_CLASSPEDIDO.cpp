#include "LVP08_PEDIDO.h"

Pedido::Pedido(){//Inicializa os atributos simples da classe Produto
valor_total_pedido = 0;
}

void Pedido::incluirProduto(Lista pedido){
    pedidos.push_back(pedido); // Adicionando o pedido a ultima posição do vetor.
}


void Pedido::retirarProduto(string nome){ // Método para remoção de pedidos da lista.
    for(unsigned i(0); i < pedidos.size(); i++){ // Repetindo para a lista com n pedidos
        if (nome == pedidos[i].nome){ // Caso a string carregada da main seja igual a contida no pedido de posição i do vetor:
            pedidos.erase(pedidos.begin()+i); // Irá excluir o pedido da posição i
            cout<<"Produto removido!"<<endl;
            return; // Para quebrar o for.
        }
    }
    cout<<"Produto não encontrado!"<<endl; 
}


void Pedido::calcularUnitario(string produto){ // Método para calcular o custo de um especifico pedido.
    for(unsigned i(0); i < pedidos.size(); i++){ // Repetindo para a lista com n pedidos
        if (produto == pedidos[i].nome){ // Caso a string carregada da main seja igual a contida no pedido de posição i do vetor:
            pedidos[i].valor_total_produto = pedidos[i].quantidade*pedidos[i].valor_unitario; // Irá carregar no struct peddios[i] o valor unitario do pedido
            cout<<fixed<<setprecision(2)<<"O valor total será de: R$ "<<pedidos[i].valor_total_produto<<endl; // Cout para exibição
            return;
        }
    }
    cout<<"Produto não encontrado!"<<endl;
}

void Pedido::calcularTotal(){ // Método para calcular o custo total da lista de pedidos.
    valor_total_pedido = 0; // Iniciando a soma com 0.
    for(unsigned i(0); i < pedidos.size(); i++){ // Repetindo para a lista com n pedidos
        pedidos[i].valor_total_produto = pedidos[i].quantidade*pedidos[i].valor_unitario; // Calculando valor total de um unico pedido
        valor_total_pedido += pedidos[i].valor_total_produto;  // Armazenando a soma de um pedido
    }
}

float Pedido::getTotal(){ // Método para retornar o valor total em R$ da lista de pedidos
    return valor_total_pedido;
}


void Pedido::imprimirPedido(){ // Método para imprimir a lista dos Pedidos
    for(unsigned i(0); i < pedidos.size(); i++){ // Repetindo para os n pedidos 
        cout << "===============PRODUTO PEDIDO====================" << endl;
        cout << "Nome: " << pedidos[i].nome << endl; // Carregando da posição i os dados do pedido 
        cout << "Quantidade: " << pedidos[i].quantidade << endl; 
        cout << fixed << setprecision(2) << "Valor unitário: R$ " << pedidos[i].valor_unitario << endl;
    }
}

