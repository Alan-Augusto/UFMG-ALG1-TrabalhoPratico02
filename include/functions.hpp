#include <iostream>
#include <string.h>
#include <vector>

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
    SubVetorzin(int Inpleft, int InpRight, double Inpsum);

    //Métodos
    //...
};

//FUNÇÕES DO ALGORITMO PRINCIPAL
SubVetorzin IntersectionMaxSum(vector<double> vet, int Inpleft, int midle, int InpRight);
SubVetorzin SubVetorMaxSum(vector<double> vet, int Inpleft, int InpRight);
