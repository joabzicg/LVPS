/*
>Discente: Joab da Silva Bezerra
>Matrícula: 121110972
>Período: 21.1
>Curso: Engenharia Elétrica
>Disciplina: Técnicas de Programação
>Turma: 02
>Professor: Marcus Salerno
>Unidade 1: LVP 09
>Compilado e programado no Visual Studio Code

Descrição do lvp : Um programa que gerencia a lista de espera de um restaurante.
*/

#include <iostream>  // Bilbioteca para saida e entrada de dados
#include <locale> // Biblioteca para idioma local
#include <string> // Biblioteca para uso do vetor
#include <vector> // Biblioteca para manipulação de entrada e saída de dados

using namespace std;

#include "LVP09_CLASSCLIENTE.cpp" // Incluindo arquivos com as definições de classes dos Objetos
#include "LVP09_CLASSRESTAURANTE.cpp"
#include "LVP09_CLASSMESA.cpp"

int main(){
	setlocale(LC_ALL,"Portuguese"); // Inicialização do idioma local
    int opcao = 0, mesasdisp = 0, acompanhantes = 0, cod = 1, aux = 0; // Variaveis auxiliar
    string nomerestaurante, nome; // Objetos auxiliares 

    cout<<"Bem vindo ao programa!!"<<endl;
    cout<<"Digite o nome do restaurante: "<<endl;
    getline(cin, nomerestaurante);
    Restaurante restaurant(nomerestaurante);  // Instanciando um objeto da classe Restaurante
    Cliente client(nome, cod, acompanhantes); // Instanciando um objeto auxiliar da classe Cliente

    while(1){ // Loop para o menu
        system("clear"); // Comando para limpar console
        cout << "------BEM VINDO AO RESTAURANTE: "<<restaurant.get_nome() << " ------"<< endl
            <<"1 - Adicionar novo cliente" << endl // Couts com opções do menu
            << "2 - Atender cliente" << endl
            << "3 - Remover cliente " << endl
            << "4 - Exibir fila" << endl
            << "5 - Exibir dados do cliente"<<endl
            << "6 - Exibir lista de clientes atendidos"<<endl
            << "7 - Exibir lista de mesas dos clientes atendidos"<<endl
            << "8 - Sair do sistema"<<endl;
        cout << endl << "Digite a opção: "; 
        cin >> opcao; // carregando opcao com o input do usuario

        if(opcao == 8) // Caso a opção seja a 7, o programa para
            break;
            
        system("clear"); // limpando a tela
        
        switch(opcao){ // Switch para realizar uma ação de acordo com o numero escolhido
            case 1: 
                cout<<"O restaurente possui um máximo de: "<<Mesa::get_maximoinstancias()<<" mesas!"<<endl; // Utilizando método get no objeto mesa para retornar o valor máximo de instâncias
                if (cod > 9){ // Caso a variável auxiliar cod seja maior que 9 (ultrapasse o número de mesas), o switch retornará um erro:
                    cout<<"Número máximo de mesas atingido! Não é possível adicionar mais clientes!"<<endl;
                    break;
                }
                cout<<"Digite o nome do cliente"<<endl; // Inserindo dados do Cliente
                cin.ignore();
                getline(cin, nome);
                cout<<"Digite a quantidade de acompanhantes do cliente: "<<endl;
                cin>>acompanhantes;
                if (acompanhantes < 2 || acompanhantes > 8){ // Caso o número de acompanhantes do cliente estiver fora do intervalor de 2 a 8, o switch retorna erro:
                    cout<<"Quantidade de acompanhantes menor que 2 ou maior que 8! Tente novamente!"<<endl;
                    break;
                }
                client.set_acompanhantes(acompanhantes); //Utilizando métodos set para o objeto client
                client.set_nome(nome); // 
                client.set_codigo(cod);
                if (restaurant.adiciona_cliente(client, nome) == true){ // Chamando o método adiciona_cliente e realizando verificação, se o método adiciona_cliente retornar false, o switch dá erro.
                    cout<<"Cliente adicionado com sucesso!"<<endl; // Caso adicona_cliente retorne true: 

                    cod++; // Adicionando mais 1 ao contador auxiliar cod.
                    break;
                }
                cout<<"O cliente com este nome já está na lista de espera!!! Tente novamente!"<<endl; // Caso o retorno de adiciona_cliente seja false, imprime mensagem falando que o cliente ja existe. 
                break;

            case 2: 
                if (restaurant.atende_cliente() == true){ // Chamando o método adiciona_cliente e realizando verificação, se o método atende_cliente retornar false, o switch dá erro.
                    cout<<"Cliente atendido com sucesso!"<<endl; 
                    Mesa::contador_instanciascriadas(); // Chamando metódo da classe Mesa contador_instanciascriadas para adicionar +1 em seu conteúdo.
                    mesasdisp = Mesa::get_maximoinstancias() - Mesa::get_contador(); // Utilizando os métodos get da classe Mesa para calcular o número restante de mesas.
                    cout<<"Número de mesas ainda disponíveis: "<< mesasdisp<<endl;
                    break;
                }
                cout<<"Lista de espera vazia!"<<endl; // Caso retorne false, imprime cout falando que a lista de espera está vazia
                break;

            case 3:
                cout<<"Digite o codigo do cliente a ser removido: "<<endl;
                cin >> aux;
                if (restaurant.remove_cliente(aux) == true){ // Chamando o método remove_cliente e realizando verificação, se o método remove_cliente retornar false, o switch dá erro.
                    cout<<"O cliente foi removido da lista de espera!"<<endl; 
                    break;
                }
                cout<<"Cliente não encontrado!"<<endl;  // Caso retorne false, imprime cout falando que o cliente não está na lista
                break;
            case 4:
                if(restaurant.exibe_fila() == true ){ // Chamando o método exibe_fila e realizando verificação, se o método exibe_fila retornar false, o switch dá erro.
                    cout<<"=============== FIM LISTA DE ESPERA===================="<<endl; // Imprime mensagem no final da lista
                    break;
                }
                cout<<"Não há clientes na lista de espera!"<<endl; // Caso retorne false, imprime cout falando que a lista de espera está vazia
                break;
            case 5:
                if (cod == 0 ){ // Caso não haja códigos de clientes, é impresso um erro e o switch quebra
                    cout<<"Lista de espera vazia, adicone um cliente!"<<endl; 
                    break;
                }
                cout<<"Digite o código do cliente: "<<endl; // Inserindo variável auxiliar para realizar busca do cliente na lista
                cin>>aux;
                if(restaurant.exibe_dados(aux) == true ){ // Chamando o método exibe_dados e realizando verificação, se o método exibe_dados retornar false, o switch dá erro.
                    cout<<"Sucesso, dados do cliente acima. "<<endl; // Imprimindo no final dos dados do cliente
                    break;
                }
                cout<<"Cliente não encontrado!"<<endl; // Imprime caso o cliente não seja achado.
                break;
            case 6:
                if (restaurant.exibe_atendidos() == true ){  // Chamando o método exibe_atendidos e realizando verificação, se o método exibe_atendidos retornar false, o switch dá erro.
                    cout<<"=============== FIM LISTA DE ATENDIDOS===================="<<endl; // Imprime mensagem no final da lista
                    break;
                }
                cout<<"Não há clientes atendidos! "<<endl; // Caso retorne false, imprime cout falando que a lista de atendidos está vazia
                break;
            case 7:
                if (restaurant.exibe_mesas() == true ){  // Chamando o método exibe_atendidos e realizando verificação, se o método exibe_atendidos retornar false, o switch dá erro.
                    cout<<"=============== FIM LISTA DE MESAS===================="<<endl; // Imprime mensagem no final da lista
                    break;
                }
                cout<<"Não há clientes atendidos, portanto não há mesas! "<<endl; // Caso retorne false, imprime cout falando que a lista de atendidos está vazia
                break;
            default:
                cout << "Opção Inválida!!!" << endl; // Caso a opção seja invalida, repete o loop
                break;
        }
        system("read -p 'Pressione qualquer tecla para continuar...' "); // Mensagem ao finalizar o case
    }
    return 0;
}