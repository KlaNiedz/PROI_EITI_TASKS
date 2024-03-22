// date_setter.cpp.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

//Proszę napisać klasę reprezentującą datę(dzień, miesiąc, rok).
//Dla klasy proszę przygotować konstruktor argumentowy oraz
//gettery i settery(metody umożliwiające dostęp do pól i ich modyfikację)
//dla wszystkich pól.Należy zapewnić sprawdzanie poprawności wprowadzanej 
//daty(np.nie można pozwolić na wpisanie daty 30.02.2020 lub 29.02.2025).
//Do reprezentacji miesiąca warto wykorzystać enum (w wersji tzw.„scoped enum”).
//Proszę przygotować kilka metod wyprowadzających datę
//w róznych formatach(także miesiąc słownie) 
//np. 23 / 03 / 2022, 23 maja 2020 albo poniedziałek 4.03.23.
//Proszę przetestować klasę dla kilku dat poprawnych i niepoprawnych
//(w tym zadaniu wyjątkowo wystarczy utworzenie kilku obiektów dat w funkcji main
//i wypisanie tych dat na standardowe wyjście).


#include <iostream>
#include "Date.h"

int main()
{
    Date first_date(20, myMonth::kwiecien, 2020);
    first_date.setDay(30);
    std::cout << "Month: " << first_date.monthToString(first_date.getMonth()) << std::endl;
    std::cout << "Formatted Date: " << first_date.PrintDate() << std::endl;
    std::cout << first_date.getDay() << std::endl;
    std::cout << "Wordly Date: " << first_date.printWordDate() << std::endl;

    Date invalid_date_1(31, myMonth::kwiecien, 2020);
    std::cout << "Formatted Date: " << invalid_date_1.PrintDate() << std::endl;
    Date invalid_date_2(29, myMonth::luty, 2025);
    std::cout << "Formatted Date: " << invalid_date_2.PrintDate() << std::endl;



    return 0;
}

