///*
//Napomena 1: Rješenja zadataka potrebno je prije isteka predviđenog vremena predati u jednoj .cpp datoteci naziva <ime_prezime_jmbag>.cpp.
//Nakon isteka predviđenog vremena naknadna predaja rješenja nije više moguća!
//Napomena 2: Ocjenjuju se samo rješenja koja se uspješno prevode!
//Napomena 3: Zbog korištenja novijih značajki jezika C++ preporuka je koristiti alat Microsoft Visual Studio.
//
//ZADATAK:
///*
//Napišite sve što je neophodno da bi se funkcija "main" izvršavala kako je
//navedeno s komentarima. Također slijedite sve ostale upute s komentarima za
//pisanje koda. Svaki dio označen između crta nosi navedeni broj bodova ako je s
//potpunosti implementiran. Djelomična implementacija boduje se prema procjeni
//nastavnika.
//
//Napomena: Funkciju "main" nije dozvoljeno modificirati! Za uočenu promjenu s
//nekom dijelu ove funkcije taj se dio poništava.
//*/
//
//int main() {
//    //**************************************************************************
//    // [1] --- 1 BOD
//
//    // sav kôd mora biti dio imenskog prostora Sastanak
//    using namespace Sastanak;
//
//    //**************************************************************************
//    // [2] --- 2 BODA
//    cout << "--- [2] ---\n";
//
//    Tocka t1(1, "Tocka prva", "Citanje zapisnika");
//    Tocka t2;  // postavlja točku na: 0, "Točka 0", "Razno"
//    Tocka t3(2, "Tocka druga", "Izvjesce povjerenika");
//    Tocka t4(3, "Tocka treca", "Plan rada");
//    vector<Tocka> tocke{ t1, t2, t3, t4 };
//
//    // * ispisuje se "neispravna točka" 
//    // (razred Tocka treba provjeravati jesu li svi podaci navedeni: redni broj, naziv i opis)
//    // * razred NeispravnaTocka mora imati samo konstruktor koji prima tekst
//    // poruke (nema drugih funkcija) i nasljeđivati od razreda "exception"
//    try {
//        Tocka t(4, "Tocka cetvrta", "");  // prazan opis - baca se iznimka
//    }
//    catch (NeispravnaTocka& e) {
//        cout << e.what() << endl;
//    }
//
//    //**************************************************************************
//    // [3] --- 2 BODA
//    cout << "--- [3] ---\n";
//
//    cout << (string)t1 << endl;  // ispisuje "Tocka prva - Citanje zapisnika"
//    cout << t1 << endl;  // ispisuje "Ad1;Tocka prva;Citanje zapisnika"
//
//    //**************************************************************************
//    // [4] --- 4 BODA
//    cout << "--- [4] ---\n";
//
//    // * ovdje upotrijebiti funkciju "sort" zaglavlja "algorithm"
//    // * za razred Tocka treba definirati i kopirni operator pridruživanja
//    sort(tocke.begin(), tocke.end());
//    ispisi(tocke);  // ispisuje točke sortirane po rednom broju
//
//    //**************************************************************************
//    // [5] --- 2 BODA
//    cout << "--- [5] ---\n";
//
//    // * ovdje upotrijebiti funkciju "sort" zaglavlja "algorithm"
//    // * varijabla slaganje_tocaka mora sadrzavati lambda-izraz
//    sort(tocke.begin(), tocke.end(), slaganje_tocaka);
//    ispisi(tocke);  // ispisuje točke sortirane po rednom broju obratnim redoslijedom
//
//    //**************************************************************************
//    // [6] --- 6 BODOVA
//    cout << "--- [6] ---\n";
//
//    vector<ElementDnevnogReda*> red{ &t1, &t2, &t3, &t4 };
//    sort(red.begin(), red.end(), usporedba_tocaka);
//
//    // Funkcijom "tekstualno" demonstrirati polimorfizam; razred ElementDnevnogReda
//    // mora biti apstraktan s jednom funkcijom "tekstualno"!
//
//    // ispisuje točke sortirane po rednom broju
//    for (vector<ElementDnevnogReda*>::const_iterator itr = red.begin();
//        itr != red.end(); ++itr) {
//        cout << (*itr)->tekstualno() << endl;
//    }
//
//    //**************************************************************************
//    // [7] --- 6 BODOVA
//    cout << "--- [7] ---\n";
//
//    Tocka s(5, "Peta tocka", "Glasanje", new Odgovor("kolega A - za"));
//    Tocka z = s;
//
//    // nadovezuje tekst zadan s "nadodaj" s tekstom zadanim s konstruktoru
//    s.odgovor()->nadodaj("kolega B - protiv");
//
//    // ispisuje "kolega A - za; kolega B - protiv"
//    cout << s.odgovor()->tekst() << endl;
//
//    // ispisuje "kolega A - za"
//    cout << z.odgovor()->tekst() << endl;
//
//    //**************************************************************************
//    // [8] --- 5 BODOVA
//    cout << "--- [8] ---\n";
//
//    Zapisnik<Tocka> zapisnik;
//    // Funkcija "nadodaj" mora biti napisana kao funkcija 
//    // s neograničenim brojem parametara!
//    zapisnik.nadodaj(t1, t4, t2);
//
//    // ispisuje "Ad1;Tocka prva;Citanje zapisnika", "Ad3;Tocka treca;Plan rada", "Ad0;Tocka 0;Razno" 
//    // (jedno ispod drugoga)
//    zapisnik.ispisi();
//
//    //**************************************************************************
//    // [9] --- 2 BODA
//    cout << "--- [9] ---\n";
//
//    // Na kraju se mora ispisati broj koliko je objekata tipa Tocka uništeno!
//    cout << Tocka::unisteno << endl;
//    //**************************************************************************
//}
//*/



