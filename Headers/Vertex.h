#ifndef TDA_VERTEX_H
#define TDA_VERTEX_H

class Vertex {
public:
    Vertex()  {}
    Vertex(int number, int x, int y) {
        this->x = x;
        this->y = y;
        this->number = number;
    }

    int number;
    int x;
    int y;
};

#endif //TDA_VERTEX_H
