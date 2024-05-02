#pragma once
#include "Element.h"
#include <string>
class Rect: public Element
{
private:
	int width;
	int height;
	std::string stroke;
	int x;
	int y;
public:
	Rect(int width = 0, int height = 0, const std::string& fill = "none", std::string stroke = "none", int x = 0, int y = 0);
	std::string to_svg() override;
};

