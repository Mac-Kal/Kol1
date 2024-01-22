
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
    int wzrost=0;
    float waga = 0, BMI = 0;
    do
    {
        cout << "Podaj wzrost" << endl;
        cin >> wzrost;
    } while (wzrost<=0);
    do
    {
        cout << "Podaj wage" << endl;
        cin >> waga;
    } while (waga <= 0);

    cout << "wzrost " <<wzrost<< endl;
    cout << "waga " << waga<< endl;
    BMI = waga / pow(wzrost,2);
    cout << "BMI ";
    cout << setprecision(2) << fixed << BMI << endl;
}
