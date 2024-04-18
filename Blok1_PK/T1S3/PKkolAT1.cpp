#include "zbior.h"

int main() {
	std::list<double> lista;
	std::list<double> lista_do_4 = {0.1,0.2,0.3,0.4,0.5};
	std::list<double> lista_do_4_false = { 0.1,0.2,0.35,0.4,0.5 };
	std::random_device rd;
	std::mt19937 rand_liczba(rd());
	std::uniform_int_distribution<int> wielkosc(10, 20);
	std::uniform_real_distribution<double> zakres_dolna(0.0, 10.0);
	std::uniform_real_distribution<double> zakres_gorna(10.0, 20.0);
	int liczba_elementow = wielkosc(rand_liczba);
	for (size_t i = 0; i < liczba_elementow; i++) {
		
		Zbior zbior(liczba_elementow, zakres_dolna(rand_liczba), zakres_gorna(rand_liczba));
		lista.push_back(static_cast<double>(zbior));
	}
	for (const auto& wynik : lista) {
		std::cout << wynik << "\n";
	}
	Funktor funktor(0.3);
	auto iter = std::find_if(lista_do_4.begin(), lista_do_4.end(), funktor);
	auto iter_2 = std::find_if(lista_do_4_false.begin(), lista_do_4_false.end(), funktor);
	std::cout << "Powinno byc OK:";
	if (iter != lista_do_4.end()) {
		std::cout << "\nOK\n";
	}
	else std::cout << "\nBlad\n";
	std::cout << "Powinno byc OK:";
	if (iter_2 != lista_do_4_false.end()) {
		std::cout << "\nBlad\n";
	}
	else std::cout << "\nOK\n";
}



//Dla klasy Zbior z plików zbior.h i zbior.cpp:
//1) Napisz konstruktor kopiujący i przenoszący operator =.Wyklucz pozostałe mechanizmy kopiowania / przenoszenia.
//2) Napisz formalny mechanizm konwersji do typu double zwracający średnią arytmetyczną z elementów w wewnętrznej
//tablicy.
//3) Napisz kod main wypełniający listę o losowej długości(min. 10 maks., 20 elementów).Wynikami konwersji Zbioru do typu
//double.Zadbaj, aby parametry zbiorów będących źródłem dla konwersji zmieniały się w kolejnych instancjach.Do
//losowania używaj tylko narzędzi C++ z biblioteki <random>.
//4) Zdefiniuj funktor, który będzie tworzony na bazie listy typu double.Funktor powinien móc być używany jako predykat
//jednoargumentowy, który będzie zwracał prawdę, jeśli przekazany mu argument typu double wystąpi w liście i fałsz
//w przeciwnym wypadku.Przyjmij tolerancję 10 - 6 dla błędu porównania zmiennoprzecinkowego.Zademonstruj działanie
//funktora na dowolnej funkcji z biblioteki algorytm i dowolnej kolekcji innej niż lista utworzona w punkcie 3.