#include "Text.h"
#include <string>
#include <iostream>

Text::Text(const std::string& fill, int x, int y, int font_size, std::string text_anchor, std::string inside)
	: Element(fill), x(x), y(y), font_size(font_size), text_anchor(text_anchor), inside(inside)
{
	if (font_size <= 0 || fill.empty() || text_anchor.empty() || inside.empty() || text_anchor == "" || inside == "") {
		std::cerr << "Error: Incorrect arguments for Text constructor. Object creation skipped." << std::endl;
	}
}

int Text::getX() const
{
	return x;
}

std::string Text::to_svg() {
	return "<text x=\"" + std::to_string(x) + "\"" + " y=\"" + std::to_string(y) + "\"" + " font-size=\"" + std::to_string(font_size) + "\""
		+ " text-anchor=\"" + text_anchor + "\"" + " fill=\"" + getFill() + "\"" + ">" + inside + "</text>\n";
}