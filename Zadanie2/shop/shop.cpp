// shop.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include "Receipt.h"
#include "Product.h"
#include "../../../Zadanie1/date_setter.cpp/date_setter.cpp/Date.h"

int main()
{
    Date date_shop(20, myMonth::kwiecien, 2020);
    Date eatbydate(29, myMonth::kwiecien, 2020);
    std::vector<Product> products;
    

    Receipt FirstReceipt("Jan", date_shop, products);
    Product chleb("chleb", 1, "goszczynski", 69, eatbydate);
    FirstReceipt.addProduct(chleb);
    std::cout<<date_shop.PrintDate()<<std::endl;
    std::cout << eatbydate.PrintDate() << std::endl;
    return 0;
}

