#include "LVP07_VENDEDOR.h"

Vendedor::Vendedor(int tam){ // Construtor para inicializar a alocação dinâmica
    this->tam = tam;
    produtos = new Produto[tam]; // Criação da lista com tamanho definido na main
    n = 0;
}

void Vendedor::insere(Produto p){ // Método para inserir objetos do tipo Produto na lista criada
    produtos[n] = p; // inserindo p, previamente carregado da main
    n++; // inserindo na posição n
}

void Vendedor::printLista(){ // Método para imprimir a lista dos Produtos
    for(int i = 0; i < tam; i++){ // Repetindo para os n produtos 
        cout << "===============PRODUTO====================" << endl;
        cout << "Nome: " << produtos[i].getNome() << endl; // Chamando métodos para retornar o nome e quantidade dos produtos 
        cout << "Quantidade: " << produtos[i].getQuantidade() << endl;
    }
}

void Vendedor::pesquisaProduto(string produto){ // Método para pesquisar os produtos na lista
    for(int i = 0; i < n; i++){ // Repetindo para a lista com n produto
        if (produto == produtos[i].getNome()){ // Caso a string carregada da main seja igual a contida no método getNome, do nésimo Produto:
            cout << "----- Produto encontrado! -----" << endl; 
            cout << "Nome: " << produtos[i].getNome() << endl; // Imprimirá o nome e quantidade do nésimo Produto com o nome igual ao pesquisado
            cout << "Quantidade: " << produtos[i].getQuantidade() << endl;
            return;
        }
    }
    cout<<"Produto não encontrado!"<<endl;
}

void Vendedor::venderProduto(string produto, int quantidade){ // Método para vender os Produtos da lista
    for(int i = 0; i < n; i++) { // Procurando o produto de acordo com o nome inserido a partir da main 
        if (produto == produtos[i].getNome()){ // Utilizando o mesmo bloco de pesquisa, mostrado anteriomente
            int retorno;
            cout << "----- Produto encontrado! -----" << endl;
            cout << "Nome: " << produtos[i].getNome() << endl;
            cout << "Quantidade: " << produtos[i].getQuantidade() << endl;
            retorno = produtos[i].venderProduto(quantidade);
            if (retorno == 0){
                cout << "Quantidade de venda inválida ou maior que o estoque"<<endl;
            }
            cout << "----- Produto após a venda -----" << endl; // Mostrando quantidades após a venda
            cout << "Nome: " << produtos[i].getNome() << endl;
            cout << "Quantidade: " << produtos[i].getQuantidade() << endl;
            return;
        }
    }
    cout<<"Produto não encontrado!"<<endl; // Mensagem para dizer que o produto foi encontrado
}

Vendedor::~Vendedor(){
    delete []produtos; // Destrutor para a exclusão dos dados
}
