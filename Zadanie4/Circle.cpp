#include "Circle.h"
#include <iostream>
#include <string>


Circle::Circle(const std::string& fill, int cx, int cy, int r) : Element( fill), cx(cx), cy(cy), r(r) 
{
	if (r <= 0 || fill.empty()) {
		std::cerr << "Error: Incorrect arguments for Circle constructor. Object creation skipped." << std::endl;
	}
}

std::string Circle::to_svg() {
	return "<circle cx=\"" + std::to_string(cx) + "\"" + " cy=\"" + std::to_string(cy) + "\"" + " r=\"" + std::to_string(r) + "\"" + " fill=\""
		+ getFill() + "\"" + " />" + "\n";
}

int Circle::getR()
{
	return r;
}

