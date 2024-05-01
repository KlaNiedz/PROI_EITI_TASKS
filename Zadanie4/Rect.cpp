#include "Rect.h"
#include <iostream>


Rect::Rect(const std::string& name, int width, int height, const std::string& fill, std::string stroke, int x, int y) :
	Element(name, fill), width(width), height(height), stroke(stroke), x(x), y(y) {}

std::string Rect::to_svg() {
    std::string svg = "<rect ";
    svg += "x=\"" + std::to_string(x) + "\" ";
    svg += "y=\"" + std::to_string(y) + "\" ";
    svg += "width=\"" + std::to_string(width) + "\" ";
    svg += "height=\"" + std::to_string(height) + "\" ";
    svg += "fill=\"" + getFill() + "\" ";
    svg += "stroke=\"" + stroke + "\" ";
    svg += "/>\n";
    return svg;
}