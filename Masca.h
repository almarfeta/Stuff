#include <iostream>
#include <string>

using namespace std;

class Masca
{
	string TipProtectie;

public:
	Masca();
	Masca(string tipProt);
	Masca(const Masca& m);
	~Masca();

	Masca& operator=(const Masca& m);
	friend istream& operator>>(istream& in, Masca& m);
	friend ostream& operator<<(ostream& out, const Masca& m);

	void set_TipProtectie(string tipProt);
	
	string get_TipProtectie();

	//virtual double get_Pret() = 0;
};

