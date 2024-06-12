#include <iostream>
#include <string>
using namespace std;
/*
Nowe pojęcia, konstruktor(36l) this->(6l)

this-> w skrócie odnosi się do bieżącego obiektu, w którym wywoływana jest dana metoda.
    this->Pozwala odwoływać się do składowych klasy, aby odróżnić je od zmiennych lokalnych lub parametrów metody o tych samych nazwach.

*/
// Klasa reprezentująca numerał rzymski, który może być konwertowany na liczbę arabską i vice versa.
class NumeralRzymski
{
public:
    const static int M = 1000; ///< Wartość liczby rzymskiej M
    const static int D = 500;  ///< Wartość liczby rzymskiej D
    const static int C = 100;  ///< Wartość liczby rzymskiej C
    const static int L = 50;   ///< Wartość liczby rzymskiej L
    const static int X = 10;   ///< Wartość liczby rzymskiej X
    const static int V = 5;    ///< Wartość liczby rzymskiej V
    const static int I = 1;    ///< Wartość liczby rzymskiej I

     // Konstruktor inicjalizujący numerał rzymski na podstawie liczby arabskiej.
     // arabski Liczba arabska, na podstawie której tworzony jest numerał rzymski.
    NumeralRzymski(const int arabski) :
            rzymski(""), ///< Inicjalizacja numerału rzymskiego jako pusty ciąg znaków
            arabski(arabski) ///< Inicjalizacja liczby arabskiej, jeśli jest większa niż 0
    {
        if (arabski <= 0)
        {
            this->arabski = 0; ///< Ustawienie arabskiego na 0, jeśli przekazano wartość mniejszą lub równą 0
        }
        konwertujNaRzymski(); ///< Konwersja liczby arabskiej na numerał rzymski
    }


    // Konstruktor inicjalizujący numerał rzymski na podstawie ciągu znaków.
    // !NOWE! Konstruktor inicjuje dane składniowe obiektu, wywoływany podczas tworzenia jej instancji (klasy)
    NumeralRzymski(const string& str) :
            arabski(0) ///< Inicjalizacja liczby arabskiej na 0
    {
        if (str.size() > 0)
        {
            rzymski = str; ///< Ustawienie numerału rzymskiego na podstawie przekazanego ciągu znaków
        }
        else
        {
            rzymski = "0"; ///< Jeśli przekazany ciąg jest pusty, ustaw numerał rzymski na "0"
        }

        // Konwersja numerału rzymskiego na liczbę arabską
        int i = 0;
        while (i < static_cast<int>(rzymski.size()))
        {
            char c = rzymski[i++];
            switch (c)
            {
                case 'M':
                case 'm':
                    arabski += M;
                    break;
                case 'D':
                case 'd':
                    arabski += D;
                    break;
                case 'C':
                case 'c':
                    arabski += C;
                    break;
                case 'L':
                case 'l':
                    arabski += L;
                    break;
                case 'X':
                case 'x':
                    arabski += X;
                    break;
                case 'V':
                case 'v':
                    arabski += V;
                    break;
                case 'I':
                case 'i':
                    arabski += I;
                    break;
                default:
                    cout << "Niepoprawny numeral rzymski!";
            }
        }
    }


     // Metoda zwracająca liczbę arabską na podstawie numerału rzymskiego.

     // Liczba arabska odpowiadająca numerałowi rzymskiemu.

    int pobierzArabski()
    {
        return arabski; ///< Zwraca liczbę arabską odpowiadającą aktualnemu numerałowi rzymskiemu
    }


    // Metoda ustawiająca liczbę arabską na podstawie podanej wartości.

    void ustawArabski(const int arabski)
    {
        if (arabski > 0)
        {
            this->arabski = arabski; ///< Ustawia liczbę arabską na podstawie przekazanej wartości, jeśli jest większa niż 0
        }
        else
        {
            this->arabski = 0; ///< W przeciwnym razie ustawia liczbę arabską na 0
        }
        konwertujNaRzymski(); ///< Po zmianie liczby arabskiej konwertuje ją na numerał rzymski
    }

    // Metoda zwracająca numerał rzymski jako ciąg znaków.
    // Referencja do ciągu znaków zawierającego numerał rzymski.
    const string& pobierzRzymski()
    {
        return rzymski; ///< Zwraca numerał rzymski jako ciąg znaków
    }

private:
    // Prywatna metoda konwertująca liczbę arabską na numerał rzymski.
    void konwertujNaRzymski()
    {
        rzymski = ""; ///< Resetuje numerał rzymski przed konwersją
        int liczba = arabski;
        while (liczba > 0)
        {
            if (liczba >= M)
            {
                rzymski += "M";
                liczba -= M;
            }
            else if (liczba >= D)
            {
                rzymski += "D";
                liczba -= D;
            }
            else if (liczba >= C)
            {
                rzymski += "C";
                liczba -= C;
            }
            else if (liczba >= L)
            {
                rzymski += "L";
                liczba -= L;
            }
            else if (liczba >= X)
            {
                rzymski += "X";
                liczba -= X;
            }
            else if (liczba >= V)
            {
                rzymski += "V";
                liczba -= V;
            }
            else if (liczba >= I)
            {
                rzymski += "I";
                liczba -= I;
            }
        }
    }

protected:
    string rzymski;
    int arabski;
};


int main()
{
    string rzymski;
    cout << "Wpisz numerał: ";
    cin >> rzymski;
    NumeralRzymski nr(rzymski); ///< Tworzy obiekt NumeralRzymski na podstawie podanego numerału rzymskiego
    cout << "Arabski: " << nr.pobierzArabski() << endl;

    int arabski;
    cout << "Wpisz liczbę arabską: ";
    cin >> arabski;
    nr.ustawArabski(arabski); ///< Ustawia nową liczbę arabską dla istniejącego numerału rzymskiego
    cout << "Rzymski: " << nr.pobierzRzymski() << endl;

    return 0;
}
