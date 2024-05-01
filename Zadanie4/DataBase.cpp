#include "DataBase.h"
#include <iostream>
#include <vector>
#include <fstream>

DataBase::DataBase() : Elements() {}
DataBase::DataBase(std::vector<std::unique_ptr<Element>> elements) : Elements(std::move(elements)) {
}

void DataBase::addElement(std::unique_ptr<Element> elem) {
	Elements.push_back(std::move(elem));
}

void DataBase::deleteElement(const std::unique_ptr<Element> elem){
	auto it = std::find_if(Elements.begin(), Elements.end(), [&elem](const std::unique_ptr<Element>& e) {
		return e.get() == elem.get();
		});
	if (it != Elements.end()) {
		Elements.erase(it);
	}
}

std::vector<std::unique_ptr<Element>>& DataBase::getElements()
{
	return Elements;
}

void DataBase::draw_to_svg(const std::string& filename) {
	std::string text = "<svg version=\"1.1\"\n"
                      "width=\"300\" height=\"200\"\n"
		"xmlns=\"http://www.w3.org/2000/svg\"> \n";
	for (int i = 0; i < Elements.size(); i++) {
		Element* first_element = Elements[i].get();
		text += first_element->to_svg();

	}
	text += "</svg>";
	std::ofstream file(filename);
	if (file.is_open()) {
		file << text;
		file.close();
		std::cout << "Description saved to file: " << filename << std::endl;
	}
	else {
		std::cerr << "Unable to open file: " << filename << std::endl;
	}
	
}