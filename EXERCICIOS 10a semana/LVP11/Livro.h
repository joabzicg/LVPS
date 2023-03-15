#ifndef LIVRO_H // Início do cabeçalho do arquivo LIVRO_H
#define LIVRO_H

class Livro{
	public:
		string nome, autor, isbn;
		double preco;
        int ano;
	public:
		Livro(string = "", string = "", string = "", double = 0, int = 0); // Construtor com parametros iniciais para os atributos
		void setNome(string); // Métodos set para definir os atributos
		void setAutor(string);
		void setIsbn(string);
		void setPreco(double);
		void setAno(int);
		string getNome() const; // Métodos get para retornar os valores dos atributos
		string getAutor() const;
		string getIsbn() const;
		double getPreco() const;
		int getAno() const;
		~Livro(); // Destrutor
};

#endif //LIVRO_H
