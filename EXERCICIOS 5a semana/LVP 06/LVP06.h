#ifndef LVP06_H // Início do cabeçalho do arquivo LVP06_H
#define LVP06_H

struct Hora{ // Struct hora para receber o horário
	int hora, minuto, segundo;
};

class Estacionamento { // Criando uma classe chamada Estacionamento, contendo os atributos hora_e, hora_s, strings placa e nome, valor da hora, valor do custo, e valor da hora convertida.
	Hora hora_e;
	Hora hora_s;
	string placa;
	string nome;
	double valor_h;
	double custo;
	double hora_convertida;
public: 
	Estacionamento(); // Construtor para posicionamento dos atributos iniciais.
	void set_dados(string, string); // Métodos set para  receber dados e atribuir aos atributos
	void set_horas(Hora, Hora);
	string get_placa(); // Métodos get para retorno de dados
	string get_nome();
	double get_horas();
	double calculavalor(); // Método para calcular o custo total do estacionamento.
};

#endif // LVP06_H
