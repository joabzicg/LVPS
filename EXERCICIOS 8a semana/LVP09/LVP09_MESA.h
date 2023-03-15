#ifndef LVP09_MESA_H // Início do cabeçalho do arquivo LVP09_MESA_H 
#define LVP09_MESA_H

class Mesa { // Criando uma classe chamada Mesa, contendo os atributos n_cadeiras, maximoinstancias e instanciascriadas.
    int n_cadeiras;
    static int maximoinstancias, contador; // Atributos do tipo int static para maximoinstancias, instanciascriadas. Em que maximoinstancias será previamente informado. 
public:
    Mesa(int = 0); // Construtor inicializando valor de n_cadeiras.
    static int get_maximoinstancias() ; // Métodos get para retornar valores dos atributos da  Classe
    static int get_contador() ;
    int get_ncadeiras() const;
    void set_ncadeiras(int);
    static void contador_instanciascriadas(); // Método contador para adicionar +1 ao atributo instanciascriadas ao ser chamado na main
    ~Mesa(); // Destrutor
};

#endif //LVP09_MESA_H