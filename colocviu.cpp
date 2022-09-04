#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Malware {
protected:
	double Rating;
	string Data;
	string Nume;
	string MetodaInfectare;
	vector <string> Registrii;

public:
	Malware() {
		Rating = 0;
		Data = "No data";
		Nume = "No name";
		MetodaInfectare = "Unknown";
	}
	Malware(string data, string nume, string metodaInfectare, vector <string> registrii) {
		Rating = 0;
		Data = data;
		Nume = nume;
		MetodaInfectare = metodaInfectare;
		Registrii = registrii;
	}

	double get_Rating() {
		return Rating;
	}

	virtual void print(ostream& output) const {
		output << "Rating = " << Rating << "\n" <<
			"Data = " << Data << "\n" <<
			"Nume = " << Nume << "\n" <<
			"Metoda Infectare = " << MetodaInfectare << "\n" <<
			"Registrii = ";
		for (string registru : Registrii)
			output << registru << " ";
		output << "\n";
	}
	friend ostream& operator<<(ostream& output, const Malware& malware) {
		malware.print(output);
		return output;
	}

	virtual void calculeaza_rating() = 0;
};

class Rootkit : public Malware {
private:
	vector <string> ListaImporturi;
	vector <string> ListaStringuri;

public:
	Rootkit() :Malware() { }
	Rootkit(string data, string nume, string metodaInfectare, vector <string> registrii,
		vector <string> listaImporturi, vector <string> listaStringuri) : Malware(data, nume, metodaInfectare, registrii) {
		ListaImporturi = listaImporturi;
		ListaStringuri = listaStringuri;
	}

	void print(ostream& output) const {
		output << "Rating = " << Rating << "\n" <<
			"Data = " << Data << "\n" <<
			"Nume = " << Nume << "\n" <<
			"Metoda Infectare = " << MetodaInfectare << "\n" <<
			"Registrii = ";
		for (string registru : Registrii)
			output << registru << " ";
		output << "\n";
		output << "Lista Importuri = ";
		for (string import : ListaImporturi)
			output << import << " ";
		output << "\nLista Stringuri = ";
		for (string sir : ListaStringuri)
			output << sir << " ";
		output << "\n";
	}

	void calculeaza_rating() {
		for (string sir : ListaStringuri) {
			if (sir == "System Service Descriptor Table" || sir == "SSDT" || sir == "NtCreateFile")
				Rating += 100;
		}
		for (string import : ListaImporturi) {
			if (import == "ntoskrnl.exe")
				Rating *= 2;
		}
		for (string registru : Registrii) {
			if (registru == "HKLM-run" || registru == "HKCU-run") {
				Rating += 20;
			}
		}
	}
};

class Keylogger : public Malware {
private:
	vector <string> ListaFunctii;
	vector <string> ListaTaste;

public:
	Keylogger() :Malware() { }
	Keylogger(string data, string nume, string metodaInfectare, vector <string> registrii,
		vector <string> listaFunctii, vector <string> listaTaste) : Malware(data, nume, metodaInfectare, registrii) {
		ListaFunctii = listaFunctii;
		ListaTaste = listaTaste;
	}

	void print(ostream& output) const {
		output << "Rating = " << Rating << "\n" <<
			"Data = " << Data << "\n" <<
			"Nume = " << Nume << "\n" <<
			"Metoda Infectare = " << MetodaInfectare << "\n" <<
			"Registrii = ";
		for (string registru : Registrii)
			output << registru << " ";
		output << "\n";
		output << "Lista Functii = ";
		for (string functie : ListaFunctii)
			output << functie << " ";
		output << "\nLista Taste = ";
		for (string tasta : ListaTaste)
			output << tasta << " ";
		output << "\n";
	}

