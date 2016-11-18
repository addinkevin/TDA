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

        // Mochila test
        Mochila mochila;

    } catch(string & error) {
        std::cout << "***ERROR***: "<< error << endl;
    }
    return 0;
}
