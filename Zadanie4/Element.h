#pragma once
#include <iostream>
#include <string>
class Element
{
private: 
	std::string Fill;
public:
	Element(const std::string& fill);
	std::string getFill() const;
	virtual std::string to_svg() = 0;
	virtual ~Element() {}
};

