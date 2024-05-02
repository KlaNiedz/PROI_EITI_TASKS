#include "Element.h"
#include <iostream>


Element::Element(const std::string& fill)
{

	Fill = fill;
}


std::string Element::getFill() const
{
	return Fill;
}


