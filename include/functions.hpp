#include <iostream>
#include <string.h>

using namespace std;

//FUNÇÕES GERAIS
void Assert(bool x, string text);
char* checkLineArguments(int argc, char **argv, int x);

//CLASSES QUE AUXILIAM
class SubVetorzin{
    public:
    //Atributos
    int left;
    int right;
    double sum;
    
    //Construtores
    SubVetorzin();
    SubVetorzin(int Inpleft, int Inpright, double Inpsum);

    //Métodos
    //...
};

