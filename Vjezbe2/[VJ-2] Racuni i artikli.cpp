/*
Potrebno je napisati program za evidenciju računa. Primjerice, u dućanu svaki kupac ima
račun s jedinstvenim rednim brojem, a na tom računu se nalazi popis kupljenih stavki
(naziv, količina, jedinična cijena). Slijedeći programski odsječak u nastavku napišite sve
potrebne klase i metode kojima se dobije očekivano ponašanje programskog koda.
int main(){
Kupac Ante(Racun(1)); // Ante ima račun broj 1
Ante.racun.dodaj(Artikl("Jabuka", 1, 6)); // 1 kg, 6 kn/kg
Ante.racun.dodaj(Artikl("Banana", 2, 7.5)); // 2 kg, 7.5 kn/kg
Ante.racun.dodaj(Artikl("Coca cola 2l", 2, 10)); // 2 boce, 10 kn/boca
cout << "Ukupno: " << Ante.racun.ukupnaCijena << " kn" << endl; // 41 kn
/* U nastavku ispišite koji je najskuplji artikl kojeg je Ante platio
(naziv i ukupna cijena). Npr.
Najskuplje placeni artikl je Coca cola 2l (20kn)
*/










#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Artikl
{
public:
    string naziv;
    int kolicina;
    double cijena;

    Artikl(string naziv, int kolicina, double cijena) : naziv(naziv), kolicina(kolicina), cijena(cijena) {}
};

class Racun
{
public:
    int redni;
    vector <Artikl> artikli;


    double ukupnaCijena = 0;
    Racun(int redni) : redni(redni) {}


    void dodaj(Artikl a)
    {
        artikli.push_back(a);
        ukupnaCijena += a.cijena * a.kolicina;
    }
};

class Kupac
{
public:
    Racun racun;
    Kupac(Racun racun) : racun(racun) {}
};

int main()
{
    Kupac Ante(Racun(1)); // Ante ima račun broj 1
    Ante.racun.dodaj(Artikl("Jabuka", 1, 6)); // 1 kg, 6 kn/kg
    Ante.racun.dodaj(Artikl("Banana", 2, 7.5)); // 2 kg, 7.5 kn/kg
    Ante.racun.dodaj(Artikl("Coca cola 2l", 2, 10)); // 2 boce, 10 kn/boca
    cout << "Ukupno: " << Ante.racun.ukupnaCijena << " kn" << endl; // 41 kn

    /* U nastavku ispišite koji je najskuplji artikl kojeg je Ante platio
    (naziv i ukupna cijena). Npr.
    Najskuplje placeni artikl je Coca cola 2l (20kn)
    */
    int j = 0, cij = 0;
    for (int i = 0; i < Ante.racun.artikli.size(); i++)
    {
        if (Ante.racun.artikli[i].cijena * Ante.racun.artikli[i].kolicina > cij)
        {
            j = i;
            cij = Ante.racun.artikli[i].cijena * Ante.racun.artikli[i].kolicina;
        }
    }
    cout << "Najskuplje placeni artikl je " << Ante.racun.artikli[j].naziv << " (" << Ante.racun.artikli[j].cijena * Ante.racun.artikli[j].kolicina << "kn)";
    return 0;
}

