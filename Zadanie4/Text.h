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
	Text(const std::string& name="text", const std::string & fill = "none", int x = 0, int y = 0, int font_size = 0, std::string text_anchor = "", std::string inside = "");
	int getX() const;
	std::string to_svg() override;
};

