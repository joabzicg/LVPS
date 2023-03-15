/*
>Discente: Joab da Silva Bezerra
>Matrícula: 121110972
>Período: 21.1
>Curso: Engenharia Elétrica
>Disciplina: Técnicas de Programação
>Turma: 02
>Professor: Marcus Salerno
>Unidade 1: LVP 03

Descrição do lvp : O objetivo deste LVP é trabalhar com um programa que instancie um Circuito Elétrico e que seja capaz de fazer modificações com seus elementos.
*/

#include <iostream> // Bibliotecas padrões
#include <iomanip>
#include <locale>

using namespace std;


struct Resistor{ // struct capacitor para armazenar dados do resistor
    double voltage, current, resistance;
};

struct Capacitor{ // struct capacitor para armazenar dados do capacitor
    double capacitance, q_cap, voltage_module;
};

class E_circuit{ // classe E_circuit
    private: //atributos da classe
       Resistor r1, r2;
       Capacitor c1;
       double resistor1P, resistor2P, R1condutance, R2condutance, voltageR1, voltageR2 , capPEE, SeqR, PeqR;
    public: // metodos da classe
       void setVR(float, float); // metodos set para receber os valores para realizar os calculos
       void setVC(float);
       void setCurrentR(float, float);
       void setCharge(float);
       void calcResistor(); // metodos de calculo
       void calcResistorP();
       void calcRCondutance();
       void calcVoltageR();
       void calcCap();
       void calcCapPEE();
       void calcSeqR();
       void calcPeqR();
       double getResistor1(void); // metodos get para retornar os valores
       double getResistor2(void);
       double getResistor1P(void);
       double getResistor2P(void);
       double getR1Condutance(void);
       double getR2Condutance(void);
       double getvoltageR1(void);
       double getvoltageR2(void);
       double getCap(void);
       double getCapPEE(void);
       double getSeqR(void);
       double getPeqR(void);
};

//Funções set para atribuir valor aos atributos
void E_circuit::setVR(float VR1, float VR2){
    r1.voltage = VR1;
    r2.voltage = VR2;
}

void E_circuit::setVC(float volts){
    c1.voltage_module = volts;
}

void E_circuit::setCurrentR(float ampsR1, float ampsR2){
    r1.current = ampsR1;
    r2.current = ampsR2;
}

void E_circuit::setCharge(float charge){
    c1.q_cap = charge;
}


//calculo dos metodos com encapsulamento - isto significa que os calculos serao calculados somente com os valores fornecidos para os valores
void E_circuit::calcResistor(){
    r1.resistance=r1.voltage/r1.current;
    r2.resistance=r2.voltage/r2.current;    
}

void E_circuit::calcResistorP(){
    resistor1P=r1.resistance*(r1.current*r1.current);    
    resistor2P=r2.resistance*(r2.current*r2.current);  
}

void E_circuit::calcRCondutance(){
    R1condutance=1/r1.resistance;    
    R2condutance=1/r2.resistance;  
}

void E_circuit::calcVoltageR(){
    voltageR1 = r1.resistance*r1.current;  
    voltageR2 = r2.resistance*r2.current;  
}

void E_circuit::calcCap(){
    c1.capacitance = c1.q_cap/c1.voltage_module;  
}

void E_circuit::calcCapPEE(){
    capPEE = (c1.q_cap*c1.q_cap)/(2*c1.capacitance);    
}

void E_circuit::calcSeqR(){
    SeqR = r1.resistance+r2.resistance;
}

void E_circuit::calcPeqR(){
    PeqR = (r1.resistance*r2.resistance)/(r1.resistance+r2.resistance);    
}


//funcao para retornar os valores dos calculos:

double E_circuit::getResistor1(){
    return r1.resistance;     
}

double E_circuit::getResistor2(){
    return r2.resistance;     
}

double E_circuit::getResistor1P(){
    return resistor1P;
}
double E_circuit::getResistor2P(){
    return resistor2P;
}

