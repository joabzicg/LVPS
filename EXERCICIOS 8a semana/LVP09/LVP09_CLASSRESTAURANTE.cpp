#include "LVP09_RESTAURANTE.h" // Incluindo arquivos de cabeçalho LVP09_RESTAURANTE e 

Restaurante::Restaurante(string nome){//Inicializa o atributo nome da classe Restaurante
    this->nome = nome; // string de entrada nome é colocado no atributo nome do objeto Restaurante.
}

string Restaurante::get_nome() const{ // Método get para retornar o nome do restaurante
    return nome;
}

bool Restaurante::adiciona_cliente(Cliente c, string nome){ // Método para inserir objetos do tipo Cliente na lista criada
    for(unsigned i(0); i < clientes_espera.size(); i++){ // Repetindo para o vetor com n clientes
        if (nome == clientes_espera[i].get_nomecliente()){ // Caso a string carregada da main seja igual a contida no cliente de posição i do vetor:
            return false; // retorna false, pois o cliente ja está contido no vetor. 
        }
    }
    clientes_espera.push_back(c); // Caso contrário, o cliente é adicionado no fim do vetor.
    return true; // retorna true.
}


bool Restaurante::remove_cliente(int codigo) { // Método para remoção de Clientes da lista.
    for(unsigned i(0); i < clientes_espera.size(); i++){ // For repetindo para o vetor com n clientes
        if (codigo == clientes_espera[i].get_codigo()){ // Caso a string carregada da main seja igual a contida no cliente de posição i do vetor:
            clientes_espera.erase(clientes_espera.begin()+i); // Irá excluir o cliente da posição i
            return true; // retorna true
        }
    }
    return false; // caso não seja encontrado o cliente, retorna false
}



bool Restaurante::atende_cliente(){ // Método para o atendimento de um cliente a partir da lista de espera.
    if(clientes_espera.size() == 0){ //  Caso a lista estiver vazia, retorna false.
        return false;
    }
    Mesa m; // Caso contrário, cria um objeto m auxiliar do tipo Mesa
    m.set_ncadeiras(clientes_espera[0].get_numeropessoas()); // Usando método set no objeto auxiliar m, para setar o numero de cadeiras com o retorno da função get_numeropessoas da posição 0 do clientes.espera
    clientes_atendidos.insert(clientes_atendidos.begin(), clientes_espera[0]); //  Adiciona o cliente da posição 0 do vetor clientes_espera no vetor clientes_atendidos.
    clientes_espera.erase(clientes_espera.begin()); // Após isso exclui o cliente do começo do vetor clientes_espera
    mesas.insert(mesas.begin(), m); // Insere uma mesa atrelado ao cliente
    return true; // E retorna true
}

bool Restaurante::exibe_fila() const{ // Método para exibição de clientes da lista de espera.
    if (clientes_espera.size() == 0){ //  Caso a lista estiver vazia, retorna false.
        return false;
    }
    for(unsigned i(0); i < clientes_espera.size(); i++){ // For repetindo para o vetor com n clientes
        cout << "===============LISTA DE ESPERA====================" << endl; // Imprimindo dados dos clientes
        cout << "Código n°: " << clientes_espera[i].get_codigo()<<endl; // Carregando da posição i os dados do cliente 
        cout << "Nome: " << clientes_espera[i].get_nomecliente() << endl; 
        cout << "Número de acompanhantes: " << clientes_espera[i].get_numeropessoas() << endl; 
    }
    return true; // Ao final, retorna true
}

bool Restaurante::exibe_atendidos() const{ // Método para a exibição dos clientes atendidos.
    if (clientes_atendidos.size() == 0){ //  Caso a lista de atendidos estiver vazia, retorna false.
        return false; 
    }
    for(unsigned i(0); i < clientes_atendidos.size(); i++){ // For repetindo para o vetor com n clientes
        cout << "===============LISTA DE ATENDIDOS====================" << endl; // Imprimindo dados dos clientes 
        cout << "Nome: " << clientes_atendidos[i].get_nomecliente() << endl; // Carregando da posição i os dados do cliente 
        cout << "Número de acompanhantes: " << clientes_atendidos[i].get_numeropessoas() << endl; 
    }
    return true;
}


bool Restaurante::exibe_mesas() const{ // Método para a exibição dos clientes atendidos.
    if (clientes_atendidos.size() == 0){ //  Caso a lista de atendidos estiver vazia, retorna false.
        return false; 
    }
    for(unsigned i(0); i < mesas.size(); i++){ // For repetindo para o vetor com n clientes
        cout << "===============LISTA DE MESAS====================" << endl; // Imprimindo dados dos clientes 
        cout << "Nome do cliente: " << clientes_atendidos[i].get_nomecliente() <<endl;  // Carregando da posição i os dados do cliente 
        cout << "Número de cadeiras na mesa: " << mesas[i].get_ncadeiras() << endl; 
    }
    return true;
}



bool Restaurante::exibe_dados(int codigo) const{ // Método para a exibição de um cliente na lista de espera.
    if (clientes_espera.size() == 0){  //  Caso a lista de espera estiver vazia, retorna false.
        return false;
    }
    for(unsigned i(0); i < clientes_espera.size(); i++){ // For repetindo para o vetor com n clientes
        if (codigo == clientes_espera[i].get_codigo()){ // Caso o int carregado da main seja igual ao contido no cliente de posição i do vetor:
            cout << "=========== CLIENTE ========="<<endl; // Exibe dados do cliente
            cout << "Nome: " << clientes_espera[i].get_nomecliente() << endl; // Carregando da posição i os dados do cliente 
            cout << "Número de acompanhantes: " << clientes_espera[i].get_numeropessoas() << endl; 
            return true; // retorna true
        }
    }
    return false; // Caso não seja achado o cliente, retorna false.
}


Restaurante::~Restaurante(){ // Destrutor

}