/*
DODAO SAM ATRIBUT IME SAMO DA PROVJERIM KAKO SE RADIM S NECIM DA NIJE POKAZIVAC

Student
Kopirni konstruktor, operator pridruživanja

Napišite klasu Student koja u privatnom dijelu sadrži pokazivač JMBAG koji pokazuje na znakovni niz duljine 11. U javnom dijelu klase smjestite metode

Student(){}
Student(char* jmbag); // konstruktor (alocira JMBAG duljine 11 znakova)
~Student();	// destruktor (dealocira JMBAG)
char* GetJMBAG() const;
void SetJMBAG(char* noviJMBAG);

Nakon što napišete tijela metoda klase Student napišite funkciju main sa sljedećim sadržajem.

Student Ante("1122334455");
Student Ivica = Ante;

Ante.SetJMBAG("6677889900");
cout << Ante.GetJMBAG() << endl;  // 6677889900
cout << Ivica.GetJMBAG() << endl; // 6677889900 ?!?!

Student Marko;
Marko = Ante;
Marko.SetJMBAG("1234567890");
cout << Marko.GetJMBAG() << endl; // 1234567890
cout << Ante.GetJMBAG() << endl;  // 1234567890 ?!?!


Nakon što pokrenete program potrebno je primijetiti problematične ispise koji su naznačeni u komentarima. Oni su se dogodili kao rezultat plitkog kopiranja (eng. shallow copy) prilikom pozivanja podrazumijevanog kopirnog konstruktora i operatora pridruživanja. Za oba ova slučaja potrebno je realizirati duboko kopiranje tako da konačni ispis bude:

6677889900
1122334455
1234567890
6677889900



*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

class Student {
private:
	char* JMBAG;

public:
	string ime; // dodan javni atribut ime

	Student() = default;
	Student(const char* jmbag, const string& ime);
	~Student();
	char* GetJMBAG() const;
	void SetJMBAG(const char* noviJMBAG);

	Student(const Student& s)
	{
		JMBAG = new char[11];
		strcpy(JMBAG, s.JMBAG);
		ime = s.ime; // kopiranje imena
	}

	Student& operator = (const Student& s)
	{
		if (this != &s)
		{
			delete[] JMBAG;

			JMBAG = new char[11];
			strcpy(JMBAG, s.JMBAG);
			ime = s.ime; // kopiranje imena
		}
		return *this;
	}

	Student(Student&& s)
	{
		JMBAG = s.JMBAG;
		s.JMBAG = NULL;
		ime = move(s.ime); // premještanje imena
	}

	Student& operator = (Student&& s)
	{
		delete[] JMBAG;
		JMBAG = s.JMBAG;
		s.JMBAG = NULL;
		ime = move(s.ime); // premještanje imena
		return *this;
	}
};

Student::Student(const char* jmbag, const string& ime) : ime(ime)
{
	JMBAG = new char[11];
	SetJMBAG(jmbag);
}

Student::~Student() {
	delete[] JMBAG;
}

char* Student::GetJMBAG() const {
	return JMBAG;
}

void Student::SetJMBAG(const char* noviJMBAG) {
	strcpy(JMBAG, noviJMBAG);
}

int main()
{
	Student Ante("1122334455", "Ante");
	Student Ivica = Ante;

	Ante.SetJMBAG("6677889900");
	cout << Ante.GetJMBAG() << " " << Ante.ime << endl;  // 6677889900 Ante
	cout << Ivica.GetJMBAG() << " " << Ivica.ime << endl; // 1122334455 Ante

	Student Marko;
	Marko = Ante;
	Marko.SetJMBAG("1234567890");
	cout << Marko.GetJMBAG() << " " << Marko.ime << endl; // 1234567890 Ante
	cout << Ante.GetJMBAG() << " " << Ante.ime << endl;  // 6677889900 Ante

	return 0;
}
