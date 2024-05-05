#include "CppUnitTest.h"
#include "../Zadanie4/Element.h"
#include "../Zadanie4/DataBase.h"
#include "../Zadanie4/Circle.h"
#include "../Zadanie4/Line.h"
#include "../Zadanie4/Rect.h"
#include "../Zadanie4/Text.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestCreateSvgCircle)
		{
			
			std::unique_ptr<Element> circle1 = std::make_unique<Circle>("circle1", "green", 150, 100, 80);
			std::string text_circle = circle1->to_svg();
		
			std::string text_check = "<circle cx=\"150\" cy=\"100\" r=\"80\" fill=\"green\" />\n";
			Assert::AreEqual(text_circle, text_check);

		}

		TEST_METHOD(TestCreateSvgRect)
		{
			std::unique_ptr<Element> rect1 = std::make_unique<Rect>("rect1", 300, 100, "red", "none", 0, 0);
			std::string text_rect = rect1->to_svg();
			std::string text_check = "<rect x=\"0\" y=\"0\" width=\"300\" height=\"300\" fill=\"red\" stroke=\"none\" />\n";
			Assert::AreEqual(text_rect, text_check);

		}

		TEST_METHOD(TestCreateSvgText)
		{
			std::unique_ptr<Element> text1 = std::make_unique<Text>("text1", "white", 150, 125, 60, "middle", "SVG");
			std::string text_text = text1->to_svg();
			std::string text_check = "<text x=\"150\" y=\"125\" font-size=\"60\" text-anchor=\"middle\" fill=\"white\" />\n";
			Assert::AreEqual(text_text, text_check);
		}
		TEST_METHOD(TestAddElement)
		{
			DataBase data;
			std::unique_ptr<Element> circle1 = std::make_unique<Circle>("circle", "green", 150, 100, 80);
			data.addElement(std::move(circle1));
			std::vector<std::unique_ptr<Element>> all_elem = data.getElements();
			Element* first_elem = all_elem[0].get();
			std::string color = "green";
			Assert::AreEqual(first_elem->getFill(), color);
		}

		TEST_METHOD(TestDeleteElement)
		{
			DataBase data;
			std::unique_ptr<Element> circle1 = std::make_unique<Circle>("circle", "green", 150, 100, 80);
			data.addElement(std::move(circle1));
			std::vector<std::unique_ptr<Element>> all_elem = data.getElements();
			data.deleteElement("circle");
			std::vector<std::unique_ptr<Element>> all_elem_after = data.getElements();
			Assert::AreNotEqual(all_elem, all_elem_after);
		}

		TEST_METHOD(TestCheckR)
		{
			std::unique_ptr<Circle> circle1 = std::make_unique<Circle>("circle1", "green", 150, 100, 80);
			int radius = 80;
			Assert::AreEqual(circle1.get()->getR(), radius);
		}
		
	};
}
