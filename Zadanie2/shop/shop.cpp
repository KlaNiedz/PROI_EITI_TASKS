// shop.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <algorithm> 
#include <vector>
#include "Receipt.h"
#include "Product.h"
#include "Amount.h"
#include "Weight.h"
#include "Price.h"
#include "HandlingFiles.h"
#include "../../Zadanie1/Date.h"


myUnit stringToUnit(const std::string& unitStr) {
    if (unitStr == "kg") {
        return myUnit::kg;
    }
    else if (unitStr == "piece") {
        return myUnit::piece;
    }
    else if (unitStr == "g") {
        return myUnit::g;
    }
    else {
        throw std::invalid_argument("Wrong Unit!: " + unitStr + " Available units are 'piece', 'kg' or 'g'.");
    }
}

myCurrency stringToCurrency(const std::string& currencyStr) {
    if (currencyStr == "PLN") {
        return myCurrency::PLN;
    }
    else if (currencyStr == "USD") {
        return myCurrency::USD;
    }
    else if (currencyStr == "EUR") {
        return myCurrency::EUR;
    }
    else {
        throw std::invalid_argument("Unknown currency: " + currencyStr);
    }
}

int main()
{
    try {
        std::string filename;
        std::cout << "Pass Filename: ";
        std::getline(std::cin, filename);
        HandlingFiles file(filename);
        std::vector<std::string> arguments = file.createReceipt();

        if (arguments.size() < 10) {
            throw std::invalid_argument("Usage: shop_name shop_day shop_month shop_year eatby_day eatby_month eatby_year amount_price currency amount_number amount_unit product_name product_producer product_number");

        }
       
        std::string shop_name = arguments[0];
        int shop_day = std::stoi(arguments[1]);
        myMonth shop_month = static_cast<myMonth>(std::stoi(arguments[2]));
        int shop_year = std::stoi(arguments[3]);
        Date date_shop(shop_day, shop_month, shop_year);

       
        //Creating list of products
        std::vector<Product> products;
        std::string my_unit;
        std::vector<std::string> my_products;
        for (int i = 4; i < arguments.size(); i += 10) {

            int eatby_day = std::stoi(arguments[i]);
            myMonth eatby_month = static_cast<myMonth>(std::stoi(arguments[i + 1]));
            int eatby_year = std::stoi(arguments[i+2]);
            Date eatbydate(eatby_day, eatby_month, eatby_year);
            double price_number = std::stod(arguments[i+3]);
            std::string price_currency = arguments[i + 4];
            if (i == 4) {
                my_unit = price_currency;
            }
            if (price_currency != my_unit) {
                throw WrongCurrencyException();
            }
            myCurrency converted_currency = stringToCurrency(price_currency);
            double amount_number = std::stod(arguments[i + 5]);
            std::string amount_unit = arguments[i + 6];
            myUnit amount_unit_converted = stringToUnit(amount_unit);
            Weight WeightOfProd(amount_number, amount_unit_converted);
            Price PriceOfProd(price_number, converted_currency);
            Amount amount(PriceOfProd, WeightOfProd);
            std::string product_name = arguments[i + 7];
            int cnt = std::count(arguments.begin(), arguments.end(), arguments[i + 7]);
            if (cnt > 1) {
                throw DuplicateProductException();
            }
            std::string product_producer = arguments[i + 8];
            int product_number = std::stoi(arguments[i + 9]);

            Product product(product_name.c_str(), amount, product_producer, product_number, eatbydate);
            products.push_back(product);
        }

        //Creating a Receipt object and adding product to it
        Receipt receipt(shop_name, date_shop, products);

        std::cout << "Shop: " << shop_name << std::endl;
        std::cout << "Sum of prices: " << receipt.getPriceSum() << std::endl;
        int size = receipt.getNumberOfProducts();
        std::cout << "Number of products bought: " << size << std::endl;

        //Printing out receipt
        for (Product element : receipt.getProducts()) {
            std::cout << element << std::endl;
        }

    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Invalid argument: " << e.what() << std::endl;
        return 1; 
    }
    catch (const DuplicateProductException& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
        return 1;
    }
    catch (const WrongUnitException& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
        return 1;
    }
    catch (const WrongCurrencyException& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}




