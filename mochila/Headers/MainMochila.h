//
// Created by kevin on 11/13/16.
//

#ifndef TRABAJOPRACTICO2_MAINMOCHILA_H
#define TRABAJOPRACTICO2_MAINMOCHILA_H
#include <iostream>
#include "Parser.h"
#include <list>
using namespace std;

class MainMochila {
public:
    int run() {
        Parser* parser = new Parser();
        list<Stage>* lista = parser->getListOfStages("/home/jorlando/test.csv");
        cout << "size lista " << (lista)->size()<< endl;
        for (list<Stage>::iterator it=lista->begin(); it != lista->end(); ++it){
        cout << "ES EL STAGE" <<  it->name << endl;
        (*it).print();
    }

};


#endif //TRABAJOPRACTICO2_MAINMOCHILA_H
