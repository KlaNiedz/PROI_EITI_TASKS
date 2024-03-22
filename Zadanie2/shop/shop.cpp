// shop.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <algorithm> 
#include "Receipt.h"
#include "Product.h"
#include "../../Zadanie1/Date.h"

int main()
{
    Date date_shop(20, myMonth::kwiecien, 2020);
    Date eatbydate1(29, myMonth::kwiecien, 2020);
    std::vector<Product> products;
    

    Receipt FirstReceipt("Jan", date_shop, products);
    Product bread("bread", 1, "goszczynski", 72, eatbydate1);
    FirstReceipt.addProduct(bread);
    std::cout<<date_shop.PrintDate()<<std::endl;
    std::cout << eatbydate1.PrintDate() << std::endl;
    Date eatbydate2(22, myMonth::kwiecien, 2020);
    Product apple("apple", 3, "biedronka", 23, eatbydate2);

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
    return 0;
}

