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
		
		TEST_METHOD(TestReceiptInit)
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
		TEST_METHOD(TestAmountInit)
		{
			Amount bread_amount(5.20, 2, "piece");
			double bread_price = 5.20;
			double bread_number = 2;
			std::string bread_unit = "piece";
			Assert::AreEqual(bread_amount.getPrice(), bread_price);
			Assert::AreEqual(bread_amount.getNumber(), bread_number);
			Assert::AreEqual(bread_amount.getUnit(), bread_unit);
		}
		TEST_METHOD(TestCalculatePrice)
		{
			Amount bread_amount(5.20, 2, "piece");
			double price = 10.40;
			Assert::AreEqual(bread_amount.calculatePrice(), price);
		}
		TEST_METHOD(TestProductInit)
		{
			Date eatbydate(29, myMonth::kwiecien, 2020);
			Amount apple_amount(1.98, 1.5, "kg");
			Product apple("apple", apple_amount, "biedronka", 23, eatbydate);
			std::string name = "apple";
			double price = 1.98 * 1.5;
			std::string producer = "biedronka";
			Assert::AreEqual(apple.getName(), name);
			Assert::AreEqual(apple.getPrice(), price);
			Assert::AreEqual(apple.getProducer(), producer);
		}
		TEST_METHOD(TestDeleteProduct)
		{
			Date date_shop(20, myMonth::kwiecien, 2020);
			Date eatbydate1(29, myMonth::kwiecien, 2020);
			Date eatbydate2(22, myMonth::kwiecien, 2020);
			std::vector<Product> products;
			Receipt Receipt("Jan", date_shop, products);
			Amount bread_amount(5.20, 2, "piece");
			Product bread("bread", bread_amount, "goszczynski", 72, eatbydate1);
			Amount apple_amount(1.98, 1.5, "kg");
			Product apple("apple", apple_amount, "biedronka", 23, eatbydate2);
			Receipt.addProduct(bread);
			Receipt.addProduct(apple);
			Assert::AreEqual(Receipt.getNumberOfProducts(), 2);
			Receipt.deleteProduct("apple");
			Assert::AreEqual(Receipt.getNumberOfProducts(), 1);
		}
		TEST_METHOD(TestFindProduct) {
			Date date_shop(20, myMonth::kwiecien, 2020);
			Date eatbydate(29, myMonth::kwiecien, 2020);
			std::vector<Product> products;
			Receipt Receipt("Jan", date_shop, products);
			Amount apple_amount(1.98, 1.5, "kg");
			Product apple("apple", apple_amount, "biedronka", 23, eatbydate);
			Receipt.addProduct(apple);
			std::string spec_prod = Receipt.getSpecificProduct("apple");
			std::string product_compare = "There is a product named: apple";
			Assert::AreEqual(spec_prod, product_compare);
		}
	};
}
