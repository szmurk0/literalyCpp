#include <iostream>
#include <string>

using namespace std;

class NumeralRzymski
{
public:
    const static int M = 1000;
    const static int D = 500;
    const static int C = 100;
    const static int L = 50;
    const static int X = 10;
    const static int V = 5;
    const static int I = 1;

    NumeralRzymski(const int arabski) :
            rzymski(""),
            arabski((arabski > 0) ? arabski : 0)
    {
        konwertujNaRzymski();
    }

    NumeralRzymski(const string& str) :
            rzymski((str.size() > 0) ? str : "0"),
            arabski(0)
    {
        int i = 0;
        while (i < static_cast<int>(str.size()))
        {
            char c = str[i++];
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

    int pobierzArabski()
    {
        return arabski;
    }

    void ustawArabski(const int arabski)
    {
        this->arabski = (arabski > 0) ? arabski : 0;
        konwertujNaRzymski();
    }

    const string& pobierzRzymski()
    {
        return rzymski;
    }

private:
    void konwertujNaRzymski()
    {
        rzymski = "";
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
    NumeralRzymski nr(rzymski);
    cout << "Arabski: " << nr.pobierzArabski() << endl;

    int arabski;
    cout << "Wpisz liczbę arabską: ";
    cin >> arabski;
    nr.ustawArabski(arabski);
    cout << "Rzymski: " << nr.pobierzRzymski() << endl;

    return 0;
}
