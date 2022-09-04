#include <iostream>
#include <string>

using namespace std;

class MascaChirurgicala : public Masca
{
	string Culoare;
	int NrPliuri;

public:
	MascaChirurgicala();
	MascaChirurgicala(string tipProt, string cul, int nr);
	MascaChirurgicala(const MascaChirurgicala& m);
	~MascaChirurgicala();

	MascaChirurgicala& operator=(const MascaChirurgicala& m);
	friend istream& operator>>(istream& in, MascaChirurgicala& m);
	friend ostream& operator<<(ostream& out, const MascaChirurgicala& m);

	void set_Culoare(string cul);
	void set_NrPliuri(int nr);

	string get_Culoare();
	int get_NrPliuri();
};

