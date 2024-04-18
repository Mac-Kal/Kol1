#include "zbior.h"

int main()
{
    std::list<double> elementy_listy = { 1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0,10.0 };
    std::vector<Zbior> vector_zbiorow;
    for (const auto& element : elementy_listy) {
        Zbior zbior = Zbior::konwersja_gora(element);
        vector_zbiorow.push_back(zbior);
    }
    Zbior zbior_do_porownania(10, 0.0, 1.0);
    Funktor predykat(zbior_do_porownania);
    auto iter = std::find_if(vector_zbiorow.begin(), vector_zbiorow.end(), predykat);
    if (iter != vector_zbiorow.end()) {
        std::cout << "jes";
    }
    else {
        std::cout << "niejes";
    }
}






Dla klasy Zbior z plików zbior.h i zbior.cpp:
1) Napisz konstruktor przenoszący i kopiujący operator =.Wyklucz pozostałe mechanizmy kopiowania / przenoszenia.
2) Napisz nieformalny mechanizm konwersji z typu double tworzący nową instancję zbioru o dolnej granicy równej 0, a górnej
równej przekazanej wartości.Mechanizm ten nie może być zwykłą(instancyjną) metodą klasy Zbiór.
3) Napisz kod main wypełniający wektor instancjami klasy Zbiór, na bazie listy 10 elementów typu double(każdy element listy
powinien być źródłem danych dla innej instancji typu Zbiór).Użyj napisanego wcześniej mechanizmu konwersji.
4) Zdefiniuj funktor, który będzie tworzony na bazie instancji typu Zbiór.Funktor powinien móc być używany jako predykat
jednoargumentowy, który będzie zwracał prawdę, jeśli przekazany mu argument typu Zbiór będzie miła zbliżoną średnią
(z wewnętrznych elementów) do zapisanej w nim instancji Zbioru.Przyjmij tolerancję 10 - 1 dla błędu porównania
zmiennoprzecinkowego.Zademonstruj działanie funktora na dowolnej funkcji z biblioteki <algorithm> przetwarzającej
wektor utworzony w punkcie 3.
