/*
Potrebno je napisati program za evidenciju igrača u ekipi. Ekipa se sastoji od igrača, a za svakog igrača se evidentira broj na dresu, ime, prezime i trzisna cijena. Potrebno je omogućiti ispis svih igrača u ekipi (naziv ekipe, te popis svih igrača poredano po broju na dresu). Također, potrebno je omogućiti jednostavno dohvaćanje informacija u ukupnoj cijeni svih igrača, najskupljem igraču, te prosječnoj cijeni svih igrača. Slijedeći programski odsječak u nastavku napišite sve potrebne klase i metode kojima se dobije očekivano ponašanje programskog koda.
int main(){

       Ekipa ekipa;

       ekipa.naziv = "Tim raketa";

       Igrac i1("Luka", "Modric");

       i1.broj = 10;

       i1.cijena = 50000000;

       ekipa.dodajIgraca(i1);

       Igrac i2("Mario", "Mandzukic");

       i2.broj = 9;

       i2.cijena = 27000000;

       ekipa.dodajIgraca(i2);

       Igrac i3("Darijo", "Srna");

       i3.broj = 11;

       i3.cijena = 14500000;

       ekipa.dodajIgraca(i3);

 

       ekipa.ispisi();

 

       Igrac najskuplji = ekipa.dohvatiNajskupljeg();

       cout << "Najskuplji igrac: ";

       najskuplji.ispisi();

 

       cout << "Ukupna cijena svih igraca: " << ekipa.ukupnaCijena() << endl;

       cout << "Prosjecna cijena jednog igraca: " << ekipa.prosjecnaCijena() << endl;

}
*/





#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Igrac
{
public:
    int broj, cijena;
    string ime, prezime;

    Igrac(string _ime, string _prezime)
    {
        ime = _ime;
        prezime = _prezime;
    }

    void ispisi() {
        cout << "Ime: " << ime << " - Prezime: " << prezime << " - Broj na dresu: " << broj << " - Cijena: " << cijena << endl;
    }
};


class Ekipa
{
public:
    string naziv;
    vector<Igrac> igraci;

    void dodajIgraca(Igrac ig)
    {
        igraci.push_back(ig);
    }

    void ispisi()
    {
        cout << "Naziv ekipe: " << naziv << endl;
        cout << "Popis igraca:" << endl;
        for (Igrac ig : igraci)
        {
            ig.ispisi();
        }
    }


    Igrac dohvatiNajskupljeg()
    {
        Igrac najskuplji = igraci[0];
        for (Igrac ig : igraci)
        {
            if (ig.cijena > najskuplji.cijena) 
            {
                najskuplji = ig; 
            }
        }
        return najskuplji;
    }

    int ukupnaCijena()
    {
        int uk = 0;
        for (Igrac ig : igraci)
        {
            uk += ig.cijena;
        }
        return uk;
    }

    int prosjecnaCijena()
    {
        double pros = (double)ukupnaCijena() / igraci.size();
        return pros;
    }
};

int main()
{
    Ekipa ekipa;
    ekipa.naziv = "Tim raketa";
    Igrac i1("Luka", "Modric");
    i1.broj = 10;
    i1.cijena = 50000000;
    ekipa.dodajIgraca(i1);
    Igrac i2("Mario", "Mandzukic");
    i2.broj = 9;
    i2.cijena = 27000000;
    ekipa.dodajIgraca(i2);
    Igrac i3("Darijo", "Srna");
    i3.broj = 11;
    i3.cijena = 14500000;
    ekipa.dodajIgraca(i3);
    ekipa.ispisi();
    Igrac najskuplji = ekipa.dohvatiNajskupljeg();
    cout << "Najskuplji igrac: ";
    najskuplji.ispisi();
    cout << "Ukupna cijena svih igraca: " << ekipa.ukupnaCijena() << endl;
    cout << "Prosjecna cijena jednog igraca: " << ekipa.prosjecnaCijena() << endl;
}

