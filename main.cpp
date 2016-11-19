#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "Viajante/MainViajante.h"
#include "FlujoDeRedes/MainFlujoDeRedes.h"
#include "mochila/Headers/MainMochila.h"

using namespace std;

int main() {
    try {
        MainViajante().run();
        MainFlujoDeRedes().run();
        MainMochila().run();

    } catch(string error) {
        std::cout << "***ERROR***: "<< error << std::endl;
    }

    return 0;
}