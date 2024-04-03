/*
Nepravilna matrica se sastoji redaka koji nemaju nužno uvijek isti broj stupaca. Napišite tijela metoda klase Matrica čija deklaracija izgleda na sljedeći način:

class Matrica{
public:
    vector<int*> redak; // svaki redak matrice je pokazivač na niz
    vector<int> stupac; // broj stupaca za svaki redak matrice

    void dodaj(int brStupaca, int* _redak); // dodaje novi redak matrici
    Matrica(){}
    Matrica(const Matrica& m);
    Matrica& operator = (const Matrica& m);
    Matrica(Matrica&& m);
    void ispis();
    ~Matrica();
};

Matrica se formira na način da se metodom dodaj matrici preda novo-alocirani 1D niz brojeva:

Matrica m;
m.dodaj(3, new int[3]{ 1, 6, 2 });  // dodaj novi redak od 3 stupca
m.dodaj(5, new int[5]{ 5, 3, 4, 7, 0 });
m.dodaj(4, new int[4]{ 6, 2, 6, 5 });
m.ispis();// ispis matrice redak po redak

Deklaraciju klase Matrice spremite u Matrica.h, a implementaciju njenih metoda u Matrica.cpp datoteku. U funkciji main također demonstrirajte poziv kopirnog konstruktora i operatora pridruživanja s semantikom kopiranja.
*/


#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class Matrica {
public:
    vector<int*> redak; // svaki redak matrice je pokazivac na niz
    vector<int> stupac; // broj stupaca za svaki redak matrice

    void dodaj(int brStupaca, int* _redak); // dodaje novi redak matrici
    Matrica() {} 
    Matrica(const Matrica& m); //KOPIRNI KONSTRUKTOR
    Matrica& operator = (const Matrica& m); //OPERATOR PRIDRUZIVANJA
    Matrica(Matrica&& m);  //KONSTRUKTOR PRIJENOSA
    void ispis();
    ~Matrica();
};

void Matrica::dodaj(int brStupaca, int* _redak)
{
    redak.push_back(_redak);
    stupac.push_back(brStupaca);
}

Matrica::Matrica(const Matrica& m)
{
    for (int i = 0; i < m.redak.size(); i++)
    {
        redak.push_back(new int[m.stupac[i]]); //kreiranje redaka
        stupac.push_back(m.stupac[i]);         //spremanje za svaki redak broj stupaca

        for (int j = 0; j < stupac[i]; j++)
        {
            redak[i][j] = m.redak[i][j];       //kopiranje vrijednosti
        }
    }
}

Matrica & Matrica::operator = (const Matrica& m) 
{
    if (this != &m)
    {
        for (int i = 0; i < redak.size(); i++)
        {
            delete[] redak[i];
        }
        redak.clear();
        stupac.clear();

        for (int i = 0; i < m.redak.size(); i++)
        {
            redak.push_back(new int[m.stupac[i]]); //kreiranje redaka
            stupac.push_back(m.stupac[i]);         //spremanje za svaki redak broj stupaca

            for (int j = 0; j < stupac[i]; j++)
            {
                redak[i][j] = m.redak[i][j];       //kopiranje vrijednosti
            }
        }
    }
    return *this;
}


Matrica::Matrica(Matrica&& m) 
{
    for (int i = 0; i < m.redak.size(); i++)
    {
        redak.push_back(m.redak[i]);
        m.redak[i] = NULL;
        stupac.push_back(m.stupac[i]);
    }
}


void Matrica::ispis()
{
    for (int i = 0; i < redak.size(); i++)
    {
        for (int j = 0; j < stupac[i]; j++)
        {
            cout << redak[i][j] << " ";
        }
        cout << endl;
    }
}
Matrica::~Matrica()
{
    for (int i = 0; i < redak.size(); i++)
    {
        delete[] redak[i];
    }
}

int main()
{
    Matrica m;
    m.dodaj(3, new int[3] { 1, 6, 2 });  // dodaj novi redak od 3 stupca
    m.dodaj(5, new int[5] { 5, 3, 4, 7, 0 });
    m.dodaj(4, new int[4] { 6, 2, 6, 5 });
    m.ispis();// ispis matrice redak po redak

    cout << "Kopirni konstruktor:" << endl;
    Matrica m2 = m;
    m2.ispis();

    cout << "Operator pridruživanja:" << endl;
    Matrica m3;
    m3 = m; //operator pridruzivanja s semantikom kopiranja
    m3.ispis();
}
