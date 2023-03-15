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
            << "4 - Adicionar pedido" << endl
            << "5 - Mostrar lista de pedidos"<<endl
            << "6 - Retirar um produto da lista de pedidos"<<endl
            << "7 - Calcular valor em R$ total de um produto pedido"<<endl
            << "8 - Calcular valor em R$  todos os produtos pedidos na lista"<<endl
            << "9 - Sair ..."<<endl;
        cout << endl << "Digite a opção: "; 
        cin >> opcao; // carregando opcao com o input do usuario

        if(opcao == 9) // Caso a opção seja a 10, o programa para
            break;
            
        system("clear"); // limpando a tela
        
        switch(opcao){ // Switch para realizar uma ação de acordo com o numero escolhido
            case 1: 
                valor = 0; // variaveis auxiliares
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
                cout<<"Digite o nome do produto a ser pedido: "<<endl;
                cin.ignore();
                getline(cin, nome);
                if (lista.pesquisaProduto(nome) == true){ // Chamando método no objeto lista para a pesquisa do produto
                    pedido.nome = nome; // carregando variaveis auxiliares
                    cout << "Digite a quantidade desejada de produtos: ";
                    cin >> quantidade;
                    pedido.quantidade = quantidade;
                    if (quantidade <= 0){  // Caso a quantidade seja negativa ou nula, retorna erro
                        cout << "Quantidade nula ou negativa, tente novamente!: " << endl; 
                        break;
                    }
                    pedido.valor_unitario = lista.getValorU(nome); // Pegando o valor unitario com o método getValorU, no objeto lista
                    if (lista.retirarQPedido(nome, quantidade) == true){ // Se a quantidade não exceder o estoque:
                        pedidos.incluirProduto(pedido);//Adiciona um produto ao objeto pedido
                        cout<<"Pedido adicionado com sucesso!"<<endl;
                        qntpedidos++; //Adiciona 1 ao contador qntpedidos
                    }
                } 
                break;
            case 5:
                if(qntpedidos == 0){ // Caso a lista não tenha Pedidos, ocorre um erro
                    cout << "Não há pedidos!!!" << endl;
                    break;
                }
                pedidos.imprimirPedido(); // Chamando método no objeto lista para a impressão da lista
                break;  
            case 6:
                if(qntpedidos == 0){ // Caso a lista não tenha Pedidos, ocorre um erro
                    cout << "Não há pedidos!!!" << endl;
                    break;
                }
                cout<<"Digite o nome do produto a ser calculado o seu valor total: "<<endl;
                cin.ignore();
                getline(cin, nome);
                quantidade = pedidos.retirarProduto(nome); // Chamando método no objeto pedidos para a remoção do pedido
                lista.VoltaQntPedido(nome, quantidade); // Chamando método no objeto lista para voltar a quantidade anterior
                qntpedidos--; //Removee 1 no contador qntpedidos
                break;  
            case 7:
                cout<<"Digite o nome do produto a ser calculado da lista de pedidos: "<<endl;
                cin.ignore();
                getline(cin, nome); // Carrega à variável temporária o nome do produto
                pedidos.calcularUnitario(nome); // Chamando método para calcular o valor unitario de um pedido
                break;
            case 8:
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
