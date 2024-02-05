#include <iostream>
#include <cstring>
#include <cassert>

using namespace std;
const char* const DOST[] = { "dostempne","niedostempne","spodziewana_dostawa" };
enum class Dostempnosc
{
	dostempne,
	niedostempne,
	spodziewana_dostawa,
};
struct Producent
{
	char nazwa[500];
};
struct Towar
{
	char nazwa[1000];
	double cena;
	Dostempnosc dostepnosc;
	Producent *producent;
};
void wypel(Towar*t,const char* nazwa,int cena,Dostempnosc dostepnosc, Producent* producent) {
	t->cena = cena;
	t->dostepnosc = dostepnosc;
	strcpy_s(t->nazwa,500,nazwa);
	t->producent = producent;
}
void wyswietl(Towar* t) {
	cout << t->cena<<" " << DOST[int(t->dostepnosc)] << " " << t->nazwa << " " << t->producent->nazwa;
}
double sredniaCena(Towar* dane, size_t size, Producent* producent)
{
	assert(producent != nullptr || dane != nullptr);
	if (dane==0)
	{
		throw invalid_argument("nullptr");
	}
		
	

	double suma = 0;
	double ilosc = 0;
	for (int i = 0; i < size; i++)
	{
		if (dane[i].producent == producent) {
			suma += dane[i].cena;
			ilosc++;
		}
	}

	if (ilosc == 0) throw domain_error("brak produktow tego producenta");
	double wynik= suma / ilosc;
	return wynik;
}

void Test1() {
	cout << "test_srednia";

	Producent producenci[] = {
		{"Sprytny Rybak"},
		{"KWK Świderek"},
		{"Agencja T. Chryzantema"},
		{"Pomidor S.A"}
	};

	Towar towary[] =
	{
		{"Sledze",10.99,Dostempnosc::dostempne,&producenci[0]},
		{"Węgiel",1000.0,Dostempnosc::niedostempne,&producenci[1]},
		{"Masaz",501.29,Dostempnosc::dostempne,&producenci[2]},
		{"Masaz1",501.29,Dostempnosc::niedostempne,&producenci[3]},
		{"Masaj",501.6363429,Dostempnosc::dostempne,&producenci[0]},
		{"Masa3",556401.29,Dostempnosc::spodziewana_dostawa,&producenci[2]},
		{"Ma654634",57301.29,Dostempnosc::dostempne,&producenci[1]}
	};
	size_t size = sizeof(towary) / sizeof(towary[0]);
	try {
		double wynik = sredniaCena(towary, size, &producenci[3]);
		if (wynik==501.29)
		{
			cerr << "test: OK" << endl;
		}
		else
		{
			throw wynik;
		}

	}
	catch (double wynik) {
		cerr << "test: FAIL" << endl;

	}

}

void Test2() {
	cout << "test_brak_towaru";

	Producent producenci[] = {
		{"Sprytny Rybak"},
		{"KWK Świderek"},
		{"Agencja T. Chryzantema"},
		{"Pomidor S.A"},
		{""}
	};

	Towar towary[] =
	{
		{"Sledze",10.99,Dostempnosc::dostempne,&producenci[0]},
		{"Masaz",501.29,Dostempnosc::dostempne,&producenci[2]},
		{"Masaz1",501.29,Dostempnosc::dostempne,&producenci[3]},
		{"Masaj",501.6363429,Dostempnosc::dostempne,&producenci[0]},
		{"Masa3",556401.29,Dostempnosc::spodziewana_dostawa,&producenci[2]},
		{"Ma654634",57301.29,Dostempnosc::dostempne,&producenci[1]}
	};

	size_t size = sizeof(towary) / sizeof(towary[0]);

	try {
		sredniaCena(towary, size, &producenci[1]);
		cerr << "test: FAIL" << endl;
	}
	catch(invalid_argument){
		cerr << "test: OK" << endl;
	}


	/*assert(catched_error);*/

}

int main()
{
	Producent producenci[] =
	{
		{"Sprytny Rybak"},
		{"KWK Świderek"},
		{"Agencja T. Chryzantema"},
		{"Pomidor S.A"}
	};
	Towar towary[8] =
	{
		{"Sledze",10.99,Dostempnosc::dostempne,&producenci[0]},
		{"Węgiel",1000.0,Dostempnosc::niedostempne,&producenci[1]},
		{"Masaz",501.29,Dostempnosc::dostempne,&producenci[2]},
		{"Masaz1",501.29,Dostempnosc::niedostempne,&producenci[3]},
		{"Masaj",501.6363429,Dostempnosc::dostempne,&producenci[0]},
		{"Masa3",556401.29,Dostempnosc::spodziewana_dostawa,&producenci[2]},
		{"Ma654634",57301.29,Dostempnosc::dostempne,&producenci[1]}

	};
	wypel(&towary[7], "Kamil", 35353, Dostempnosc::niedostempne, &producenci[2]);
	wyswietl(&towary[7]);
	size_t size = sizeof(towary) / sizeof(towary[0]);
	cout << endl<<"srednia cena: " << sredniaCena(towary, size, &producenci[3]) << endl;
	Test1();
	Test2();

}
