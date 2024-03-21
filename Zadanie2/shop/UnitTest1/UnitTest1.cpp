#include "pch.h"
#include "CppUnitTest.h"
#include "../../shop/shop/Receipt.h"
#include "../../shop/shop/Product.h"
#include "../../../Zadanie1/date_setter.cpp/date_setter.cpp/Date.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace ;




namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestClassInit)
		{
			std::string shop_name = "Jan";
			Date date_shop(20, myMonth::kwiecien, 2020);
			Date eatbydate(29, myMonth::kwiecien, 2020);
			std::vector<Product> products;
			Receipt recepit("Jan", date_shop, products);
			Assert::AreEqual(shop_name, recepit.getShopName());

		}
	};
}
