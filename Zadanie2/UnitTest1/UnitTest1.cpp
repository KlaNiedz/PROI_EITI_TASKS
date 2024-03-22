#include "CppUnitTest.h"

#include "../../Zadanie1/Date.h"
#include "../shop/Product.h"
#include "../shop/Receipt.h"
#include "../shop/Amount.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestClassInit)
		{
			std::string shop_name = "Jan";
			int year = 2020;
			Date date_shop(20, myMonth::kwiecien, 2020);
			std::vector<Product> products;
			Receipt receipt("Jan", date_shop, products);
			Assert::AreEqual(shop_name, receipt.getShopName());
			Assert::AreEqual(year, date_shop.getYear());
		}
		TEST_METHOD(TestAddProduct) 
		{
			std::string product_name = "apple";
			Date date_shop(20, myMonth::kwiecien, 2020);
			Date eatbydate(29, myMonth::kwiecien, 2020);
			std::vector<Product> products;
			Receipt receipt("Jan", date_shop, products);
			Amount apple_amount(1.98, 1.5, "kg");
			Product apple("apple", apple_amount, "biedronka", 23, eatbydate);
			receipt.addProduct(apple);
			std::string element = receipt.getProducts().back().getName();
			Assert::AreEqual(product_name, element);
		}

	};
}
