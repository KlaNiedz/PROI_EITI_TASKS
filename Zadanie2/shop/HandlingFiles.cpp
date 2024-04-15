#include "HandlingFiles.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Receipt.h"

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


void HandlingFiles::saveReceipt(const std::string& filename, Receipt my_receipt) {
	std::ofstream file(filename); // Open the file for writing
	if (file.is_open()) {
		file << my_receipt.getDescription();
		file.close(); // Close the file
		std::cout << "Description saved to file: " << filename << std::endl;
	}
	else {
		std::cerr << "Unable to open file: " << filename << std::endl;
	}
}

