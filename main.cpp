#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "Viajante/MainViajante.h"
#include "FlujoDeRedes/MainFlujoDeRedes.h"
#include "Viajante/ParserTSPFile.h"
#include "Viajante/Types.h"
#include "Viajante/TSPTest.h"
#include "mochila/Headers/Mochila.h"

using namespace std;

int main() {
    try{
        std::cout << "Hello, World!" << std::endl;

        //MainViajante().run();
        //MainFlujoDeRedes().run();

        //Mochila test easy instances
        string rutaEasy1= "./mochila/files/knapPI_1_50_1000.csv";
        string rutaEasy2= "./mochila/files/knapPI_2_50_1000.csv";
        string rutaEasy3= "./mochila/files/knapPI_3_50_1000.csv";
        string rutaEasy4= "./mochila/files/knapPI_4_50_1000.csv";
        string rutaEasy5= "./mochila/files/knapPI_5_50_1000.csv";
        string rutaEasy6= "./mochila/files/knapPI_6_50_1000.csv";
        string rutaEasy7= "./mochila/files/knapPI_9_50_1000.csv";

        // Mochila test hard instances
        string rutaHard1= "./mochila/files/knapPI_16_100_1000.csv";
        string rutaHard2 = "./mochila/files/knapPI_16_500_1000.csv";
        string rutaHard3 = "./mochila/files/knapPI_16_1000_1000.csv";
        Mochila* mochila = new Mochila(rutaHard1);

    } catch(string & error) {
        std::cout << "***ERROR***: "<< error << endl;
    }
    return 0;
}
