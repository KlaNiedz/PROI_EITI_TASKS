#pragma once
#include <iostream>
#include <string>
class Element
{
private: 
	std::string Name;
	std::string Fill;
public:
	Element(const std::string& name = "name", const std::string& fill = "none");
	std::string getName() const;
	std::string getFill() const;
	virtual std::string to_svg() = 0;
	virtual ~Element() {}
};

