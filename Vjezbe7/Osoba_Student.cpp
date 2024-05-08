/*
Klasa osoba sadrzi string prezime i funkciju void RadniStatus. A klasa Student sadrzi string NazivStudija, smjer;
int semestar.

Klasa Student koristi javno (public) nasljeđivanje klase Osoba, dok podatkovni članovi u obje klase imaju javno pravo pristupa. Također, metoda RadniStatus ispisuje "Osoba nema radni status!".

a)	U klasi Osoba dodajte podatkovni član OIB (string), te konstruktor sljedećeg oblika: Osoba(string oib);
Navedeni konstruktor postavlja člansku varijablu OIB na vrijednost predanu parametrom. Sukladno tome, u klasi Student također dodajte odgovarajući konstruktor kojim se inicijalizira pod-objekt Osoba.
b)	U klasi Student napravite prijepis (eng. overriding) metode RadniStatus tako da ispisuje "Redovni student".

c)	U funkciji main (main.cpp) deklarirajte statičko polje GrupaA tipa Student koje sadrži 5 elemenata. Pri deklaraciji polja svaki element treba inicijalizirati proizvoljnim OIB-om.

d)	Napišite funkciju
int BrojStudenata(Student* p, int elem, int semestar);
koja za predano polje p vraća broj studenata koji se nalazi u traženom semestru.
*/


#include <iostream>
#include <string>


using namespace std;

class Osoba
{
public:
    string prezime, ime, OIB;

    Osoba(string OIB) : OIB(OIB) {}
    void RadniStatus()
    {
        cout << "Osoba nema radni status!" << endl;
    }
};

class Student : public Osoba
{
public:
    string NazivStudija, smjer;
    int semestar;

    Student (string OIB) : Osoba(OIB) {}
    void RadniStatus()
    { 
        cout << "Redovni student." << endl;
    }
};

int BrojStudenata(Student* p, int elem, int semestar)
{
    int br = 0;
    for (int i = 0; i < elem; i++)
    {
        if (p[i].semestar == semestar)
        {
            br++;
        }
    }
    return br;
}

int main()
{
    Student GrupaA[5] = { Student("OIB1"), Student("OIB2"), Student("OIB3"), Student("OIB4"), Student("OIB5") };


    //ispisa radnog statusa 
    GrupaA[0].RadniStatus();
    GrupaA[0].Osoba::RadniStatus();

    return 0;
}

