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

void Vendedor::pesquisaProduto(string produto){ // Método para pesquisar os produtos na lista
    for(unsigned i(0); i < produtos.size(); i++){ // Repetindo para a lista com n produto
        if (produto == produtos[i].getNome()){ // Caso a string carregada da main seja igual a contida no método getNome, do nésimo Produto:
            cout << "----- Produto encontrado! -----" << endl; 
            cout << "Nome: " << produtos[i].getNome() << endl; // Imprimirá o nome e quantidade do nésimo Produto com o nome igual ao pesquisado
            cout << "Quantidade: " << produtos[i].getQuantidade() << endl;
            cout <<fixed<<setprecision(2)<< "Valor unitário: R$" << produtos[i].getValorU()<< endl;
            return;
        }
    }
    cout<<"Produto não encontrado!"<<endl;
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
