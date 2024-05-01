#include "Circle.h"
#include <iostream>
#include <string>


Circle::Circle(const std::string& name, const std::string& fill, int cx, int cy, int r) : Element(name, fill), cx(cx), cy(cy), r(r) {}

std::string Circle::to_svg() {
	return "<circle cx=\"" + std::to_string(cx) + "\"" + " cy=\"" + std::to_string(cy) + "\"" + " r=\"" + std::to_string(r) + "\"" + " fill=\"" + getFill() + "\"" + " />" + "\n";
}