double E_circuit::getR1Condutance(){
    return R1condutance;     
}

double E_circuit::getR2Condutance(){
    return R2condutance;     
}

double E_circuit::getvoltageR1(){
    return voltageR1;     
}

double E_circuit::getvoltageR2(){
    return voltageR2;     
}

double E_circuit::getCap(){
    return c1.capacitance;
}

double E_circuit::getCapPEE(){
    return capPEE;
}

double E_circuit::getSeqR(){
    return SeqR;
}

double E_circuit::getPeqR(){
    return PeqR;
}

// Função principal, para chamada das funções de calculo e impressão dos resultados
int main (){
    setlocale(LC_ALL,"Portuguese");
    
    E_circuit circuito; // Circuito como membro da classe E_circuit

    float vR1, vR2, vC1, iR1, iR2, c_charge; // Variáveis auxiliares

    cout<<"Bem vindo ao programa simulador de circuitos \n"<<endl; //dados de entrada
    cout<<"Digite a DDP do R1 volts: "<<endl;
    cin>>vR1;
    cout<<"Digite a corrente no R1 em amperes: "<<endl;
    cin>> iR1;
    cout<<"Digite a DDP do R2 volts: "<<endl;
    cin>>vR2;
    cout<<"Digite a corrente no R2 em amperes: "<<endl;
    cin>> iR2;
    cout<<"Digite a DDP do capacitor em V: "<<endl;
    cin>> vC1;
    cout<<"Digite a quantidade de carga do capacitor em C:"<<endl;
    cin>> c_charge;


    circuito.setCharge(c_charge); // chamando funções para setar valorse
    circuito.setVC(vC1);
    circuito.setCurrentR(iR1, iR2);
    circuito.setVR(vR1, vR2);
    circuito.calcResistor(); // chamando funções para calcular os valores
    circuito.calcResistorP();
    circuito.calcRCondutance();
    circuito.calcVoltageR();
    circuito.calcCap();
    circuito.calcCapPEE();
    circuito.calcSeqR();
    circuito.calcPeqR();

    cout<<fixed<<setprecision(2);
    cout<<"\n---R1---\nDDP: "<<vR1<<" V \nCorrente: "<<iR1<<" A\nA resistência R1 tem o valor de: "<<circuito.getResistor1()<<" Ohm"<<endl; // conjunto de Couts para impressão dos valores
    cout<<"A potência no resistor R1 tem o valor de: "<<circuito.getResistor1P()<<" Watts"<<endl;
    cout<<"A condutância no resistor R1 tem o valor de: "<<circuito.getR1Condutance()<<" S"<<endl;
    cout<<"A voltagem no resistor R1 tem o valor de: "<<circuito.getvoltageR1()<< " Volts \n"<<endl;
    cout<<"---R2---\nDDP: "<<vR2<<" V \nCorrente: "<<iR2<<" A\nA resistência R2 tem o valor de: "<<circuito.getResistor2()<<" Ohm"<<endl;
    cout<<"A potência no resistor R2 o valor de: "<<circuito.getResistor2P()<<" Watts"<<endl;
    cout<<"A condutância no resistor R2 tem o valor de: "<<circuito.getR2Condutance()<<" S"<<endl;
    cout<<"A voltagem no resistor R2 tem o valor de: "<<circuito.getvoltageR2()<< " Volts\n"<<endl;
    cout<<"---Capacitor---\nDDP: "<<vC1<<" V \nCarga: "<<c_charge<<" C\nO valor do capacitor é de: "<<circuito.getCap()<<" F"<<endl;
    cout<<"A energia potencial eletrostática do capacitor é igual a : "<<circuito.getCapPEE()<< " J\n"<<endl;
    cout<<"A resistência equivalente caso r1 e r2 estejam em série, é de : "<<circuito.getSeqR()<< " Ohms"<<endl;
    cout<<"A resistência equivalente caso r1 e r2 estejam em paralelo, é de : "<<circuito.getPeqR()<< " Ohms"<<endl;

    return 0;
}