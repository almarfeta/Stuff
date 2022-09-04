#include "Masca.h"
#include <iostream>
#include <string>

using namespace std;

Masca::Masca() {
	TipProtectie = "unknown";
}
Masca::Masca(string tipProtectie) {
	TipProtectie = tipProtectie;
}
Masca::Masca(const Masca& m) {
	TipProtectie = m.TipProtectie;
}
Masca::~Masca() { }


Masca& Masca::operator=(const Masca& m) {
	if (this != &m) {
		TipProtectie = m.TipProtectie;
	}
	return *this;
}
istream& operator>>(istream& in, Masca& m) {
	cout << "Tip Protectie: ";
	in >> m.TipProtectie;

	return in;
}
ostream& operator<<(ostream& out, const Masca& m) {
	out << "Tip Protectie: " << m.TipProtectie << "\n";

	return out;
}


void Masca::set_TipProtectie(string tipProt) {
	TipProtectie = tipProt;
}


string Masca::get_TipProtectie() {
	return TipProtectie;
}