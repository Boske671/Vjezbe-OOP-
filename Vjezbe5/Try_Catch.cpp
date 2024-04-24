#include <iostream>
#include <vector>
#include <exception>

using namespace std;

class PrevelikBroj : public exception
{
public:
	int broj;
	PrevelikBroj(int broj) : broj(broj) { }
	const char* poruka() const noexcept
	{
		return "prevelik broj";
	}

};

class PremaliBroj : public exception
{
public:
	int broj;
	PremaliBroj(int broj) : broj(broj) { }
	const char* poruka() const noexcept
	{
		return "premali broj";
	}
};

void test(int a)
{
	cout << "pocetak testa" << endl;
	cout << "pocetak primjera" << endl;

	if (a > 1)
	{
		throw PrevelikBroj(a);
	}
	else
	{
		throw PremaliBroj(a);
	}
}

int main() {
	try {
		test(2);
		cout << "nastavak try-bloka...\n";
	}
	catch (const PrevelikBroj& e) {
		cout << e.poruka() << endl;
	}
	catch (const PremaliBroj& e) {
		cout << e.poruka() << endl;
	}
	catch (...) {
		cout << "... neka druga greska!";
	}

	cout << "nastavak main funkcije\n";
}
