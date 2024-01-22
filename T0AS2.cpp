
#include <iostream>
#include <ctime>
#include <math.h>
#include <iomanip>

using namespace std;
/*
Napisz program, który pobierze od użytkownika dwie liczby, całkowitą wzrost i rzeczywistą waga. Program powinien wymusić na użytkowniku podanie wartości większych od 0 dla obydwóch liczb.
Wymuszanie powinno się odbyć oddzielnie dla każdej z liczb.Następnie oblicz wartość wskaźnika BMI wg. wzoru: BMI=waga/(wzrost^2)
Uzyskany wynik wyświetl z dokładnością do dwóch miejsc po przecinku
*/
int main()
{
    //zad1
    int wzrost = 0, a = 0;
    float waga = 0, BMI = 0;
    do
    {
        cout << "Podaj wzrost" << endl;
        cin >> wzrost;
    } while (wzrost <= 0);
    do
    {
        cout << "Podaj wage" << endl;
        cin >> waga;
    } while (waga <= 0);

    cout << "wzrost " << wzrost << endl;
    cout << "waga " << waga << endl;
    BMI = waga / pow(wzrost, 2);
    cout << "BMI ";
    cout << setprecision(2) << fixed << BMI << endl;

    //zad2
    cout << "Podaj liczbe" << endl;
    cin >> a;
    int T[5][6] = {0};
    int suma = 0, lasti = 0;
    //wypełnianie tablicy elementami od 0 do a
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 6; j++) {
            T[i][j] = rand() % (a + 1);
            
        }
    }
    //wypisywanie elementów tablicy
    for (int i1 = 0; i1 < 5; i1++) {
        cout << "\n";
        for (int j1 = 0; j1 < 6; j1++) {
            cout << T[i1][j1]<<" ";
        }
    }
    cout << "\n";
    //sumowanie wartości w wierszach tablicy 
    //NIE KOPIOWAĆ BEZNADZIEJNE ROZWIAZANIE NIE MIAŁEM INNEGO POMYSŁU XD
    for (int i2 = 0; i2 < 6; i2++) {
        if (i2>0)
        {
            cout << "Suma wiersza " << i2-1 << ": " << suma << "\n";
        }
        if (lasti!=i2)
        {
            suma = 0;
        }
        lasti = i2;
        for (int j2 = 0; j2 < 6; j2++) {
            suma=suma+T[i2][j2];
        }
    }
    //Suma wartości w wierszu 0
    //for (int k = 0; k < 6; k++) {
    //    suma += T[0][k];
    //}
    //cout << "Suma: " << suma;


    //zad3
    //Wyświetlanie odległości między komórkami pamięci przechowującymi wartość indeksów w tablicy T
    int x1, x2, y1, y2;
    int* wskA;
    int* wskB;
    int odlwsk;
    cout << "Wspolrzedne punktu 1 \nPodaj x1" << endl;
    cin >> x1;
    cout << "Podaj y1" << endl;
    cin >> y1;

    cout << "Wspolrzedne punktu 2 \nPodaj x2" << endl;
    cin >> x2;
    cout << "Podaj y2" << endl;
    cin >> y2;
    
    wskA = &T[x1][y1];
    wskB = &T[x2][y2];
    if (wskA>wskB)
    {
        odlwsk = wskA - wskB;
    }
    else
    {
        odlwsk = wskB - wskA;
    }
    cout << "\n" << "Odleglosc wskasnikow wynosi: " << odlwsk;

}

