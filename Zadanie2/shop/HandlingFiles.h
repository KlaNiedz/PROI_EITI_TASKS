#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Receipt.h"

class HandlingFiles
{
private:
	std::string Filename;
public:
	HandlingFiles(std::string filename);
	std::vector<std::string> createReceipt();  
	void saveReceipt(const std::string& filename, Receipt my_receipt);  //niespójne - mamy pole Filename
	//void loadReceipt(const std::string& filename, Receipt& my_receipt);
};

