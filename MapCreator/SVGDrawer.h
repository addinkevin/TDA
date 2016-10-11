//
// Created by kevin on 10/10/16.
//

#ifndef TDA_SVGDRAWER_H
#define TDA_SVGDRAWER_H

#include <string>
#include <fstream>

class SVGDrawer {
private:
    std::ofstream file;
    int height;
    int width;
public:
    SVGDrawer(std::string fileName, int width, int height);
    ~SVGDrawer();

    void drawRectangle(int x, int y, int width, int height, std::string color);
    void drawRectangleWithMark(int x, int y, int width, int height,std::string color, std::string colorMark);
};


#endif //TDA_SVGDRAWER_H
