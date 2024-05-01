#include "Element.h"
#include <iostream>


Element::Element(const std::string& name, const std::string& fill)
{
	Name = name;
	Fill = fill;
}

std::string Element::getName() const
{
	return Name;
}

std::string Element::getFill() const
{
	return Fill;
}


