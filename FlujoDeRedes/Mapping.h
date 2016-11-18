#ifndef TRABAJOPRACTICO2_MAPPING_H
#define TRABAJOPRACTICO2_MAPPING_H

#include <map>
#include "Edge.h"

using namespace std;

// El mapeo se realiza para obtener mejores tiempos, y no estar creando el grafo residual en cada iteración del algoritmo
// de Ford-Fulkerson.
class Mapping {
public:
    map<Edge*, pair<Edge*,Edge*>> mapEdgeGToResidualG;
    map<Edge*, Edge*> mapEdgeResidualGToEdgeG;
    map<Edge*, bool> isEdgeResidualForward;

    Mapping() {

    }
};


#endif //TRABAJOPRACTICO2_MAPPING_H
