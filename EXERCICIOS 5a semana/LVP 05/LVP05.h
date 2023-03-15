#ifndef LVP05_H // Início do cabeçalho do arquivo LVP05_H
#define LVP05_H

class Horario{ // Criando uma classe chamada Horario, contendo os atributos hora, minuto e segundo.
	int hora;
	int minuto;
	int segundo;
public: 
	Horario(int, int, int); // Construtor para posicionamento de dados previamente colocados na função main.
	Horario(); // Construtor para posicionamento de dados a partir dp horario do sistema.

	void setHora(int); // Métodos set para colocação de dados a partir da main.
	void setMinuto(int);
	void setSegundo(int);

	int getHora(); // Métodos get para recepção de dados a partir da main.
	int getMinuto();
	int getSegundo();

	string converteString(); // Método converteString para formatação do horario.
    void adicionaSegundo(); // Método para adicionar segundo ao horario 
};

#endif // LVP05_H
