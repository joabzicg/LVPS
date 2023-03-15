/*
>Discente: Joab da Silva Bezerra
>Matrícula: 121110972
>Período: 21.1
>Curso: Engenharia Elétrica
>Disciplina: Técnicas de Programação
>Turma: 02
>Professor: Marcus Salerno
>Unidade 1: LVP 10
>Compilado e programado no Visual Studio Code

Descrição do lvp : Um programa que gerencia uma livraria.
*/

#include <iostream> // Bilbioteca para saida e entrada de dados
#include <locale> // Biblioteca para idioma local
#include <string>  // Biblioteca para uso de strings
#include <vector> // Biblioteca para uso do vetor
#include <algorithm> // Biblioteca para uso da função sort
#include <cstdlib> // Biblioteca comandos de clear, e pause

using namespace std;

#include "Livro.cpp" // Incluindo arquivos com as definições de classes dos Objetos
#include "Ficcao.cpp" 
#include "Naoficcao.cpp" 
#include "Livraria.cpp" 

int main(){
	setlocale(LC_ALL,"Portuguese"); // Inicialização do idioma local
    int opcao = 0, ano = 0, senha = 0, ranking = 0, qntf = 0, qntnf =0 ; // Variaveis auxiliares
    double preco;
    string nome, autor, isbn, tipoficcao, tipo, tipomidia, narrativa; 
    Livraria library; // Objetos auxiliares 
    Naoficcao livroNF(tipo, tipomidia, ranking);
    Ficcao LivroF(tipoficcao, narrativa);

    cout<<"Bem vindo ao programa!! Possui o objetivo de gerenciar uma livraria!"<<endl;
    do { // Loopwhile para entrada da senha correta
        cout<<"Digite a senha para acessar o menu de funcionário! "<<endl;
        cin>>senha;
        library.login(senha); // Chama o método login com a senha colocada
        cout<<"Senha incorreta, tente novamente!"<<endl;
    }
    while (library.login(senha) != true); // Enquanto não for correto, o loop do é repetido
    while(1){ // Loop para o menu
        system("cls"); // Comando para limpar console
        cout << "------BEM VINDO A LIVRARIA ------"<< endl
            <<"1 - Adicionar um Livro de não Ficção " << endl // Couts com opções do menu
            <<"2 - Imprimir lista de livros de não ficção " << endl
            <<"3 - Adicionar um livro de Ficção " << endl
            <<"4 - Imprimir lista de livros de ficção " << endl
            <<"5 - Vender livro de não ficção " << endl
            <<"6 - Vender livro de ficção " << endl
            <<"7 - Sair do sistema"<<endl;
        cout << endl << "Digite a opção: "; 
        cin >> opcao; // carregando opcao com o input do usuario

        if(opcao == 7) // Caso a opção seja a 7, o programa para
            break;
            
        system("cls"); // limpando a tela 
        
        switch(opcao){ // Switch para realizar uma ação de acordo com o numero escolhido
            case 1:
                cout<<"Digite o nome do livro: "<<endl; // Inserindo dados auxiliares do livro de não ficção
                cin.ignore();
                getline(cin, nome);
                livroNF.setNome(nome); // Chamando métodos set para colocação de dados no objeto auxiliar

                cout<<"Digite o nome do autor: "<<endl;
                getline(cin, autor);
                livroNF.setAutor(autor); 

                cout<<"Digite o preço do livro: "<<endl; 
                cin>>preco; 
                if (preco <= 0){ // Checando se o preço for negativo
                    cout<<"Preço inválido, tente novamente!"<<endl;
                    break;
                }
                livroNF.setPreco(preco);

                cout<<"Digite o tipo do livro: "<<endl;
                cin>>tipo;
                livroNF.setTipo(tipo);

                cout<<"Digite o tipo de mídia do livro: "<<endl;
                cin>>tipomidia;
                livroNF.setTipomidia(tipomidia);
                
                cout<<"Digite o ano de lançamento do livro: "<<endl;
                cin>>ano;
                if (ano <= 0 && ano>2022){
                    cout<<"Data inválida, tente novamente!"<<endl;
                    break;
                }
                livroNF.setAno(ano);

                cout<<"Digite o ranking semanal do livro: "<<endl;
                cin>>ranking;
                if (ranking <= 0){
                    cout<<"Ranking inválido, tente novamente!"<<endl;
                    break;
                }
                livroNF.setRanking(ranking);

                cout<<"Digite o ISBN do livro: "<<endl;
                cin >> isbn;
                livroNF.setIsbn(isbn);
                if (library.cadastrarLivroNF(livroNF) == false){ // Checando se o isbn já não foi colocado, chamando a função cadastrarLivroNF
                    cout<<"O ISBN informado já existe na lista de livros de não ficção! Tente novamente!"<<endl;
                    break;
                }
                qntnf++; // Adicionando 1 ao contador qntnf
                cout<<"Livro adicionado com sucesso!"<<endl;
                break;
            case 2:
                if (qntnf == 0){ // Caso o contador qntnf for igual a 0, mostra erro:
                    cout<<"Lista de livros de não ficção vazia, adicione um livro!"<<endl;
                    break;
                }
                library.mostrarLivrosNF(); // Chama método para a impressão dos livros de Não Ficção
                break;
            case 3:
                cout<<"Digite o nome do livro: "<<endl; // Inserindo dados auxiliares do livro ficção
                cin.ignore();
                getline(cin, nome);
                LivroF.setNome(nome);

                cout<<"Digite o nome do autor: "<<endl;
                getline(cin, autor);
                LivroF.setAutor(autor); 

                cout<<"Digite o preço do livro: "<<endl;
                cin>>preco;
                if (preco <= 0){
                    cout<<"Preço inválido, tente novamente!"<<endl;
                    break;
                }
                LivroF.setPreco(preco);
                
                cout<<"Digite o ano de lançamento do livro: "<<endl;
                cin>>ano;
                if (ano <= 0 && ano>2022){
                    cout<<"Data inválida, tente novamente!"<<endl;
                    break;
                }
                LivroF.setAno(ano);

                cout<<"Digite o tipo de ficção do livro: "<<endl;
                cin.ignore();
                getline(cin,tipoficcao);
                LivroF.setTipoficcao(tipoficcao);

                cout<<"Digite o tipo de narrativa do livro: "<<endl;
                getline(cin,narrativa);
                LivroF.setNarrativa(narrativa);
                
                cout<<"Digite o ISBN do livro: "<<endl;
                cin>>isbn;
                LivroF.setIsbn(isbn);
                if (library.cadastrarLivroF(LivroF) == false){ // Faz verificção do ISBN e insere o livro de Ficção no vetor
                    cout<<"O ISBN informado já existe na lista de livros de ficção! Tente novamente!"<<endl;
                    break;
                }
                qntf++; // Adiciona 1 ao contador qntf
                cout<<"Livro adicionado com sucesso!"<<endl;
                break;
            case 4:
                    if (qntf == 0){ // Caso o contador qntf estiver igual a 0, mostra erro:
                    cout<<"Lista de livros de ficção vazia, adicione um livro!"<<endl;
                    break; // Sai do case
                }
                library.mostrarLivrosF(); // Chama método para a impressão dos livros de Não Ficção
                break;
            case 5:
                cout<<"Digite o ISBN do livro de não ficção a ser vendido:"<<endl; 
                cin>>isbn;
                if (library.venderLivroNF(isbn) == true){ // Checa se o método retorna true, caso true mostra mensagem:
                    cout<<"Livro vendido com sucesso!"<<endl;
                    qntnf--; // Diminui 1 do contador qntnf
                    break; // Sai do case
                }
                cout<<"O livro com o ISBN digitado não existe, tente outra vez!"<<endl; 
                break;

            case 6:
                cout<<"Digite o ISBN do livro de ficção a ser vendido:"<<endl; // Checa se o método retorna true, caso true mostra mensagem:
                cin>>isbn;
                if (library.venderLivroF(isbn) == true){
                    cout<<"Livro vendido com sucesso!"<<endl;
                    qntf--;  // Diminui 1 do contador qntf
                    break; // Sai do case
                }
                cout<<"O livro com o ISBN digitado não existe, tente outra vez!"<<endl;
                break;
            default:
                cout << "Opção Inválida!!!" << endl; // Caso a opção seja invalida, repete o loop
                break;
        }
        system("pause"); // Mensagem ao finalizar o case
    }
    return 0;
}