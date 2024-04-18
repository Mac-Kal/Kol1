#pragma once
#include <iostream>
#include <algorithm>
#include <random>
#include <vector>
#include <list>

class Zbior
{
	size_t m_liczbaElementow = 0;
	double* m_elementy = nullptr;
	double m_dolnaGranica = 0;
	double m_gornaGranica = 0;
	void alokuj(int);
	void zwolnij();
public:
	Zbior(size_t liczElem, double dGran, double gGran);
	Zbior(const Zbior& inny);
	Zbior& operator=(const Zbior& inny);
	Zbior(Zbior&& other) noexcept;
	static Zbior konwersja_gora(double gorna_granica);
	double oblicz_srednia() const;
	~Zbior() { 	zwolnij(); }
};

class Funktor {
	Zbior m_element;
	double tolerancja = 1e-1;
public:
	Funktor(Zbior element) : m_element(element) {}
	bool operator()(const Zbior& zbior) const {
		return std::abs(zbior.oblicz_srednia() - m_element.oblicz_srednia()) < tolerancja;
	}
};