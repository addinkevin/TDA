//
// Created by kevin on 10/10/16.
//

#include "SVGDrawer.h"

SVGDrawer::SVGDrawer(std::string fileName, int width, int height) {
    this->file = std::ofstream(fileName);
    this->width = width;
    this->height = height;

    this->file << "<svg id=\"grafo\" xmlns=\"http://www.w3.org/2000/svg\" ";
    this->file << "width=\"" << width << "\" height=\"" << height << "\">";
    this->file << std::endl;
}

SVGDrawer::~SVGDrawer() {
    this->file << "</svg>" << std::endl;
    this->file.close();
}

void SVGDrawer::drawRectangleWithMark(int x, int y, int width, int height, std::string color, std::string colorMark) {
    this->file << "<g><rect x=\"" << x << "\" y=\"" << y << "\" width=\"" << width << "\" height=\"" << height << "\" ";
    this->file << "fill=\"" << color << "\" stroke=\"pink\"/>";
    this->file << "<circle cx=\"" << x + width/2 << "\" cy=\"" << y + height/2 << "\" r=\"" << std::min(width,height)/8 << "\" ";
    this->file << "fill=\"" << colorMark << "\" stroke=\"black\" stroke-width=\"3\" /> </g>";
    this->file << std::endl;

}

void SVGDrawer::drawRectangle(int x, int y, int width, int height, std::string color) {
    this->file << "<rect x=\"" << x << "\" y=\"" << y << "\" width=\"" << width << "\" height=\"" << height << "\" ";
    this->file << "fill=\"" << color << "\" stroke=\"pink\"/>";
    this->file << std::endl;
}
