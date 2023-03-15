/*
>Discente: Joab da Silva Bezerra
>Matrícula: 121110972
>Período: 21.1
>Curso: Engenharia Elétrica
>Disciplina: Técnicas de Programação
>Turma: 02
>Professor: Marcus Salerno
>Unidade 1: LVP 08
>Compilado e programado no Visual Studio Code

Descrição do lvp : Um programa que gerencia uma lista de produtos e a lista de pedidos de uma loja. Utilizando-se de vetores.
*/

// Bibliotecas necessárias para o funcionamento do programa
#include <iostream>  // Bilbioteca para saida e entrada de dados
#include <stdlib.h> // Biblioteca para clean do console
#include <cstring> // Biblioteca para uso de strings
#include <clocale> // Biblioteca para idioma local
#include <vector> // Biblioteca para uso do vetor
#include <iomanip> // Biblioteca para manipulação de entrada e saída de dados

using namespace std;

#include "LVP08_CLASSPRODUTO.cpp" // Incluindo arquivos com as definições de classes dos Objetos
#include "LVP08_CLASSVENDEDOR.cpp"
#include "LVP08_CLASSPEDIDO.cpp"

int main(){ // Função principal
    setlocale(LC_ALL, "Portuguese"); // // Inicialização do idioma local
    int quantidade = 0, opcao, qnt=0, qntpedidos = 0; // Variaveis auxiliares 
    double valor;
    string nome;
    Lista pedido;

    Vendedor lista; // Inserindo o tamanho maximo da lista e criando um objeto auxiliar chamado "lista" do tipo Vendedor
    Produto p; // Criando um objeto auxiliar "p" do tipo Produto
    Pedido pedidos; // Criando um objeto auxiliar "pedidos" do tipo Pedido

    while(1){ // Loop para o menu
        system("clear"); // Comando para limpar console
        cout << "1 - Adicionar produto" << endl // Couts com opções do menu
            << "2 - Pesquisar produto pelo nome" << endl
            << "3 - Mostrar lista de produtos " << endl
            << "4 - Vender produtos" << endl
            << "5 - Adicionar pedido" << endl
            << "6 - Mostrar lista de pedidos"<<endl
            << "7 - Retirar um produto da lista de pedidos"<<endl
            << "8 - Calcular valor em R$ total de um produto pedido"<<endl
            << "9 - Calcular valor em R$  todos os produtos pedidos na lista"<<endl
            << "10 - Sair ..."<<endl;
        cout << endl << "Digite a opção: "; 
        cin >> opcao;

        if(opcao == 10) // Caso a opção seja a 10, o programa para
            break;
            
        system("clear");
        
        switch(opcao){ // Switch para realizar uma ação de acordo com o numero escolhido
            case 1: 
                valor = 0;
                quantidade = 0;
                cout << "Digite o nome do produto: "; // Inserindo dados do Produto
                cin.ignore();
                getline(cin, nome);
                p.setNome(nome);
                cout << "Digite a quantidade de " << p.getNome() << ":";
                cin >> quantidade;
                if (quantidade < 0){
                    cout << "Quantidade negativa, inválida! Tente novamente!"<<endl;
                    break;
                }
                p.setQuantidade(quantidade); 
                cout << "Digite o valor unitario em R$ de " << p.getNome() << ":";
                cin >> valor;
                if (valor < 0){
                    cout << "Valor unitario negativo, inválido! Tente novamente!"<<endl;
                    break;
                }
                p.setValorU(valor); 
                lista.insere(p); //Adiciona um Produto ao objeto lista
                qnt++; //Adiciona 1 ao contador qnt
                break;
            case 2:
                if(qnt == 0){ // Caso a lista não tenha Produtos, ocorre um erro
                    cout << "Não há produtos!!!" << endl; 
                    break;
                }
                cout<<"Digite o nome do produto: "<<endl;
                cin.ignore();
                getline(cin, nome);
                lista.pesquisaProduto(nome); // Chamando método no objeto lista para a pesquisa do produto
                break;
            case 3:
                if(qnt == 0){ // Caso a lista não tenha Produtos, ocorre um erro
                    cout << "Não há produtos!!!" << endl; 
                    break;
                }
                lista.printLista(); // Chamando método no objeto lista para a impressão da lista
                break;     
            case 4:
                if(qnt == 0){ // Caso a lista não tenha Produtos, ocorre um erro
                    cout << "Não há produtos!!!" << endl;
                    break;
                }
                cout << "Digite a o nome do produto: " << endl;
                cin >> nome;
                cout << "Digite a quantidade desejada para vender o produto: " << endl; 
                cin >> quantidade;
                if (quantidade <= 0){
                    cout << "Quantidade nula ou negativa, tente novamente!: " << endl; 
                    break;
                }
                lista.venderProduto(nome, quantidade); // Chamando método no objeto lista para a venda de Produto
                break;
            case 5:
                cout << "Digite o nome do produto a ser pedido: "; // Inserindo dados do Pedido
                cin.ignore();
                getline(cin, pedido.nome);
                cout << "Digite a quantidade do produto a ser pedido:";
                cin >> pedido.quantidade;
                if (pedido.quantidade < 0){ // Caso a lista não tenha Produtos, ocorre um erro
                    cout << "Quantidade negativa, inválida! Tente novamente!"<<endl;
                    break;
                }
                cout << "Digite o valor unitario em R$ do produto:"; // Caso o valor seja negativo, ocorre um erro
                cin >> pedido.valor_unitario;
                if (pedido.valor_unitario < 0){
                    cout << "Valor unitario negativo, inválido! Tente novamente!"<<endl;
                    break;
                }
                pedidos.incluirProduto(pedido); //Adiciona um produto ao objeto pedido
                qntpedidos++; //Adiciona 1 ao contador qntpedidos
                break;
            case 6:
                if(qntpedidos == 0){ // Caso a lista não tenha Pedidos, ocorre um erro
                    cout << "Não há pedidos!!!" << endl;
                    break;
                }
                pedidos.imprimirPedido(); // Chamando método no objeto lista para a impressão da lista
                break;  
            case 7:
                if(qntpedidos == 0){ // Caso a lista não tenha Pedidos, ocorre um erro
                    cout << "Não há pedidos!!!" << endl;
                    break;
                }
                cout<<"Digite o nome do produto a ser calculado o seu valor total: "<<endl;
                cin>>nome;
                pedidos.retirarProduto(nome); // Chamando método no objeto lista para a impressão da lista
                qntpedidos--; //Removee 1 no contador qntpedidos
                break;  
            case 8:
                cout<<"Digite o nome do produto a ser calculado o seu valor total: "<<endl;
                cin>>nome; // Carrega à variável temporária o nome do produto
                pedidos.calcularUnitario(nome); // Chamando método para calcular o valor unitario de um pedido
                break;
            case 9:
                if(qntpedidos == 0){ // Caso a lista não tenha Pedidos, ocorre um erro
                    cout << "Não há pedidos!!!" << endl;
                    break;
                }
                pedidos.calcularTotal(); // Chamando método para calcular valor total da lista de pedidos
                cout<<"O valor total da lista é de: R$ "<<pedidos.getTotal()<<endl; // Chamando o método para retornar o valor total da lista de pedidos
                break;
            default:
                cout << "Opção Inválida!!!" << endl; // Caso a opção seja invalida, repete o loop
                break;
        }
        system("read -p 'Pressione qualquer tecla para continuar...' ");
    }
    return 0;
}