#include <iostream>
#include <vector>
#include <functional>
#include <string>
#include <algorithm>
using namespace std;


namespace Sastanak
{
    class ElementDnevnogReda
    {
    public:
        virtual string tekstualno() = 0;
    };
    class NeispravnaTocka
    {
    public:
        string what()
        {
            return "bacanje greske!";
        }
    };
    class Tocka : public ElementDnevnogReda
    {
    public:
        static int unisteno;
        int kordinata;
        string opis1, opis2;
        Tocka(int _kor = 0, string _o = "Tocka 0", string _o2 = "Razno") : kordinata(_kor), opis1(_o), opis2(_o2)
        {
            if (opis1 == "" || opis2 == "")
            {
                throw NeispravnaTocka();
            }
        }
        string tekstualno() override
        {
            return "ispis: " + opis1;
        }
        operator string()
        {
            return opis1 + " - " + opis2;
        }

        Tocka& operator = (const Tocka& t2)
        {
            if (this != &t2)
            {
                kordinata = t2.kordinata;
                opis1 = t2.opis1;
                opis2 = t2.opis2;
            }
            return *this;
        }

        bool operator < (const Tocka& t) const
        {
            return kordinata < t.kordinata;
        }

        ~Tocka()
        {
            unisteno++;
        }
    };
    ostream& operator << (ostream& izlaz, Tocka& t1)
    {
        //cout << t1 << endl;  // ispisuje "Ad1;Tocka prva;Citanje zapisnika"

        izlaz << "Ad" << t1.kordinata << ";" << t1.opis1 << ";" << t1.opis2 << endl;
        return izlaz;
    }
    void ispisi(vector <Tocka>& t)
    {
        for (int i = 0; i < t.size(); i++)
        {
            cout << t[i] << endl;
        }
    }

    auto slaganje_tocaka = [](Tocka& t1, Tocka& t2) {
        return t1.kordinata > t2.kordinata;
        };

    bool usporedba_tocaka(const ElementDnevnogReda* a, const ElementDnevnogReda* b) {
        const Tocka* ta = dynamic_cast<const Tocka*>(a);
        const Tocka* tb = dynamic_cast<const Tocka*>(b);
        return ta->operator<(*tb);
    }

    template <class t1>
    class Zapisnik
    {
    public:
        vector <t1> v;
        template <class ... Args>
        void nadodaj(Args... a)
        {
            (v.push_back(a), ...);
        }

