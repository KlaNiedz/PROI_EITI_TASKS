#pragma once
#include "Element.h"
class Line : public Element {
private:
	int start_x;
	int start_y;
	int end_x;
	int end_y;

public:
	Line(const std::string& name = "line", const std::string & fill = "none", int start_x = 0, int start_y = 0, int end_x = 0, int end_y = 0);
	std::string to_svg() override;
};

