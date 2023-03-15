#include "LVP08_VENDEDOR.h"

Vendedor::Vendedor(){ // Construtor para inicializar a alocação dinâmica
}

void Vendedor::insere(Produto p){ // Método para inserir objetos do tipo Produto na lista criada
    produtos.push_back(p);
}

void Vendedor::printLista(){ // Método para imprimir a lista dos Produtos
    for(unsigned i(0); i < produtos.size(); i++){ // Repetindo para os n produtos 
        cout << "===============PRODUTO====================" << endl;
        cout << "Nome: " << produtos[i].getNome() << endl; // Chamando métodos para retornar o nome e quantidade dos produtos 
        cout << "Quantidade: " << produtos[i].getQuantidade() << endl;
        cout <<fixed<<setprecision(2)<< "Valor unitário: R$" << produtos[i].getValorU()<< endl;
    }
}

bool Vendedor::pesquisaProduto(string produto){ // Método para pesquisar os produtos na lista
    for(unsigned i(0); i < produtos.size(); i++){ // Repetindo para a lista com n produto
        if (produto == produtos[i].getNome()){ // Caso a string carregada da main seja igual a contida no método getNome, do nésimo Produto:
            cout << "----- Produto encontrado! -----" << endl; 
            cout << "Nome: " << produtos[i].getNome() << endl; // Imprimirá o nome e quantidade do nésimo Produto com o nome igual ao pesquisado
            cout << "Quantidade: " << produtos[i].getQuantidade() << endl;
            cout <<fixed<<setprecision(2)<< "Valor unitário: R$" << produtos[i].getValorU()<< endl;
            return true; // caso o produto seja achado, a função retorna true
        }
    }
    cout<<"Produto não encontrado!"<<endl;
    return false;
}

float Vendedor::getValorU(string produto){ // Método para retornar o valor unitario de um produto
    for(unsigned i(0); i < produtos.size(); i++){ // Repetindo para a lista com n produto
        if (produto == produtos[i].getNome()){ // Caso a string carregada da main seja igual a contida no método getNome, do nésimo Produto:
            return produtos[i].getValorU(); // retorna valor unitario de um produto
        }
    }
    cout<<"Produto não encontrado!"<<endl;
    return 0; // caso não seja encontrado, o valor unitario será 0
}

bool Vendedor::retirarQPedido(string produto, int qntd){ // Método para retirar a quantidade após feito um pedidod
    for(unsigned i(0); i < produtos.size(); i++){ // Repetindo para a lista com n produto
        if (produto == produtos[i].getNome()){ // Caso a string carregada da main seja igual a contida no método getNome, do nésimo Produto:
            int retorno; // variável auxiliar 
            retorno = produtos[i].venderProduto(qntd); // o retorno será igual a quantidade removida depois de feito o pedido
            if (retorno == 0){ // Se a quantidade for maior que o estoque:
                cout << "Quantidade de venda inválida ou maior que o estoque"<<endl;
                return false;
            }
            return true; // Caso seja possivel remover a quantidade feita no pedido, a função retorna true
        }
    }
    cout<<"Produto não encontrado!"<<endl;
    return false;
}

void Vendedor::VoltaQntPedido(string nome, int qntd){ // Método para voltar a quantidade original após a remoção de um pedido
    int total = 0; // variavel auxiliar
    for(unsigned i(0); i < produtos.size(); i++){ // Repetindo para a lista com n produto
        if (nome == produtos[i].getNome()){ // Caso a string carregada da main seja igual a contida no método getNome, do nésimo Produto:
            total = qntd + produtos[i].getQuantidade(); // total será igual a soma da quantidade carregada da main e a quantidade atual do produto
            produtos[i].setQuantidade(total); // Método para setar a quantidade com o valor original
            cout << "quantidade reestabelecida!"<<endl; 
        }
    }
}

void Vendedor::venderProduto(string produto, int quantidade){ // Método para vender os Produtos da lista
    for(unsigned i(0); i < produtos.size(); i++) { // Procurando o produto de acordo com o nome inserido a partir da main 
        if (produto == produtos[i].getNome()){ // Utilizando o mesmo bloco de pesquisa, mostrado anteriomente
            int retorno;
            cout << "----- Produto encontrado! -----" << endl;
            cout << "Nome: " << produtos[i].getNome() << endl;
            cout << "Quantidade: " << produtos[i].getQuantidade() << endl;
            cout <<fixed<<setprecision(2)<< "Valor unitário: R$" << produtos[i].getValorU()<< endl;
            retorno = produtos[i].venderProduto(quantidade);
            if (retorno == 0){
                cout << "Quantidade de venda inválida ou maior que o estoque"<<endl;
                return;
            }
            cout << "----- Produto após a venda -----" << endl; // Mostrando quantidades após a venda
            cout << "Nome: " << produtos[i].getNome() << endl;
            cout << "Quantidade: " << produtos[i].getQuantidade() << endl;
            cout <<fixed<<setprecision(2)<< "Valor unitário: R$" << produtos[i].getValorU()<< endl;
            return;
        }
    }
    cout<<"Produto não encontrado!"<<endl; // Mensagem para dizer que o produto foi encontrado
}
 