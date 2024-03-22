#include "CppUnitTest.h"

#include "../../Zadanie1/Date.h"
#include "../shop/Product.h"
#include "../shop/Receipt.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

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
			Receipt receipt("Jan", date_shop, products);
			Assert::AreEqual(shop_name, receipt.getShopName());
		}
	};
}
