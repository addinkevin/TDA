//
// Created by kevin on 11/13/16.
//

#ifndef TRABAJOPRACTICO2_MAPPING_H
#define TRABAJOPRACTICO2_MAPPING_H

#include <map>
#include "Edge.h"

using namespace std;

class Mapping {
private:

public:
    map<Edge*, pair<Edge*,Edge*>> mapEdgeGToResidualG;
    map<Edge*, Edge*> mapEdgeResidualGToEdgeG;
    map<Edge*, bool> isEdgeResidualForward;

    Mapping();
};


#endif //TRABAJOPRACTICO2_MAPPING_H
