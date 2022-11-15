#include <functions.hpp>

//_____FUNÇÕES GERAIS___
    //Maximo de 3
    double maximus (double a, double b, double c){
        if(a>=b){
            if(a>=c){
                return a;
            }
            else{
                return c;
            }
        }
        else
        {
            if(b>=c){
                return b;
            }
            else{
                return c;
            }
        }
    }
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

SubVetorzin::SubVetorzin(int Inpleft, int InpRight, double InpSum){
    right = InpRight;
    left = Inpleft;
    sum = InpSum;
}

//_____ALGORITMO - SUBVETOR DE SOMA MAXIMA_______
SubVetorzin IntersectionMaxSum(vector<double> vet, int Inpleft, int middle, int InpRight){
    double sum = 0;
    double LeftSum = -139157123;
    int LeftID = middle;
    
    /*
    int i = middle;
    while(i >= Inpleft){
        sum = sum + vet[i];
        if (sum > LeftSum){
            LeftSum = sum;
            LeftID = i;
        }

        i--;
    }
    */

    for (int i = middle; i >= Inpleft; i--) {
        sum = sum + vet[i];
        if (sum > LeftSum){
            LeftSum = sum;
            LeftID = i;
        }
    }

    sum = 0;
    double RightSum = -139157123;
    int RightID = middle;
    for (int i = middle; i <= InpRight; i++) {
        sum = sum + vet[i];
        if (sum > RightSum) {
            RightSum = sum;
            RightID = i;
        }
    }

    double middleSum = LeftSum + RightSum - vet[middle];
    double bigger = maximus(middleSum, LeftSum, RightSum);
    
    SubVetorzin intervalo;
    
    if (bigger == middleSum) {
        intervalo = { LeftID, RightID, middleSum };
    }
    else if (bigger == LeftSum) {
        intervalo = { LeftID, middle, LeftSum };
    } 
    else {
        intervalo = { middle , RightID, RightSum };
    }
    return intervalo;
}

SubVetorzin SubVetorMaxSum(vector<double> vet, int Inpleft, int InpRight){
    if (Inpleft > InpRight) {
        SubVetorzin intervalo = {Inpleft, InpRight, 0 };
        return intervalo;
    }

    if (Inpleft == InpRight) {
        SubVetorzin intervalo = {Inpleft, InpRight, vet[Inpleft] };
        return intervalo;
    }

    int m = (Inpleft + InpRight) / 2;

    SubVetorzin SubvetLeft = SubVetorMaxSum(vet, Inpleft, m - 1);
    SubVetorzin SubvetRight = SubVetorMaxSum(vet, m + 1, InpRight);
    SubVetorzin SubvetMiddle = IntersectionMaxSum(vet, Inpleft, m, InpRight);
    double bigger = maximus(SubvetMiddle.sum, SubvetLeft.sum, SubvetRight.sum);

    if (bigger == SubvetMiddle.sum) {
        return SubvetMiddle;
    } else if (bigger == SubvetLeft.sum) {
        return SubvetLeft;
    } else {
        return SubvetRight;
    }
}

