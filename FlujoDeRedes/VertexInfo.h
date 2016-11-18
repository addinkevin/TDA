#ifndef TRABAJOPRACTICO2_VERTEXINFO_H
#define TRABAJOPRACTICO2_VERTEXINFO_H


class VertexInfo {
public:
    VertexInfo() {
    }

    VertexInfo(string description, int number, bool isProject) {
        this->description = description;
        this->isProject = isProject;
        this->number = number;
    }

    string description;
    bool isProject = false;
    int number = 0;
};


#endif //TRABAJOPRACTICO2_VERTEXINFO_H
