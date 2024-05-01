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
	Rect(const std::string& name, int width, int height, const std::string& fill, std::string stroke, int x, int y);
	std::string to_svg() override;
};

