#include "Masca.h"
#include "MascaChirurgicala.h"
#include <iostream>
#include <string>

using namespace std;

MascaChirurgicala::MascaChirurgicala() : Masca() {
	Culoare = "unknown";
	NrPliuri = 0;
}
MascaChirurgicala::MascaChirurgicala(string tipProt, string cul, int nr) : Masca(tipProt) {
	Culoare = cul;
	NrPliuri = nr;
}
MascaChirurgicala::MascaChirurgicala(const MascaChirurgicala& m) : Masca(m) {
	Culoare = m.Culoare;
	NrPliuri = m.NrPliuri;
}
MascaChirurgicala::~MascaChirurgicala() { }


MascaChirurgicala& MascaChirurgicala::operator=(const MascaChirurgicala& m) {
	if (this != &m) {
		Masca::operator=(m);
		Culoare = m.Culoare;
		NrPliuri = m.NrPliuri;
	}
	return *this;
}
istream& operator>>(istream& in, MascaChirurgicala& m) {
	in >> (Masca&) m;

	cout << "Culoare: ";
	in >> m.Culoare;
	cout << "Nr Pliuri: ";
	in >> m.NrPliuri;

	return in;
}
ostream& operator<<(ostream& out, const MascaChirurgicala& m) {
	out << (Masca&) m;

	out << "Culoare: " << m.Culoare << "\n";
	out << "Nr Pliuri: " << m.NrPliuri << "\n";

	return out;
}


void MascaChirurgicala::set_Culoare(string cul) {
	Culoare = cul;
}
void MascaChirurgicala::set_NrPliuri(int nr) {
	NrPliuri = nr;
}



string MascaChirurgicala::get_Culoare() {
	return Culoare;
}
int MascaChirurgicala::get_NrPliuri() {
	return NrPliuri;
}