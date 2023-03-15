#ifndef NAOFICCAO_H // Início do cabeçalho do arquivo NAOFICCAO_H
#define NAOFICCAO_H

class Naoficcao : public Livro { 
    string tipo, tipomidia;
    int ranking;  // Atributo ranking 
public:
    Naoficcao(string = "", string = "", int = 0); // Construtor com parametros iniciais para os atributos
    string getTipo() const; // Métodos para retronar valores dos atributos
    void setTipo(string); // Métodos para setar valores dos atributos
    void setTipomidia(string);
    void setRanking(int);
    string compararanking(int); // Método para a comparação do ranking dos livros de não ficção
    string getTipomidia() const;
    int getRanking() const;
    ~Naoficcao(); // Destrutor
};
#endif // NAOFICCAO_H
