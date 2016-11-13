#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "Viajante/MainViajante.h"
#include "FlujoDeRedes/MainFlujoDeRedes.h"

using namespace std;


int main() {
    try{
        std::cout << "Hello, World!" << std::endl;

        //MainViajante().run();
        MainFlujoDeRedes().run();

    } catch(string error) {
        std::cout << error;
    }
    return 0;
}
