#pragma once
#include <iostream>
#include <vector>
#include <string>

class HandlingFiles
{
private:
	std::string Filename;
public:
	HandlingFiles(std::string filename);
	std::vector<std::string> createReceipt();
};

