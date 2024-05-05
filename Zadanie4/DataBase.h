#pragma once
#include <vector>
#include <memory>
#include "Element.h"
class DataBase
{
private:
	std::vector<std::unique_ptr<Element>> Elements;
public:
	DataBase();
	DataBase(std::vector<std::unique_ptr<Element>> elements);
	void addElement(std::unique_ptr<Element>& elem);
	void deleteElement(std::string name);
	std::vector<std::unique_ptr<Element>>& getElements();
	void draw_to_svg(const std::string& filename);
};

