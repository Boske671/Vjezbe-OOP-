/*
Potrebno je napisati program za evidenciju narudžbi za postolara. Postolar zaprima narudžbe od naručitelja, a svaka narudžba može sadržavati više cipela. 
Svaka cipela ima veličinu (broj), materijal i boju. Slijedeći programski odsječak u nastavku napišite sve potrebne klase i metode kojima se dobije očekivano ponašanje programskog koda.

 

int main(){

       Postolar p;

       Narudzba n1;

       n1.narucitelj = "Susjed Mirko";

       //Cipela ima broj (velicinu), materijal i boju

       n1.dodajCipelu(Cipela(47, "Sky", "plava"));

       n1.dodajCipelu(Cipela(44, "Platno", "zelena"));

 

       //Cijena izrade jedne cipele se racuna na nacin da se velicina (broj cipele) pomnozi sa 10.5

       double c1 = p.preuzmiNarudzbu(n1);

       cout << "Ukupna cijena 1. narudzbe je " << c1 << endl;

 

       Narudzba n2("Barica");

       n2.dodajCipelu(Cipela(43, "Koza", "crna"));

       double c2 = p.preuzmiNarudzbu(n2);

       cout << "Ukupna cijena 2. narudzbe je " << c2 << endl;

 

       //Ispisuje sve narudzbe

       //Za svaku narudzbu ispisuje tko je narucitelj, te popis svih cipela koje su narucene

       p.ispisiNarudzbe();

      

}

*/



#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//Potrebno je napisati program za evidenciju narudžbi za postolara.Postolar zaprima narudžbe od naručitelja, a svaka narudžba može sadržavati više cipela.
//Svaka cipela ima veličinu(broj), materijal i boju.Slijedeći programski odsječak u nastavku napišite sve potrebne klase i metode kojima se dobije očekivano ponašanje programskog koda.


class Cipela
{
public:
    int broj;
    string materijal, boja;

    Cipela(int broj, string materijal, string boja) : broj(broj), materijal(materijal), boja(boja) {}

};

class Narudzba
{
public:
    vector <Cipela> cipele;
    string narucitelj;

    Narudzba (string narucitelj) : narucitelj(narucitelj) {}
    Narudzba() = default;
    void dodajCipelu(Cipela c)
    {
        cipele.push_back(c);
    }

};

class Postolar
{
public:
    vector <Narudzba> narudzbe;

    double preuzmiNarudzbu(Narudzba n)
    {
        narudzbe.push_back(n);
        double cijena = 0;
        for (int i = 0; i < n.cipele.size(); i++)
        {
            cijena += n.cipele[i].broj * 10.5;
        }
        return cijena;
    }

    void ispisiNarudzbe()
    {
        for (int i = 0; i < narudzbe.size(); i++)
        {
            cout << "Ime nar: " << narudzbe[i].narucitelj << endl;
            cout << "Cipele: " << endl;
            for (int j = 0; j < narudzbe[i].cipele.size(); j++)
            {
                cout << "br: " << narudzbe[i].cipele[j].broj << " boja: " << narudzbe[i].cipele[j].boja << " mat: " << narudzbe[i].cipele[j].materijal << endl;
            }
            cout << endl;
        }
    }
};

int main() {

    Postolar p;
    Narudzba n1;
    n1.narucitelj = "Susjed Mirko";
    //Cipela ima broj (velicinu), materijal i boju
    n1.dodajCipelu(Cipela(47, "Sky", "plava"));
    n1.dodajCipelu(Cipela(44, "Platno", "zelena"));
    //Cijena izrade jedne cipele se racuna na nacin da se velicina (broj cipele) pomnozi sa 10.5
    double c1 = p.preuzmiNarudzbu(n1);
    cout << "Ukupna cijena 1. narudzbe je " << c1 << endl;
    Narudzba n2("Barica");

    n2.dodajCipelu(Cipela(43, "Koza", "crna"));

    double c2 = p.preuzmiNarudzbu(n2);

    cout << "Ukupna cijena 2. narudzbe je " << c2 << endl;
    //Ispisuje sve narudzbe
    //Za svaku narudzbu ispisuje tko je narucitelj, te popis svih cipela koje su narucene
    p.ispisiNarudzbe();

}
