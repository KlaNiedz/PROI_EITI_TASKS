#include "Line.h"
#include <iostream>


Line::Line(const std::string& fill, int start_x, int start_y, int end_x, int end_y)
    : Element(fill), start_x(start_x), start_y(start_y), end_x(end_x), end_y(end_y) {}

std::string Line::to_svg() {
    return "<line x1=\"" + std::to_string(start_x) + "\" y1=\"" + std::to_string(start_y) + "\" x2=\"" + std::to_string(end_x) + 
        "\" y2=\"" + std::to_string(end_y) + "\" fill=\"" + getFill() + "\" />\n";
}