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
 /*   std::unique_ptr<Element> element = std::make_unique<Element>("Element", "blue");*/
    std::unique_ptr<Element> circle1 = std::make_unique<Circle>("circle", "green", 150, 100, 80);
    std::unique_ptr<Element> rect1 = std::make_unique<Rect>("rect", 300, 100, "red", "none", 0, 0);
    std::unique_ptr<Element> rect2 = std::make_unique<Rect>("rect", 280, 180, "none", "blue", 10, 10);
    std::unique_ptr<Element> text1 = std::make_unique<Text>("text", "white", 150, 125, 60, "middle", "SVG");
    std::unique_ptr<Element> text2 = std::make_unique<Text>("text", "blue", 280, 180, 20, "end", "24.L");


    data.addElement(std::move(rect1));
    data.addElement(std::move(rect2));
    data.addElement(std::move(circle1));
    data.addElement(std::move(text1));
    data.addElement(std::move(text2));


    //std::cout << "Name of the element: " << element->getName() << std::endl;
    data.draw_to_svg("dupa.html");
    
 
 

    return 0;
}

