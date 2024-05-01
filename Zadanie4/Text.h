#pragma once
#include "Element.h"
class Text:
    public Element
{
private:
	std::string stroke;
	int x;
	int y;
	int font_size;
	std::string text_anchor;
	std::string inside;
public:
	Text(const std::string& name, const std::string& fill, int x, int y, int font_size, std::string text_anchor, std::string inside);
	std::string to_svg() override;
};

