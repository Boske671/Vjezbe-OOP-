/*
Napraviti klasu Firma sa sljedećim (privatnim) poljima:

    naziv
    OIB
    Adresa sjedišta

Omogućiti korisniku kreiranje nove firme i postavljanje naziva, OIBa i adrese sjedišta. Treba pripaziti na sljedeća pravila:

    Naziv mora biti barem 5 znakova – ako je manji, odustati od postavljanja naziva i ispisati poruku korisniku
    OIB mora biti od točno 11 znamenki. Ukoliko pravilo nije zadovoljeno, odustati od postavljanja vrijednosti, i ispisati poruku korisniku

Sve provjere pravila je potrebno napraviti unutar klase Firma. Gdje?

Dodati klasu Zaposlenik s nekoliko proizvoljnih polja (ime, prezime,...). Neka klasa Zaposlenik ima samo jedan konstruktor, unutar kojeg je potrebno ispisati „Zaposlenik constructor called“ korisniku, te jedan destruktor u kojem treba ispisati "Zaposlenik destructor called" korisniku. Proširiti klasu Firma s poljem vector<Zaposlenik> i dodati u klasu Firma metode:

    dodajZaposlenika1(Zaposlenik z)
    dodajZaposlenika2(Zaposlenik& z)
    dodajZaposlenika3(Zaposlenik* z)

Što se ispisuje prilikom poziva metoda 1,2 i 3? U kojim slučajevima se stvara novi objekt? Zašto se ispisuje više puta destruktor nego konstruktor?

Dodati u klasu Firma metodu „ispisSvihZaposlenika“.

Dodati u klasu Firma metode:

    Zaposlenik nadjiZaposlenika1(string ime, string prezime)
    Zaposlenik* nadjiZaposlenika2(string ime, string prezime)
    Zaposlenik& nadjiZaposelnika3(string ime, string prezime)

Koristeći nadjiZaposlenika1 naći i zatim izmjeniti podatke o jednom zaposleniku, a zatim koristeći metodu nadjiZaposlenika2 naći i zatim izmjeniti podatke o drugom zaposleniku i koristeći metodu nadjiZaposlenika3 naći i zatim izmjeniti podatke o trećem zaposleniku. Pozvati „ispisSvihZaposlenika“ za firmu. Što zapažate?

Koje su prednosti a koji nedostaci u načinima pozivanja metoda s objektima kao parametrima i vraćanja objekata kao vrijednosti iz funkcije? Kada koristiti jedan način a kada drugi?

*/


#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class Zaposlenik
{
public:
    string ime, prezime;

    Zaposlenik(string ime, string prezime) : ime(ime), prezime(prezime)
    {
        cout << "Zaposlenik constructor called" << endl;
    }

    ~Zaposlenik()
    {
        cout << "Zaposlenik destructor called" << endl;
    }
};


class Firma
{
private:
    string naziv, OIB, adresa;

public:

    vector <Zaposlenik> zaposlenici;
    void setNaziv(string noviNaziv)
    {
        if (noviNaziv.length() >= 5)
        {
            naziv = noviNaziv;
        }
        else
        {
            cout << "Naziv je manji od 5 znakova!" << endl;
        }
    }
    string getNaziv() const 
    {
        return naziv;
    }

    void setOIB(string noviOIB)
    {
        if (noviOIB.size() == 11) 
        {
            OIB = noviOIB;
        }
        else 
        {
            cout << "OIB nema tocno 11 znamenki!" << endl;
        }
    }

    string getOib() const
    {
        return OIB;
    }

    void dodajZaposlenika1(Zaposlenik z)
    {
        zaposlenici.push_back(z);
    }
    void dodajZaposlenika2(Zaposlenik &z)
    {
        zaposlenici.push_back(z);
    }
    void dodajZaposlenika3(Zaposlenik *z)
    {
        zaposlenici.push_back(*z);
    }


    void ispisSvihZaposlenika()
    {
        for (int i = 0; i < zaposlenici.size(); i++)
        {
            cout << zaposlenici[i].ime << " " << zaposlenici[i].prezime << endl;
        }
    }

    Zaposlenik nadjiZaposlenika1(string ime, string prezime)
    {
        for (int i = 0; i < zaposlenici.size(); i++)
        {
            if (zaposlenici[i].ime == ime && zaposlenici[i].prezime == prezime)
            {
                cout << "1. Naden" << endl;
                zaposlenici[i].ime = "novo ime 1";
                zaposlenici[i].prezime = "novo prezime 1";
                return zaposlenici[i];
                break;
            }
        }
    }

    Zaposlenik *nadjiZaposlenika2(string ime, string prezime)
    {
        for (int i = 0; i < zaposlenici.size(); i++)
        {
            if (zaposlenici[i].ime == ime && zaposlenici[i].prezime == prezime)
            {
                cout << "2. Naden" << endl;
                zaposlenici[i].ime = "novo ime 2";
                zaposlenici[i].prezime = "novo prezime 2";
                return &zaposlenici[i];
                break;
            }
        }
    }

    Zaposlenik& nadjiZaposlenika3(string ime, string prezime)
    {
        for (int i = 0; i < zaposlenici.size(); i++)
        {
            if (zaposlenici[i].ime == ime && zaposlenici[i].prezime == prezime)
            {
                cout << "3. Naden" << endl;
                zaposlenici[i].ime = "novo ime 3";
                zaposlenici[i].prezime = "novo prezime 3";
                return zaposlenici[i];
                break;
            }
        }
    }
};



int main()
{
    Firma f1;
    f1.setOIB("12345678901");

    Zaposlenik za1("fran", "bosancic");
    Zaposlenik za2("leo", "messi");
    Zaposlenik za3("zinedine", "zidane");


    f1.dodajZaposlenika1(za1);
    f1.dodajZaposlenika2(za2);
    f1.dodajZaposlenika3(&za3);
    f1.ispisSvihZaposlenika();


    f1.nadjiZaposlenika1("fran", "bosancic");
    f1.nadjiZaposlenika2("leo", "messi");
    f1.nadjiZaposlenika3("zinedine", "zidane");
    f1.ispisSvihZaposlenika();
}

