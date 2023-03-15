#ifndef LVP09_CLIENTE_H // Início do cabeçalho do arquivo LVP09_CLIENTE_H
#define LVP09_CLIENTE_H

class Cliente { // Criando uma classe chamada cliente, contendo os atributos nome, codigo e numerodepessoas.
    string nome;
    int codigo, numeropessoas;   

public:
    Cliente(string="Desconhecido", int =0, int=0); // Construtor inicializando valores para nome, codigo e numerodepessoas.
    void set_nome(string); // Méotodos set para setar valores dos atributos
    void set_codigo(int); 
    void set_acompanhantes(int);
    string get_nomecliente() const; // Métodos para retornar valores dos atributos
    int get_numeropessoas() const;
    int get_codigo() const;
};

#endif //LVP09_CLIENTE_H