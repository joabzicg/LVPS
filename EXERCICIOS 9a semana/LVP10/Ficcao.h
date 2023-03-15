#ifndef FICCAO_H // Início do cabeçalho do arquivo FICCAO_H
#define FICCAO_H

class Ficcao : public Livro { // Classe Ficcao, herdada da classe Livro
    string tipoficcao, narrativa;
public:
    Ficcao(string = "", string = ""); // Construtor com parametros iniciais para os atributos
    void setTipoficcao(string); // Métodos set para definir os atributos
    void setNarrativa(string);
    string getTipoficcao() const; // Métodos get para retornar os valores dos atributos
    string getNarrativa() const;
    ~Ficcao(); // Destrutor
};
#endif //FICCAO_H
