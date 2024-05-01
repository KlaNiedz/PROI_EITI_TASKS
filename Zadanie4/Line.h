#pragma once
#include "Element.h"
class Line : public Element {
private:
	std::string name;
	std::string fill;
	int start_x;
	int start_y;
	int end_x;
	int end_y;

public:
	Line(const std::string& name, const std::string& fill, int start_x, int start_y, int end_x, int end_y);
	std::string to_svg() override;
};

