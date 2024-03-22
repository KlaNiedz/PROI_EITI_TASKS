// shop.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <algorithm> 
#include "Receipt.h"
#include "Product.h"
#include "Amount.h"
#include "../../Zadanie1/Date.h"

int main()
{
    Date date_shop(20, myMonth::kwiecien, 2020);
    Date eatbydate1(29, myMonth::kwiecien, 2020);

    std::vector<Product> products;
    Receipt FirstReceipt("Jan", date_shop, products);


    try {
        Amount bread_amount(5.20, 2, "piece");
        Product bread("bread", bread_amount, "goszczynski", 72, eatbydate1);
        FirstReceipt.addProduct(bread);
        std::cout<<date_shop.PrintDate()<<std::endl;
        std::cout << eatbydate1.PrintDate() << std::endl;

    }
    catch (const char * unitException) {
        std::cout << "Exception: " << unitException << std::endl;
    }

    Date eatbydate2(22, myMonth::kwiecien, 2020);
    Amount apple_amount(1.98, 1.5, "kg");
    Product apple("apple", apple_amount, "biedronka", 23, eatbydate2);

    FirstReceipt.addProduct(apple);
    for (Product element : FirstReceipt.getProducts()) {
        std::cout << element.getName() << std::endl;
    }
    std::cout << apple.getName() << std::endl;
 
   // FirstReceipt.deleteProduct(apple);
    for (Product element : products) {
        std::cout << element.getName() << std::endl;
    }

    int size = FirstReceipt.getNumberOfProducts();
    std::cout << "Number of products bought: " << size << std::endl;

    std::string spec_prod = FirstReceipt.getSpecificProduct("apple");
    std::cout << spec_prod << std::endl;
    
    try {
        Date eatbydate3(4, myMonth::maj, 2021);
        Amount apple2_amount(2, 1.2, "kg");
        Product apple2("apple", apple2_amount, "biedronka", 23, eatbydate3);
        FirstReceipt.addProduct(apple2);
    }
    catch (const char * addException) {
        std::cout << "Exception: " << addException << std::endl;
    }
    return 0;
}

