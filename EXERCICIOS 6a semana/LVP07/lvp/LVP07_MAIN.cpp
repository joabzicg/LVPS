/*
>Discente: Joab da Silva Bezerra
>Matrícula: 121110972
>Período: 21.1
>Curso: Engenharia Elétrica
>Disciplina: Técnicas de Programação
>Turma: 02
>Professor: Marcus Salerno
>Unidade 1: LVP 07
>Compilado e programado no Visual Studio Code

Descrição do lvp : Um programa que gerencia uma lista de produtos de uma loja. Utilizando-se de alocação dinâmica.
*/

// Bibliotecas necessárias para o funcionamento do programa
#include <iostream>  // Bilbioteca para saida e entrada de dados
#include <cstdlib> // Biblioteca para clean do console
#include <cstring> // Biblioteca para uso de strings
#include <clocale> // Biblioteca para idioma local

using namespace std;

#include "LVP07_CLASSPRODUTO.cpp" // Incluindo arquivos com as definições de classes dos Objetos
#include "LVP07_CLASSVENDEDOR.cpp"

int main(){ // Função principal
    setlocale(LC_ALL, "Portuguese"); // // Inicialização do idioma local
    int tamanhomax, quantidade, opcao, qnt=0; // Variaveis auxiliares 
    string nome; 

    cout<<"Quantos produtos deseja adicionar?"; 
    cin>>tamanhomax; // Inserindo o tamanho maximo da lista na variavel auxiliar

    Vendedor lista(tamanhomax); // Inserindo o tamanho maximo da lista e criando um objeto auxiliar chamado "lista" do tipo Vendedor
    Produto p; // Criando um objeto auxiliar "p" do tipo Produto

    while(1){ // Loop para o menu
        system("cls"); // Comando para limpar console
        cout << "1 - Adicionar produto" << endl // Couts com opções do menu
            << "2 - Pesquisar produto pelo nome" << endl
            << "3 - Mostrar lista de produtos " << endl
            << "4 - Vender produtos" << endl
            << "5 - Sair..." << endl;
        cout << endl << "Digite a opção: "; 
        cin >> opcao;

        if(opcao == 5) // Caso a opção seja a 5, o programa para
            break;
            
        system("cls");
        
        switch(opcao){ // Switch para realizar uma ação de acordo com o numero escolhido
            case 1: 
                if(qnt >= tamanhomax){ // Caso a lista esteja totalmente preenchida ocorre erro
                    cout << "Lista cheia!!!" << endl;
                    break;
                }
                cout << "Digite o nome do produto: "; // Inserindo dados do Produto
                cin.ignore();
                getline(cin, nome);
                p.setNome(nome);
                cout << "Digite a quantidade de " << p.getNome() << ":";
                cin >> quantidade;
                p.setQuantidade(quantidade); 
                lista.insere(p); //Adiciona um Produto ao objeto lista
                qnt++; //Adiciona n vezes Produtos ao objeto lista
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
                lista.venderProduto(nome, quantidade); // Chamando método no objeto lista para a venda de Produto
                break;

            default:
                cout << "Opção Inválida!!!" << endl; // Caso a opção seja invalida, repete o loop
                break;
        }
        system("pause"); // Para finalizar o programa
    }
    return 0;
}
