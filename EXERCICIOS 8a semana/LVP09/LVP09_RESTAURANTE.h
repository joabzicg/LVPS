#ifndef LVP09_RESTAURANTE_H  // Início do cabeçalho do arquivo LVP09_RESTAURANTE_H 
#define LVP09_RESTAURANTE_H

class Restaurante { // Criando uma classe chamada Restaurante, contendo os atributos do tipo vector, clientes_atendidos, clientes_espera, e uma variavel do tipo string nome, para o nome do restaurante. 
    string nome;
    vector<Cliente> clientes_atendidos;
    vector<Cliente> clientes_espera;
    vector<Mesa> mesas;
public:
    Restaurante(string="Restaurante desconhecido"); // Construtor com os parametros padrões setados
    string get_nome() const; // Método get_nome para pegar o nome do restaurante
    bool adiciona_cliente(Cliente, string); // Método para adicionar cliente a lista de espera, com parametros de entrada do tipo Cliente e string (string para realizar a consulta na lista)
    bool remove_cliente(int); // Método que remove o cliente da lista de espera
    bool atende_cliente(); // Método para atender cliente
    bool exibe_fila() const; // Método para exibir fila de espera dos clientes
    bool exibe_mesas() const; // Método para exibir mesas ocupadas pelos clientes ja atendidos
    bool exibe_atendidos() const; // Método para exibir clientes atendidos
    bool exibe_dados(int) const; // Método para exibir dados de um cliente a partir de seu código
    ~Restaurante(); // Destrutor
};

#endif // LVP09_RESTAURANTE_H