	void calculeaza_rating() {
		for (string functie : ListaFunctii) {
			if (functie == "CreateFileW" || functie == "OpenProcess" || functie == "ReadFile" || functie == "WriteFile" ||
				functie == "RegisterHotKey" || functie == "SetWindowsHookEx") {
				Rating += 30;
			}
		}
		for (string tasta : ListaTaste) {
			if (tasta == "[Up]" || tasta == "[Num Lock]" || tasta == "[Down]" ||
				tasta == "[Right]" || tasta == "[UP]" || tasta == "[Left]" || tasta == "[PageDown]") {
				Rating += 10;
			}
		}
		for (string registru : Registrii) {
			if (registru == "HKLM-run" || registru == "HKCU-run") {
				Rating += 20;
			}
		}
	}
};

class Kernel_Keylogger : public Malware {
private:
	vector <string> ListaImporturi;
	vector <string> ListaStringuri;
	vector <string> ListaFunctii;
	vector <string> ListaTaste;
	bool AscundeRegistrii;
	bool AscundeFisiere;

public:
	Kernel_Keylogger() :Malware() {
		AscundeRegistrii = false;
		AscundeFisiere = false;
	}
	Kernel_Keylogger(string data, string nume, string metodaInfectare, vector <string> registrii,
		vector <string> listaImporturi, vector <string> listaStringuri,
		vector <string> listaFunctii, vector <string> listaTaste,
		bool ascundeRegistrii, bool ascundeFisiere) : Malware(data, nume, metodaInfectare, registrii) {
		ListaImporturi = listaImporturi;
		ListaStringuri = listaStringuri;
		ListaFunctii = listaFunctii;
		ListaTaste = listaTaste;
		AscundeRegistrii = ascundeRegistrii;
		AscundeFisiere = ascundeFisiere;
	}

	void print(ostream& output) const {
		output << "Rating = " << Rating << "\n" <<
			"Data = " << Data << "\n" <<
			"Nume = " << Nume << "\n" <<
			"Metoda Infectare = " << MetodaInfectare << "\n" <<
			"Registrii = ";
		for (string registru : Registrii)
			output << registru << " ";
		output << "\n";
		output << "Lista Importuri = ";
		for (string import : ListaImporturi)
			output << import << " ";
		output << "\nLista Stringuri = ";
		for (string sir : ListaStringuri)
			output << sir << " ";
		output << "\nLista Functii = ";
		for (string functie : ListaFunctii)
			output << functie << " ";
		output << "\nLista Taste = ";
		for (string tasta : ListaTaste)
			output << tasta << " ";
		if (AscundeRegistrii)
			output << "\nDa\n";
		else
			output << "\nNu\n";
		if (AscundeFisiere)
			output << "Da\n";
		else
			output << "Nu\n";
	}

	void calculeaza_rating() {
		for (string sir : ListaStringuri) {
			if (sir == "System Service Descriptor Table" || sir == "SSDT" || sir == "NtCreateFile")
				Rating += 100;
		}
		for (string import : ListaImporturi) {
			if (import == "ntoskrnl.exe")
				Rating *= 2;
		}
		for (string functie : ListaFunctii) {
			if (functie == "CreateFileW" || functie == "OpenProcess" || functie == "ReadFile" || functie == "WriteFile" ||
				functie == "RegisterHotKey" || functie == "SetWindowsHookEx") {
				Rating += 30;
			}
		}
		for (string tasta : ListaTaste) {
			if (tasta == "[Up]" || tasta == "[Num Lock]" || tasta == "[Down]" ||
				tasta == "[Right]" || tasta == "[UP]" || tasta == "[Left]" || tasta == "[PageDown]") {
				Rating += 10;
			}
		}
		if (AscundeFisiere)
			Rating += 20;
		if (AscundeRegistrii)
			Rating += 30;
		for (string registru : Registrii) {
			if (registru == "HKLM-run" || registru == "HKCU-run") {
				Rating += 20;
			}
		}
	}

};

