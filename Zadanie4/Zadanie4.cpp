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
    std::unique_ptr<Element> circle1 = std::make_unique<Circle>("green", 150, 100, 80);
    std::unique_ptr<Element> rect1 = std::make_unique<Rect>(300, 100, "red");
    std::unique_ptr<Element> rect3 = std::make_unique<Rect>(300);
    std::unique_ptr<Element> rect2 = std::make_unique<Rect>(280, 180, "none", "blue", 10, 10);
    std::unique_ptr<Element> text1 = std::make_unique<Text>("white", 150, 125, 60, "middle", "SVG");
    std::unique_ptr<Element> text2 = std::make_unique<Text>("blue", 280, 180, 20, "end", "24.L");

    data.addElement(std::move(rect1));
    data.addElement(std::move(rect2));
    data.addElement(std::move(circle1));
    data.addElement(std::move(text1));
    data.addElement(std::move(text2));

    data.draw_to_svg("data.html");
    
    return 0;
}

