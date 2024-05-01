#include "Text.h"
#include <string>
#include <iostream>

Text::Text(const std::string& name, const std::string& fill, int x, int y, int font_size, std::string text_anchor, std::string inside)
	: Element(name, fill), x(x), y(y), font_size(font_size), text_anchor(text_anchor), inside(inside){}

std::string Text::to_svg() {
	return "<text x=\"" + std::to_string(x) + "\"" + " y=\"" + std::to_string(y) + "\"" + " font-size=\"" + std::to_string(font_size) + "\"" + " text-anchor=\"" + text_anchor +
		"\"" + " fill=\"" + getFill() + "\"" + ">" + inside + "</text>\n";
}