        void ispisi()
        {
            for (int i = 0; i < v.size(); i++)
            {
                cout << v[i];
            }
        }
    };


    int Tocka::unisteno = 0;
}


int main() {
    //**************************************************************************
    // [1] --- 1 BOD

    // sav kôd mora biti dio imenskog prostora Sastanak
    using namespace Sastanak;

    //**************************************************************************
    // [2] --- 2 BODA
    cout << "--- [2] ---\n";

    Tocka t1(1, "Tocka prva", "Citanje zapisnika");
    Tocka t2;  // postavlja točku na: 0, "Točka 0", "Razno"
    Tocka t3(2, "Tocka druga", "Izvjesce povjerenika");
    Tocka t4(3, "Tocka treca", "Plan rada");
    vector<Tocka> tocke{ t1, t2, t3, t4 };


    // * ispisuje se "neispravna točka" 
    // (razred Tocka treba provjeravati jesu li svi podaci navedeni: redni broj, naziv i opis)
    // * razred NeispravnaTocka mora imati samo konstruktor koji prima tekst
    // poruke (nema drugih funkcija) i nasljeđivati od razreda "exception"
    try {
        Tocka t(4, "Tocka cetvrta", "");  // prazan opis - baca se iznimka
    }
    catch (NeispravnaTocka& e) {
        cout << e.what() << endl;
    }

    //**************************************************************************
    // [3] --- 2 BODA
    cout << "--- [3] ---\n";

    cout << (string)t1 << endl;  // ispisuje "Tocka prva - Citanje zapisnika"
    cout << t1 << endl;  // ispisuje "Ad1;Tocka prva;Citanje zapisnika"

    //**************************************************************************
    // [4] --- 4 BODA
    cout << "--- [4] ---\n";

    // * ovdje upotrijebiti funkciju "sort" zaglavlja "algorithm"
    // * za razred Tocka treba definirati i kopirni operator pridruživanja
    sort(tocke.begin(), tocke.end());
    ispisi(tocke);  // ispisuje točke sortirane po rednom broju

    //**************************************************************************
     // [5] --- 2 BODA
    cout << "--- [5] ---\n";

    // * ovdje upotrijebiti funkciju "sort" zaglavlja "algorithm"
    // * varijabla slaganje_tocaka mora sadrzavati lambda-izraz

    sort(tocke.begin(), tocke.end(), slaganje_tocaka);
    ispisi(tocke);  // ispisuje točke sortirane po rednom broju obratnim redoslijedom

    //**************************************************************************
    // [6] --- 6 BODOVA
    cout << "--- [6] ---\n";

    vector<ElementDnevnogReda*> red{ &t1, &t2, &t3, &t4 };
    sort(red.begin(), red.end(), usporedba_tocaka);

    // Funkcijom "tekstualno" demonstrirati polimorfizam; razred ElementDnevnogReda
    // mora biti apstraktan s jednom funkcijom "tekstualno"!

    // ispisuje točke sortirane po rednom broju
    for (vector<ElementDnevnogReda*>::const_iterator itr = red.begin();
        itr != red.end(); ++itr) {
        cout << (*itr)->tekstualno() << endl;
    }

    //**************************************************************************
    // [8] --- 5 BODOVA
    cout << "--- [8] ---\n";

    Zapisnik<Tocka> zapisnik;
    // Funkcija "nadodaj" mora biti napisana kao funkcija 
    // s neograničenim brojem parametara!
    zapisnik.nadodaj(t1, t4, t2);

    // ispisuje "Ad1;Tocka prva;Citanje zapisnika", "Ad3;Tocka treca;Plan rada", "Ad0;Tocka 0;Razno" 
    // (jedno ispod drugoga)
    zapisnik.ispisi();

    //**************************************************************************
     //**************************************************************************
    // [9] --- 2 BODA
    cout << "--- [9] ---\n";

    // Na kraju se mora ispisati broj koliko je objekata tipa Tocka uništeno!
    cout << Tocka::unisteno << endl;
    //**************************************************************************
}

