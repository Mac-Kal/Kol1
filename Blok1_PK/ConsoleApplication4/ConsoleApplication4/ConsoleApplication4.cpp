#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

struct Taryfa {
	double dystans;
	double cena;
};
vector<Taryfa> zaladujTaryfeZPliku(const string& nazwaPliku) {
	vector<Taryfa> taryfy;
	ifstream plik(nazwaPliku);
	if (!plik.is_open()) {
		cerr << "Nie da sie otworzyc pliku: " << nazwaPliku << endl;
		return taryfy;
	}
	double opcja, cena;
	while (plik >> opcja >> cena) {
		taryfy.push_back({ opcja, cena });
	}
	plik.close();
	return taryfy;
}

double wybierzTaryfe(const vector<Taryfa>& taryfy, double dystans) {
	double wybranaCena = 0.0;
	for (const Taryfa& taryfa : taryfy) {
		if (dystans < taryfa.dystans) {
			wybranaCena = taryfa.cena;
			break;
		}
	}
	return wybranaCena;
}
int main()
{
	vector<Taryfa> taryfaOdleglosci = zaladujTaryfeZPliku("dystans.txt");
	vector<Taryfa> taryfaCzasu = zaladujTaryfeZPliku("czas.txt");
	double odleglosc;
	cout << "Podaj odleglosc przesylki: "; cin >> odleglosc;
	double cenaDystansu = wybierzTaryfe(taryfaOdleglosci, odleglosc);
	int opcjaDostawy;
	cout << "Podaj opcje dostawy: " << endl;
	for (int i = 0; i < taryfaCzasu.size(); i++) {
		cout << i + 1 << ". Do " << taryfaCzasu[i].dystans << " dni - " << taryfaCzasu[i].cena << "x" << endl;
	}
	cout << "Wybierz numer opcji: "; cin >> opcjaDostawy;
	double cenaCzasu = taryfaCzasu[opcjaDostawy - 1].cena;
	double zaCalosc = cenaDystansu * cenaCzasu;
	cout << "Cena calkowita: " << zaCalosc << " zł" << endl;
}
