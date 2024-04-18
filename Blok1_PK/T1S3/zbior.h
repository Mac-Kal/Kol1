#pragma once
#include <iostream>
#include <algorithm>
#include <random>
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
	operator double() const;
	~Zbior() { 	zwolnij(); }
};

class Funktor {
	double m_szukany_element;
	double tolerancja = 1e-6;
public:
	Funktor(double element) : m_szukany_element(element) {}
	bool operator()(double wartosc) const {
		return std::abs(wartosc - m_szukany_element) < tolerancja;
	}
};