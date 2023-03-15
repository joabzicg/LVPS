#ifndef LIVRARIA_H // Início do cabeçalho do arquivo LIVRARIA_H
#define LIVRARIA_H

class Livraria{
    vector<Ficcao> livrosficcao;  // Criando dois vetores para livros de ficção e livros de não ficcção
    vector<Naoficcao> livrosnaoficcao;
    static int senha; // senha para o funcionario, do tipo static int
public:
    Livraria();  // Construtor com parametros iniciais para os atributos
    bool login(int) const; // Método para login do funcionário com a senha
    bool venderLivroF(string isbn); // Método para venda de livros de ficção
    bool venderLivroNF(string isbn); // Método para venda de livros de não ficção
    bool cadastrarLivroF(Ficcao); // Método para o cadastramento de livro de ficção
    bool cadastrarLivroNF(Naoficcao); 
    bool mostrarLivrosF();// Método para mostrar os livros de ficção e não ficção
    bool mostrarLivrosNF();
    ~Livraria(); // destrutor
};     
#endif //LIVRARIA_H