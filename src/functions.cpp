#include <functions.hpp>

//_____FUNÇÕES GERAIS___
    //Maior SUbvetor entre 3
    SubVetorzin MaxSumOfThreeSubVet(SubVetorzin a, SubVetorzin b, SubVetorzin c){
        if(a.sum>=b.sum){
            if(a.sum>=c.sum){
                return a;
            }
            else{
                return c;
            }
        }
        else
        {
            if(b.sum>=c.sum){
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
    //ANÁLISE DO LADO ESQUERDO
        //Variáveis principais
        double sum = 0;
        double sumPartialAuxCount = 0;
        double LeftSum = -139157123; //Seta com um valor muito baixo para que não cause problemas
        int LeftID = middle; //Setamos a esqueda do subvetor como o meio dele - a priori
        
        //iterador começa no meio
        int i = middle;
        //Varremos o subvetor até a esquerda
        while(i >= Inpleft){
            //Fazemos a soma dos elementos
            sum = sum + vet[i];
            sumPartialAuxCount ++;
            //Comparamos com a última soma
            if (sum >= LeftSum){
                //Se a soma atual for maior que a última maior soma, atualizamos o valor da ultima maior soma
                LeftSum = sum;
                //Guardamos o ID do elemento que faz sentidoe star na soma
                LeftID = i;
                //Reajustamos a contagem parcial
                while(sumPartialAuxCount>LeftID){
                    sumPartialAuxCount--;
                }
            }
            //Redução do iterador
            i--;
        }
    //ANÁLISE DO LADO DIREITO
        //Reseta a soma temporária
        sum = 0;
        double RightSum = -139157123; //Pequeno valor para não prejudicart
        int RightID = middle;  //Setamos a direita do subvetor como o meio dele - a priori

        //iterador começa no meio
        int j = middle;
        //Varremos o subvetor até a direita
        while(j <= InpRight){
            //Fazemos a soma dos elementos
            sum = sum + vet[j];
             //Comparamos com a última soma
            if (sum >= RightSum) {
                //Se a soma atual for maior que a última maior soma, atualizamos o valor da ultima maior soma
                RightSum = sum;
                //Guardamos o ID do elemento que faz sentido estar na soma
                RightID = j;
            }
            //Acresce o iterador
            j++;
        }

    //CONCLUSEOS
        //Encontramos a soma dos elementos em interseção
        double middleSum = LeftSum + RightSum - vet[middle];

        //Criamos um subvetor para cada intervalo em questão
        SubVetorzin LeftSub(LeftID, middle, LeftSum);
        SubVetorzin RightSub(middle , RightID, RightSum);
        SubVetorzin MiddleSub(LeftID, RightID, middleSum);

        //Retornamos o subvetor com maior soma
        return MaxSumOfThreeSubVet(LeftSub, RightSub, MiddleSub);
}

SubVetorzin SubVetorMaxSum(vector<double> vet, int Inpleft, int InpRight){
    //CONDIÇÕES DE PARADA
        //Se o indicies se ultrapassarem
        if (Inpleft > InpRight) {
            SubVetorzin intervalo = {Inpleft, InpRight, -139157123 };
            return intervalo;
        }

        //Se os índicies se encontrarem  
        if (Inpleft == InpRight) {
            SubVetorzin intervalo = {Inpleft, InpRight, vet[Inpleft] };
            return intervalo;
        }

    //CASOS BASE
        //####--DIVISÃO E CONQUISTA--####
            //Encontramos o meio do vetor
            int MiddleVet = (Inpleft + InpRight) / 2;

            //Encontramos o subvetor de maior soma em cada lado
            SubVetorzin SubvetLeft = SubVetorMaxSum(vet, Inpleft, MiddleVet - 1);
            SubVetorzin SubvetRight = SubVetorMaxSum(vet, MiddleVet + 1, InpRight);
            //Encontramos o subvetor de maior soma na interseção entre os lados
            SubVetorzin SubvetMiddle = IntersectionMaxSum(vet, Inpleft, MiddleVet, InpRight);
            
        //Após ter os maiores subvetores em cada lado e na interseção, pegamos o maior entre eles
        return MaxSumOfThreeSubVet(SubvetMiddle, SubvetLeft, SubvetRight);
}

