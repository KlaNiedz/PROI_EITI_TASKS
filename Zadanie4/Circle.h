#pragma once
#include "Element.h"
class Circle : public Element{
private:
	int cx;
	int cy;
	int r;
public:
	Circle(const std::string& name = "circle", const std::string& fill = "none", int cx = 0, int cy = 0, int r = 0);
	std::string to_svg() override;
	int getR();
	
};

