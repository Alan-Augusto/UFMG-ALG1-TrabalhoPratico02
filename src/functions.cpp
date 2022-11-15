#include <functions.hpp>

//_____FUNÇÕES GERAIS___

    //Conferências gerais
    void Assert(bool x, string text){
        if(!x){
            if(text == ""){
                cout << text;
                exit(0);
            }
            cout << text << endl;
            exit(0);
        }
    }

    //ler a linha de comando
    char* checkLineArguments(int argc, char **argv, int x){
        if(argc < 2){
            cout << "--------Few arguments---------" << endl;
            cout << "---provide the file address---" << endl;
            exit(0);
        }
        return argv[x];
    }

//_____CLASSE SUBVETORZIN_____
SubVetorzin::SubVetorzin(){
    right = 0;
    left = 0;
    sum = 0;
} 

SubVetorzin::SubVetorzin(int Inpleft, int Inpright, double Inpsum){
    right = Inpleft;
    left = Inpright;
    sum = Inpsum;
}