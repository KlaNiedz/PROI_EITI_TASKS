// Zadanie4.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include "DataBase.h"
#include "Element.h"
#include "Circle.h"
#include "Rect.h"
#include "Line.h"
#include "Text.h"


int main()
{
    DataBase data;
    std::unique_ptr<Element> circle1 = std::make_unique<Circle>("circle1", "green", 150, 100, 80);
    std::unique_ptr<Element> rect1 = std::make_unique<Rect>("rect1", 300, 100, "red");
    std::unique_ptr<Element> rect4 = std::make_unique<Rect>("rect4", 400, 100, "red");
    std::unique_ptr<Element> rect3 = std::make_unique<Rect>("rect3", 300, 100);
    std::unique_ptr<Element> rect2 = std::make_unique<Rect>("rect2", 280, 180, "none", "blue", 10, 10);
    std::unique_ptr<Element> text1 = std::make_unique<Text>("text1", "white", 150, 125, 60, "middle", "SVG");
    std::unique_ptr<Element> text2 = std::make_unique<Text>("text2", "blue", 280, 180, 20, "end", "24.L");

    data.addElement(rect1);
    data.addElement(rect2);
    data.addElement(rect4);
    data.addElement(rect3);
    data.addElement(circle1);
    data.addElement(text1);
    data.addElement(text2);

    data.deleteElement("rect4");

    data.draw_to_svg("data.html");
    
    return 0;
}

