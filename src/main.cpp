#include <functions.hpp>

using namespace std;

int main(int argc,char ** argv){

    int NumFriends = -1;
    int NumShows = -1;
    //Loop de leitura
    while( (cin >> NumFriends) && (cin >> NumShows) ){
        Assert(((NumFriends >=0) && (NumFriends <= 50)), "Incompatible number of friends");
        Assert(((NumShows >=0) && (NumShows <=100000)), "Incompatible number of shows");
        
        //Fim do arquivo é marcado por "0 0"
        Assert(((NumFriends!=0) && (NumShows!=0)), "");

        //De posse dos valores, realiza um loop preenchendo cada um dos valores dos shows
        //Vetor de com o somatorio das notas de cada show
        vector<double> Valuations = vector<double>(NumShows, 0);

        //Passa em cada linha referente às notas de um amigo
        for(int i = 0; i<NumFriends; i++){
            //recolhe as notas desse amigo e soma no show
            for(int j = 0; j<NumShows; j++){
                double value = 0;
                cin >> value;
                Assert(((value<=5)&&(value>= (-5))),"invalid assessment!");

                //Soma o valor no somatório do show
                Valuations[j]+= value;
            }
        }

        //Aplica o algoritmo de subvetor de soma máxima
        SubVetorzin SubVetMaxSum = SubVetorMaxSum(Valuations, 0, (Valuations.size()) - 1);
        //Imprime o intervalo em que se encontra o subvetor de maior soma
        cout << SubVetMaxSum.left + 1 << " " << SubVetMaxSum.right + 1 << endl;

    }
        
    return 0;
}