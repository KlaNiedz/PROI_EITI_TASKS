#include "Rect.h"
#include <iostream>


Rect::Rect(const std::string& name, int width, int height, const std::string& fill, std::string stroke, int x, int y) :
	Element(name, fill), width(width), height(height), stroke(stroke), x(x), y(y) 
{
    if (width <= 0 || height <= 0 || fill.empty()) {
        std::cerr << "Error: Incorrect arguments for Rect constructor. Object creation skipped." << std::endl;
    }
}

std::string Rect::to_svg() {
    return "<rect x=\"" + std::to_string(x) + "\" " + "y=\"" + std::to_string(y) + "\" " + "width=\"" + std::to_string(width) + "\" " +
        "height=\"" + std::to_string(height) + "\" " + "fill=\"" + getFill() + "\" " + "stroke=\"" + stroke + "\" " + "/>\n";
}