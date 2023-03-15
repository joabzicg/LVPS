#include "LVP09_MESA.h" // Incluindo arquivo de cabeçalho LVP09_MESA.h

int Mesa::maximoinstancias = 10; // Inicializando o static maximoinstancias com o valor 10

int Mesa::contador = 0; // Inicializando o static Instanciascriadas com o valor 0

Mesa::Mesa(int n_cadeiras){ // Construtor inicializando o objeto Mesa com valores iniciais.
    this->n_cadeiras = n_cadeiras;
}

void Mesa::contador_instanciascriadas(){ // Método para contar as instancias criadas.
    contador++; // Ao método ser chamado, adiciona +1 ao atributo instanciascriadas. 
} 

int Mesa::get_contador() { // Métodos get para retornar valores dos atributos da classe Mesa
    return contador;
}

int Mesa::get_maximoinstancias() {
    return maximoinstancias;
}

int Mesa::get_ncadeiras() const{
    return n_cadeiras;
}


void Mesa::set_ncadeiras(int ncadeiras){ // Método para setar o atributo n_cadeiras
    n_cadeiras = ncadeiras;
}


Mesa::~Mesa(){ // Destrutor

}