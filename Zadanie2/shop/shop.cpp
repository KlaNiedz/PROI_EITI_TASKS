// shop.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <algorithm> 
#include "Receipt.h"
#include "Product.h"
#include "Amount.h"
#include "../../Zadanie1/Date.h"


int main(int argc, char* argv[])
{
    try {
        if (argc < 14) {
            throw std::invalid_argument("Usage: shop_name shop_day shop_month shop_year eatby_day eatby_month eatby_year amount_price amount_number amount_unit product_name product_producer product_number");

        }

        std::string shop_name = argv[1];
        int shop_day = std::stoi(argv[2]);
        myMonth shop_month = static_cast<myMonth>(std::stoi(argv[3]));
        int shop_year = std::stoi(argv[4]);
        Date date_shop(shop_day, shop_month, shop_year);

       
        //Creating list of products
        std::vector<Product> products;
        for (int i = 5; i < argc; i += 9) {
            int eatby_day = std::stoi(argv[i]);
            myMonth eatby_month = static_cast<myMonth>(std::stoi(argv[i + 1]));
            int eatby_year = std::stoi(argv[i+2]);
            Date eatbydate(eatby_day, eatby_month, eatby_year);
            double amount_price = std::stod(argv[i+3]);
            double amount_number = std::stod(argv[i + 4]);
            std::string amount_unit = argv[i + 5];
            Amount amount(amount_price, amount_number, amount_unit);

            std::string product_name = argv[i + 6];
            std::string product_producer = argv[i + 7];
            int product_number = std::stoi(argv[i + 8]);

            Product product(product_name.c_str(), amount, product_producer, product_number, eatbydate);
            products.push_back(product);
        }

        //Creating a Receipt object and adding product to it
        Receipt receipt(shop_name, date_shop, products);

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
    return 0;
}




