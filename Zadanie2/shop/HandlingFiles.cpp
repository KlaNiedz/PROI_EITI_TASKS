#include "HandlingFiles.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

HandlingFiles::HandlingFiles(std::string filename)
{
	Filename = filename;
}

std::vector<std::string> HandlingFiles::createReceipt()
{
	std::fstream myFile;
	myFile.open(Filename, std::ios::in);
	std::vector<std::string>myArgs;


	if (myFile.fail()) {
		throw std::invalid_argument("Error opening file.");
	}
	if (myFile.is_open()) {
		std::string line;
		while (std::getline(myFile, line)) {
			myArgs.push_back(line);

		}
		myFile.close();
		return myArgs;
	}
}