class Ransomware : public Malware {
private:
	int RatingCriptare;
	double RatingObfuscare;

public:
	Ransomware() : Malware() { 
		RatingCriptare = 0;
		RatingObfuscare = 0;
	}
	Ransomware(string data, string nume, string metodaInfectare, vector <string> registrii,
		int ratingCriptare, double ratingObfuscare) : Malware(data, nume, metodaInfectare, registrii) {
		RatingCriptare = ratingCriptare;
		RatingObfuscare = ratingObfuscare;
	}

	void print(ostream& output) const {
		output << "Rating = " << Rating << "\n" <<
			"Data = " << Data << "\n" <<
			"Nume = " << Nume << "\n" <<
			"Metoda Infectare = " << MetodaInfectare << "\n" <<
			"Registrii = ";
		for (string registru : Registrii)
			output << registru << " ";
		output << "\n";
		output << "Rating Criptare = " << RatingCriptare << "\n"
			<< "Rating Obfuscare = " << RatingObfuscare << "\n";
	}

	void calculeaza_rating() {
		Rating += RatingCriptare + RatingObfuscare;
		for (string registru : Registrii) {
			if (registru == "HKLM-run" || registru == "HKCU-run") {
				Rating += 20;
			}
		}
	}
};

class Computer {
private:
	static int Nr_computere;
	int ID;
	vector <Malware*> ListaMalware;
	double RatingFinal;

public:
	Computer() {
		Nr_computere++;
		ID = Nr_computere;
		RatingFinal = 0;
	}
	Computer(vector <Malware*> listaMalware) {
		Nr_computere++;
		ID = Nr_computere;
		ListaMalware = listaMalware;
		RatingFinal = 0;
		for (Malware* malware : ListaMalware) {
			malware->calculeaza_rating();
			RatingFinal += malware->get_Rating();
		}
	}

	friend ostream& operator<<(ostream& out, const Computer& computer) {
		out << "ID = " << computer.ID << "\n"
			<< "Rating Final = " << computer.RatingFinal << "\n"
			<< "Lista Malware = ";
		for (Malware* malware : computer.ListaMalware) {
			out << (*malware) << "\n";
		}
		return out;
	}
};
int Computer::Nr_computere = 0;



void meniu() {
	vector <Malware*> listaMalware;
	listaMalware.push_back(new Rootkit("12.12.2022", "Rootkit", "Cumva", { "t0", "t1" }, { "Ceva", "ntoskrnl.exe" }, { "Altceva", "SSDT" }));
	listaMalware.push_back(new Keylogger("15.15.2015", "Keylogger", "Altcumva", { "HKLM-run" }, { "RegisterHotKey" }, { "[Up]" }));
	Computer computer1 = Computer(listaMalware);
	vector <Malware*> listaMalware2;

	listaMalware2.push_back(new Ransomware("01.01.2001", "Ransomware", "Habarnam", { "HKCU-run" }, 6, 23.5));
	Computer computer2 = Computer(listaMalware2);

	vector <Computer> computers;
	computers.push_back(computer1);
	computers.push_back(computer2);


	int comanda;
	while (true) {
		cout << "Comenzi: 1) Afisare calculatoare;\n 2) Afisare calculatoare sortate;\n 3) Afisare primele k sortate;\n" <<
			" 4)Afisare procent infectare\n 5) Inchide program\n";
		cin >> comanda;
		if (comanda == 1) { //afisarea informatiilor pt fiecare calculator
			for (Computer computer : computers) {
				cout << computer << "\n";
			}
		}
		else if (comanda == 2) { //afisare informatii pt fiecare calculator, ordonati dupa ratig final

		}
		else if (comanda == 3) { //afisarea primelor k calculatoare ordonate

		}
		else if (comanda == 4) { //afisare % computere afectate

		}
		else if (comanda == 5) { //exit
			cout << "Program incheiat";
			break;
		}
		else
			cout << "Comanda invalida\n";
	}
}

int main() {
	meniu();
	return 0;
}
