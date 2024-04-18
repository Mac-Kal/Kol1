#include "zbior.h"

void Zbior::alokuj(int n)
{
	if (n > 0)
	{
		m_elementy = new(std::nothrow) double[n];
		m_liczbaElementow = n;
	}
}

void Zbior::zwolnij()
{
	if (m_elementy != nullptr)
	{
		delete[] m_elementy;
		m_elementy = nullptr;
	}
}

Zbior::Zbior(size_t liczElem, double dGran, double gGran)
{
	alokuj(liczElem);
	std::uniform_real_distribution<double> zakres(dGran, gGran);
	std::random_device generator;
	for (int elem = 0; elem < liczElem; elem++)
		m_elementy[elem] = zakres(generator);
}

//konstruktor kopiujacy
Zbior::Zbior(const Zbior& inny) : 
m_liczbaElementow(inny.m_liczbaElementow),
m_dolnaGranica(inny.m_dolnaGranica),
m_gornaGranica(inny.m_gornaGranica) 
{
	alokuj(m_liczbaElementow);
	for (size_t i = 0; i < m_liczbaElementow; i++) {
		m_elementy[i] = inny.m_elementy[i];
	}
}

//konstruktor przenoszacy operator =
Zbior& Zbior::operator=(const Zbior& inny) {
	if (this != &inny) {
		zwolnij();
		m_liczbaElementow = inny.m_liczbaElementow;
		m_dolnaGranica = inny.m_dolnaGranica;
		m_gornaGranica = inny.m_gornaGranica;
		alokuj(m_liczbaElementow);
		for (size_t i = 0; i < m_liczbaElementow; i++) {
			m_elementy[i] = inny.m_elementy[i];
		}
	}
	return *this;
}
//konstruktor przenoszacy
Zbior::Zbior(Zbior&& inny) noexcept : 
m_liczbaElementow(inny.m_liczbaElementow), 
m_elementy(inny.m_elementy),
m_dolnaGranica(inny.m_dolnaGranica), 
m_gornaGranica(inny.m_gornaGranica)
{
	inny.m_liczbaElementow = 0;
	inny.m_elementy = nullptr;
}


//formalna konwersja do double zwracajacy srednia arytmetyczna
Zbior::operator double() const {
	if (m_liczbaElementow == 0) {
		return 0.0;
	}
	double suma = 0.0;
	for (size_t i = 0; i < m_liczbaElementow; i++) {
		suma += m_elementy[i];
	}
	return suma / m_liczbaElementow;
}