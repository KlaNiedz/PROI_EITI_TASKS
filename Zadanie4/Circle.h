#pragma once
#include "Element.h"
class Circle : public Element{
private:
	int cx;
	int cy;
	int r;
public:
	Circle(const std::string& name, const std::string& fill, int cx, int cy, int r);
	std::string to_svg() override;
	/*std::string getName() const override;*/
};

