#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
class Magazin
{
protected:
	char* oras;
	string numeMagazin;
	int nrAngajati;
	int nrLuni;
	float* venituriLunare;
	float suprafataMagazin;
	bool esteNonStop;
	const float TVA;
public:
	static int clasaCAENPrincipala;
	
	Magazin() :TVA(0.19)
	{
		
		this->oras = new char[strlen("Necunoscut") + 1];
		strcpy(this->oras, "Necunoscut");

		this->numeMagazin = "Anonim";
		this->nrAngajati = 0;
		this->nrLuni = 0;
		this->venituriLunare = NULL; //VECTORUL ESTE GOL
		this->suprafataMagazin = 0;
		this->esteNonStop = 1; //adevarat

	}

	
	Magazin(const char* oras, string numeMagazin, int nrAngajati, int nrLuni, float* venituriLunare, float suprafataMagazin, bool esteNonStop, float TVA) :TVA(TVA)
	{
		this->oras = new char[strlen(oras) + 1];
		//2) initializam atributul
		strcpy(this->oras, oras);

		this->numeMagazin = numeMagazin;
		this->nrAngajati = nrAngajati;

		this->nrLuni = nrLuni;
		this->venituriLunare = new float[this->nrLuni];
		for (int i = 0; i < this->nrLuni; i++)
		{
			this->venituriLunare[i] = venituriLunare[i];
		}

		this->suprafataMagazin = suprafataMagazin;
		this->esteNonStop = esteNonStop;
	}


	
	~Magazin()
	{
		
		if (this->oras != NULL)
		{
			delete[] this->oras;
		}
		if (this->venituriLunare != NULL)
		{
			delete[] this->venituriLunare;
		}
		cout << "S-a apelat destructorul!" << endl;
	}



	char* getOras()
	{
		return this->oras;
	}

	string getNumeMagazin()
	{
		return this->numeMagazin;
	}

	int getNrAngajati()
	{
		return this->nrAngajati;
	}

	int getNrLuni()
	{
		return this->nrLuni;
	}

	float* getVenituriLunare()
	{
		return this->venituriLunare;
	}

	float getSuprafataMagazin()
	{
		return this->suprafataMagazin;
	}

	bool getEsteNonStop()
	{
		return this->esteNonStop;
	}

	float getTVA()
	{
		return this->TVA;
	}

	
	void setVenituriLunare(int nrLuniNou, float* venituriLunareNoi)
	{
		this->nrLuni = nrLuniNou;
		if (this->venituriLunare != NULL)
		{
			delete[] this->venituriLunare;
		}
		this->venituriLunare = new float[this->nrLuni];
		for (int i = 0; i < this->nrLuni; i++)
		{
			this->venituriLunare[i] = venituriLunareNoi[i];
		}
	}

	void setOras(const char* numeOrasNou)
	{
		
		if (this->oras != NULL)
		{
			delete[] this->oras;
		}
		this->oras = new char[strlen(numeOrasNou) + 1];
		strcpy(this->oras, numeOrasNou);
	}

	void setNumeMagazin(string numeMagazinNou)
	{
		this->numeMagazin = numeMagazinNou;
	}


	void setNrAngajati(int nrAngajatiNou)
	{
		this->nrAngajati = nrAngajatiNou;
	}

	void setSuprafataMagazin(float suprafataMagazinNoua)
	{
		this->suprafataMagazin = suprafataMagazinNoua;
	}

	void setEsteNonStop(bool esteNonStopNou)
	{
		this->esteNonStop = esteNonStopNou;
	}


	
	Magazin(const Magazin& obj) :TVA(obj.TVA)
	{
		this->oras = new char[strlen(obj.oras) + 1];
		strcpy(this->oras, obj.oras);

		this->numeMagazin = obj.numeMagazin;
		this->nrAngajati = obj.nrAngajati;

		this->nrLuni = obj.nrLuni;
		this->venituriLunare = new float[this->nrLuni];
		for (int i = 0; i < this->nrLuni; i++)
		{
			this->venituriLunare[i] = obj.venituriLunare[i];
		}

		this->suprafataMagazin = obj.suprafataMagazin;
		this->esteNonStop = obj.esteNonStop;


	}

	
	Magazin& operator=(const Magazin& obj)
	{
		if (this->oras != NULL)
		{
			delete[] this->oras;
		}
		if (this->venituriLunare != NULL)
		{
			delete[] this->venituriLunare;
		}
		this->oras = new char[strlen(obj.oras) + 1];
		strcpy(this->oras, obj.oras);

		this->numeMagazin = obj.numeMagazin;
		this->nrAngajati = obj.nrAngajati;

		this->nrLuni = obj.nrLuni;
		this->venituriLunare = new float[this->nrLuni];
		for (int i = 0; i < this->nrLuni; i++)
		{
			this->venituriLunare[i] = obj.venituriLunare[i];
		}

		this->suprafataMagazin = obj.suprafataMagazin;
		this->esteNonStop = obj.esteNonStop;

		return *this;
	}


	float totalVenituri(/*this*/)
	{
		float suma = 0;
		for (int i = 0; i < this->nrLuni; i++)
		{
			suma = suma + this->venituriLunare[i];
		}
		return suma;
	}

	
	float venituriMedii()
	{
		float suma = 0;
		for (int i = 0; i < this->nrLuni; i++)
		{
			suma = suma + this->venituriLunare[i];
		}
		return suma / this->nrLuni;
	}

	
	float maximVenituri()
	{
		float max = this->venituriLunare[0];
		for (int i = 1; i < this->nrLuni; i++)
		{
			if (max < this->venituriLunare[i])
			{
				max = this->venituriLunare[i];
			}
		}
		return max;
	}

	float minimVenituri()
	{
		float min = this->venituriLunare[0];
		for (int i = 1; i < this->nrLuni; i++)
		{
			if (min > this->venituriLunare[i])
			{
				min = this->venituriLunare[i];
			}
		}
		return min;
	}

	float calculTVALuna(int nrLuna)
	{
		if (nrLuna < this->nrLuni && nrLuna >= 0)
		{
			return this->TVA * this->venituriLunare[nrLuna];
		}
		else
		{
			return -1;
		}
	}

	void verificareNonStop(/*this*/)
	{
		if (this->esteNonStop == 1)
		{
			cout << "Magazinul este non stop!";
		}
		else
		{
			cout << "Magazinul nu este non stop!";
		}
	}

	
	void adaugaVenit(float venituriNoi)
	{
		Magazin copieObiect = *this;

		if (this->venituriLunare != NULL)
		{
			delete[] this->venituriLunare;
		}

		this->nrLuni++; 
		this->venituriLunare = new float[this->nrLuni];

		for (int i = 0; i < this->nrLuni - 1; i++)
		{
			this->venituriLunare[i] = copieObiect.venituriLunare[i];
		}

		this->venituriLunare[this->nrLuni - 1] = venituriNoi;
	}

	
	void eliminaVenitDupaPozitie(int pozitieDorita)
	{
		Magazin copieObiect = *this;

		if (this->venituriLunare != NULL)
		{
			delete[] this->venituriLunare;
		}

		this->nrLuni--; //this->nrLuni=this->nrLuni-1;

		this->venituriLunare = new float[this->nrLuni];

		
		for (int i = 0; i < pozitieDorita; i++)
		{
			this->venituriLunare[i] = copieObiect.venituriLunare[i];
		}
		for (int i = pozitieDorita + 1; i < this->nrLuni + 1; i++)
		{
			this->venituriLunare[i - 1] = copieObiect.venituriLunare[i];
		}

		
	}

	
	void eliminaDupaValoare(float valDorita)
	{
		Magazin copieObiect = *this;

		if (this->venituriLunare != NULL)
		{
			delete[] this->venituriLunare;
		}

		int nr = 0;
		for (int i = 0; i < copieObiect.nrLuni; i++)
		{
			if (copieObiect.venituriLunare[i] == valDorita)
			{
				nr++;
			}
		}

		this->nrLuni = this->nrLuni - nr;

		this->venituriLunare = new float[this->nrLuni];

		int poz = 0;
		for (int i = 0; i < copieObiect.nrLuni; i++)
		{
			if (valDorita != copieObiect.venituriLunare[i])
			{
				this->venituriLunare[poz] = copieObiect.venituriLunare[i];
				poz++;
			}
		}
	}

	virtual string returneazaClasaInCareMaAflu()
	{
		return "SUNT IN CLASA DE BAZA, CLASA MAGAZIN";
	}

	e va ajuta la afisarea pe consola si un obiect de tipul clasei noastre pe caree il vom afisa pe consola(pentru ca nu mai avem ca si parametru implicit obiectul this din cauza atributului friend
	friend ostream& operator<<(/*nu mai avem this*/ostream& out, Magazin& m)
	{
		out << "Oras:" << m.oras << endl;
		out << "Nume magazin:" << m.numeMagazin << endl;
		out << "Numar angajati:" << m.nrAngajati << endl;
		out << "Numar luni:" << m.nrLuni << endl;
		cout << "Venituri lunare:" << endl;
		for (int i = 0; i < m.nrLuni; i++)
		{
			out << m.venituriLunare[i] << " ; ";
		}
		out << endl;
		out << "Suprafata magazin:" << m.suprafataMagazin << endl;
		out << "Este non-stop? (1-da  0-nu):" << m.esteNonStop << endl;
		out << "TVA:" << m.TVA << endl;
		return out;
	}

	friend istream& operator>>(istream& in, Magazin& m)
	{
		if (m.oras != NULL)
		{
			delete[] m.oras;
		}
		if (m.venituriLunare != NULL)
		{
			delete[] m.venituriLunare;
		}
		char aux[50];
		cout << "Introduceti orasul:";
		in >> aux;
		m.oras = new char[strlen(aux) + 1];
		strcpy(m.oras, aux);

		cout << "Introduceti nume magazin:" << endl;
		in >> m.numeMagazin;

		cout << "Introduceti nr angajati:" << endl;
		in >> m.nrAngajati;

		cout << "Introduceti nr luni:" << endl;
		in >> m.nrLuni;

		m.venituriLunare = new float[m.nrLuni];
		cout << "Introduceti veniturile lunare:" << endl;
		for (int i = 0; i < m.nrLuni; i++)
		{
			in >> m.venituriLunare[i];
			cout << endl;
		}

		cout << "Introduceti suprafata magazin:" << endl;
		in >> m.suprafataMagazin;

		cout << "Este sau nu este non-stop? 1-da 0-nu" << endl;
		in >> m.esteNonStop;

		return in;
	}


	
	float operator[](int pozitieVector)
	{
		if (pozitieVector >= 0 && pozitieVector < this->nrLuni)
		{
			return this->venituriLunare[pozitieVector];
		}
		else
		{
			return -1;
		}
	}

	
	bool operator>(/*this*/Magazin& m)
	{
		
		if (this->suprafataMagazin > m.suprafataMagazin)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

	bool operator ==(int nrAngajatiDeComparat)
	{
		if (this->nrAngajati == nrAngajatiDeComparat)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

	
	void operator()(int pozitieDorita, float valoareAdaos)
	{
		if (pozitieDorita >= 0 && pozitieDorita < this->nrLuni)
		{
			this->venituriLunare[pozitieDorita] = this->venituriLunare[pozitieDorita] + valoareAdaos;
		}
	}

	
	operator int()
	{
		int nr = 0;
		for (int i = 0; i < this->nrLuni; i++)
		{
			if (this->venituriLunare[i] > 500)
			{
				nr++;
			}
		}
		return nr;
	}

	
	operator float()
	{
		float medie = 0;
		if (this->nrLuni >= 2)
		{
			for (int i = 0; i < 2; i++)
			{
				medie = medie + this->venituriLunare[i];
			}
			medie = medie / 2;
			return medie;
		}
		else
		{
			return -1; //eroare
		}
	}

	
	operator string(/*this*/)
	{
		string propozitie = "Numele magazinului nostru este:" + this->numeMagazin;
		return propozitie;
	}

	
	friend void operator!(Magazin& m)
	{
		if (m.esteNonStop == 1)
		{
			m.esteNonStop = 0;
		}
		else
		{
			m.esteNonStop = 1;
		}
	}

	Magazin& operator+=(/*this*/float venituriNoi)
	{
		Magazin copieObiect = *this;

		if (this->venituriLunare != NULL)
		{
			delete[] this->venituriLunare;
		}

		this->nrLuni++; 

		this->venituriLunare = new float[this->nrLuni];

		for (int i = 0; i < this->nrLuni - 1; i++)
		{
			this->venituriLunare[i] = copieObiect.venituriLunare[i];
		}

		this->venituriLunare[this->nrLuni - 1] = venituriNoi;

		return *this;
	}


	
	Magazin& operator-=(int pozitieDorita)
	{
		Magazin copieObiect = *this;

		if (this->venituriLunare != NULL)
		{
			delete[] this->venituriLunare;
		}

		this->nrLuni--; //this->nrLuni=this->nrLuni-1;

		this->venituriLunare = new float[this->nrLuni];

		
		for (int i = 0; i < pozitieDorita; i++)
		{
			this->venituriLunare[i] = copieObiect.venituriLunare[i];
		}
		for (int i = pozitieDorita + 1; i < this->nrLuni + 1; i++)
		{
			this->venituriLunare[i - 1] = copieObiect.venituriLunare[i];
		}

		
		return *this;
	}

	
	Magazin& operator++()
	{
		this->nrAngajati++;
		return *this;
	}

	
	Magazin operator++(int)
	{
		Magazin copie = *this;
		this->nrAngajati++;
		return copie;
	}

	


 valoarea niciodata!)
	friend ofstream& operator<<(/*nu mai avem this*/ofstream& file, Magazin& m)
	{
		file << m.oras << endl;
		file << m.numeMagazin << endl;
		file << m.nrAngajati << endl;
		file << m.nrLuni << endl;
		for (int i = 0; i < m.nrLuni; i++)
		{
			file << m.venituriLunare[i] << " ";
		}
		file << endl;
		file << m.suprafataMagazin << endl;
		file << m.esteNonStop << endl;
		return file;
	}

	
	friend ifstream& operator>>(/*nu avem this*/ifstream& file, Magazin& m)
	{
		if (m.oras != NULL)
		{
			delete[] m.oras;
		}
		if (m.venituriLunare != NULL)
		{
			delete[] m.venituriLunare;
		}
		char aux[50];
		file >> aux;
		m.oras = new char[strlen(aux) + 1];
		strcpy(m.oras, aux);
		file >> m.numeMagazin;
		file >> m.nrAngajati;
		file >> m.nrLuni;
		m.venituriLunare = new float[m.nrLuni];
		for (int i = 0; i < m.nrLuni; i++)
		{
			file >> m.venituriLunare[i];
		}
		file >> m.suprafataMagazin;
		file >> m.esteNonStop;
		return file;
	}




	
	void scriereBinar(fstream& file) 
	{
		int nrLitereOras = strlen(this->oras); 
		file.write((char*)&nrLitereOras, sizeof(int)); 
		for (int i = 0; i < nrLitereOras; i++)
		{
			file.write((char*)&this->oras[i], sizeof(char));
		}

		int nrLitireNumeMagazin = this->numeMagazin.size(); 
		file.write((char*)&nrLitireNumeMagazin, sizeof(int));
		file.write(this->numeMagazin.c_str(), nrLitireNumeMagazin);

		file.write((char*)&this->nrAngajati, sizeof(int));


		file.write((char*)&this->nrLuni, sizeof(int));

		for (int i = 0; i < this->nrLuni; i++)
		{
			file.write((char*)&this->venituriLunare[i], sizeof(float));
		}

		file.write((char*)&this->suprafataMagazin, sizeof(float));

		file.write((char*)&this->esteNonStop, sizeof(bool));
	}

	
	void citireBinar(fstream& file)
	{
		if (this->oras != NULL)
		{
			delete[] this->oras;
		}
		if (this->venituriLunare != NULL)
		{
			delete[] this->venituriLunare;
		}

		int nrLitereOras;
		file.read((char*)&nrLitereOras, sizeof(int));
		this->oras = new char[nrLitereOras + 1];
		for (int i = 0; i < nrLitereOras; i++)
		{
			file.read((char*)&this->oras[i], sizeof(char));
		}
		this->oras[nrLitereOras] = '\0';

		int nrLitireNumeMagazin; 
		file.read((char*)&nrLitireNumeMagazin, sizeof(int)); 
		string aux;
		aux.resize(nrLitireNumeMagazin);
		file.read((char*)aux.c_str(), nrLitireNumeMagazin);
		this->numeMagazin = aux;

		
		file.read((char*)&this->nrAngajati, sizeof(int));

		file.read((char*)&this->nrLuni, sizeof(int));

		this->venituriLunare = new float[this->nrLuni];
		for (int i = 0; i < this->nrLuni; i++)
		{
			file.read((char*)&this->venituriLunare[i], sizeof(float));
		}

		file.read((char*)&this->suprafataMagazin, sizeof(float));

		//bool
		file.read((char*)&this->esteNonStop, sizeof(bool));

	}
};

int Magazin::clasaCAENPrincipala = 47;


class MagazinDeElectrocasnice :public Magazin

{
	bool livrareLaDomiciliu;
	//bool plataInRate;
	float dobandaRate;
public:

	MagazinDeElectrocasnice() :Magazin()
	{
		this->livrareLaDomiciliu = 0;
		this->dobandaRate = 0;
	}

	MagazinDeElectrocasnice(bool livrareLaDomiciliu, float dobandaRate, const char* oras, string numeMagazin, int nrAngajati, int nrLuni, float* venituriLunare, float suprafataMagazin, bool esteNonStop, float TVA) :Magazin(oras, numeMagazin, nrAngajati, nrLuni, venituriLunare, suprafataMagazin, esteNonStop, TVA)
	{
		this->livrareLaDomiciliu = livrareLaDomiciliu;
		this->dobandaRate = dobandaRate;
	}


	
	~MagazinDeElectrocasnice()
	{

	}

	bool getLivrareLaDomiciliu()
	{
		return this->livrareLaDomiciliu;
	}
	float getDobandaRate()
	{
		return this->dobandaRate;
	}

	
	void setLivrareLaDomiciliu(bool livrareLaDomicliuNou)
	{
		this->livrareLaDomiciliu = livrareLaDomicliuNou;
	}
	void setDobandaRate(float dobandaRateNoua)
	{
		this->dobandaRate = dobandaRateNoua;
	}

	
	MagazinDeElectrocasnice(const MagazinDeElectrocasnice& obj) :Magazin(obj)
	{
		this->livrareLaDomiciliu = obj.livrareLaDomiciliu;
		this->dobandaRate = obj.dobandaRate;
	}


	
	MagazinDeElectrocasnice(const Magazin& obj) :Magazin(obj)
	{
		this->livrareLaDomiciliu = 0;
		this->dobandaRate = 0;
	}


	MagazinDeElectrocasnice& operator=(const MagazinDeElectrocasnice&obj)
	{
		Magazin::operator =(obj);
		this->livrareLaDomiciliu = obj.livrareLaDomiciliu;
		this->dobandaRate = obj.dobandaRate;
		return *this;
	}

	
	float calculDobandaProdus(float pretProdus)
	{
		float dobanda = this->dobandaRate * pretProdus;
		return dobanda;
	}

	friend ostream& operator<<(ostream& out, MagazinDeElectrocasnice& obj)
	{
		out << (Magazin&)obj;
		out <<"Livrare la domiciliu (1-DA 0-NU): " << obj.livrareLaDomiciliu << endl;
		out << "Dobanda rate:" << obj.dobandaRate << endl;
		return out;
	 }

	friend istream& operator>>(istream& in, MagazinDeElectrocasnice& obj)
	{
		in >> (Magazin&)obj;
		cout << "Introduceti daca avem livrare la domiciliu (1-DA 0-NU): ";
		in >> obj.livrareLaDomiciliu;
		cout << "Introduceti dobanda pentru rate: ";
		in >> obj.dobandaRate;
		return in;
	}

	
	friend ifstream& operator>>(ifstream& file, Magazin& m)
	{
		if (m.oras != NULL)
		{
			delete[] m.oras;
		}
		if (m.venituriLunare != NULL)
		{
			delete[] m.venituriLunare;
		}
		char aux[50];
		file >> aux;
		m.oras = new char[strlen(aux) + 1];
		strcpy(m.oras, aux);
		file >> m.numeMagazin;
		file >> m.nrAngajati;
		file >> m.nrLuni;
		m.venituriLunare = new float[m.nrLuni];
		for (int i = 0; i < m.nrLuni; i++)
		{
			file >> m.venituriLunare[i];
		}
		file >> m.suprafataMagazin;
		file >> m.esteNonStop;
		file >> m.livreareLaDomiciliu;
		file >> m.dobandaRate;
		return file;



	
	string returneazaClasaInCareMaAflu()
	{
		return "SUNT IN CLASA DERIVATA, CLASA MAGAZIN DE ELECTROCASNICE";
	}

	

};




void main()
{
	Magazin m; 

	float vector1[] = { 100.9,259.67 };
	float vector2[] = { 10000,10000,789.5,600.9,10000 };
	Magazin m3("Iasi", "H%M", 90, 2, vector1, 67, 0, 0.19);
	Magazin m4("Bucuresti", "Cora", 300, 5, vector2, 200, 0, 0.19);


	cout << "--------------------------------------GETTERI------------------------" << endl << endl;
	
	cout << m.getOras() << endl;
	cout << m.getNumeMagazin() << endl;
	cout << m.getNrAngajati() << endl;
	cout << m.getNrLuni() << endl;
	cout << m.getVenituriLunare() << endl;
	cout << m.getSuprafataMagazin() << endl;
	cout << m.getEsteNonStop() << endl;
	cout << m.getTVA() << endl;
	cout << endl << endl;

	cout << m3.getOras() << endl;
	cout << m3.getNumeMagazin() << endl;
	cout << m3.getNrAngajati() << endl;
	cout << m3.getNrLuni() << endl;
	for (int i = 0; i < m3.getNrLuni(); i++)
	{
		cout << m3.getVenituriLunare()[i] << " ; ";
	}
	cout << endl;
	cout << m3.getSuprafataMagazin() << endl;
	cout << m3.getEsteNonStop() << endl;
	cout << m3.getTVA() << endl;
	cout << endl << endl;


	cout << m4.getOras() << endl;
	cout << m4.getNumeMagazin() << endl;
	cout << m4.getNrAngajati() << endl;
	cout << m4.getNrLuni() << endl;
	for (int i = 0; i < m4.getNrLuni(); i++)
	{
		cout << m4.getVenituriLunare()[i] << " ; ";
	}
	cout << endl;
	cout << m4.getSuprafataMagazin() << endl;
	cout << m4.getEsteNonStop() << endl;
	cout << m4.getTVA() << endl;

	//SETTERI
	cout << "--------------------------------------SETTERI------------------------" << endl << endl;
	m.setOras("Suceava");
	m.setNumeMagazin("D&M");
	m.setNrAngajati(50);
	float vector3[] = { 1000.78, 567.11,999.22,60000 };
	m.setVenituriLunare(4, vector3);
	m.setSuprafataMagazin(78.55);
	m.setEsteNonStop(0);


	cout << m.getOras() << endl;
	cout << m.getNumeMagazin() << endl;
	cout << m.getNrAngajati() << endl;
	cout << m.getNrLuni() << endl;
	for (int i = 0; i < m.getNrLuni(); i++)
	{
		cout << m.getVenituriLunare()[i] << " ; ";
	}
	cout << endl;
	cout << m.getSuprafataMagazin() << endl;
	cout << m.getEsteNonStop() << endl;
	cout << m.getTVA() << endl;
	cout << endl << endl;

	//Constructorul de copiere
	cout << "--------------------------------------Constructorul de copiere------------------------" << endl << endl;
	Magazin m5(m4);
	cout << m5.getOras() << endl;
	cout << m5.getNumeMagazin() << endl;
	cout << m5.getNrAngajati() << endl;
	cout << m5.getNrLuni() << endl;
	for (int i = 0; i < m5.getNrLuni(); i++)
	{
		cout << m5.getVenituriLunare()[i] << " ; ";
	}
	cout << endl;
	cout << m5.getSuprafataMagazin() << endl;
	cout << m5.getEsteNonStop() << endl;
	cout << m5.getTVA() << endl;
	cout << endl << endl;


	//Operator =
	cout << "--------------------------------------Operator =------------------------" << endl << endl;
	cout << "Inainte de modificare:" << endl << endl;
	cout << m.getOras() << endl;
	cout << m.getNumeMagazin() << endl;
	cout << m.getNrAngajati() << endl;
	cout << m.getNrLuni() << endl;
	for (int i = 0; i < m.getNrLuni(); i++)
	{
		cout << m.getVenituriLunare()[i] << " ; ";
	}
	cout << endl;
	cout << m.getSuprafataMagazin() << endl;
	cout << m.getEsteNonStop() << endl;
	cout << m.getTVA() << endl;
	cout << endl << endl;

	cout << m5.getOras() << endl;
	cout << m5.getNumeMagazin() << endl;
	cout << m5.getNrAngajati() << endl;
	cout << m5.getNrLuni() << endl;
	for (int i = 0; i < m5.getNrLuni(); i++)
	{
		cout << m5.getVenituriLunare()[i] << " ; ";
	}
	cout << endl;
	cout << m5.getSuprafataMagazin() << endl;
	cout << m5.getEsteNonStop() << endl;
	cout << m5.getTVA() << endl;
	cout << endl << endl;


	m = m5;
	cout << "Dupa modificare:" << endl << endl;

	cout << m.getOras() << endl;
	cout << m.getNumeMagazin() << endl;
	cout << m.getNrAngajati() << endl;
	cout << m.getNrLuni() << endl;
	for (int i = 0; i < m.getNrLuni(); i++)
	{
		cout << m.getVenituriLunare()[i] << " ; ";
	}
	cout << endl;
	cout << m.getSuprafataMagazin() << endl;
	cout << m.getEsteNonStop() << endl;
	cout << m.getTVA() << endl;
	cout << endl << endl;

	cout << m5.getOras() << endl;
	cout << m5.getNumeMagazin() << endl;
	cout << m5.getNrAngajati() << endl;
	cout << m5.getNrLuni() << endl;
	for (int i = 0; i < m5.getNrLuni(); i++)
	{
		cout << m5.getVenituriLunare()[i] << " ; ";
	}
	cout << endl;
	cout << m5.getSuprafataMagazin() << endl;
	cout << m5.getEsteNonStop() << endl;
	cout << m5.getTVA() << endl;
	cout << endl << endl;


	//METODE
	cout << "--------------------------------------METODE------------------------" << endl << endl;
	cout << "Veniturile totale obtinute de magazinul m5 sunt in valoare de:" << m5.totalVenituri() << endl;
	cout << "Veniturile medii obtinute de magazinul m5 sunt in valoare de:" << m5.venituriMedii() << endl;
	cout << "Veniturile maxime ale magazinului m5 sunt in valoare de:" << m5.maximVenituri() << endl;
	cout << "Veniturile minime ale magazinului m5 sunt in valoare de:" << m5.minimVenituri() << endl;
	cout << "TVA-ul platit de magazinul m5 in luna 2 este:" << m5.calculTVALuna(2) << endl;
	cout << "TVA-ul platit de magazinul m5 in luna 2 este:" << m5.calculTVALuna(20) << endl;
	cout << "TVA-ul platit de magazinul m5 in luna 2 este:" << m5.calculTVALuna(-2) << endl;

	m5.verificareNonStop();

	cout << endl << endl << "Metoda adauga in vector" << endl << endl;
	cout << "Obiectul m5 inainte de modificare:" << endl << endl;
	cout << m5.getOras() << endl;
	cout << m5.getNumeMagazin() << endl;
	cout << m5.getNrAngajati() << endl;
	cout << m5.getNrLuni() << endl;
	for (int i = 0; i < m5.getNrLuni(); i++)
	{
		cout << m5.getVenituriLunare()[i] << " ; ";
	}
	cout << endl;
	cout << m5.getSuprafataMagazin() << endl;
	cout << m5.getEsteNonStop() << endl;
	cout << m5.getTVA() << endl;
	cout << endl << endl;

	m5.adaugaVenit(500);

	cout << "Obiectul m5 dupa modificare:" << endl << endl;

	cout << m5.getOras() << endl;
	cout << m5.getNumeMagazin() << endl;
	cout << m5.getNrAngajati() << endl;
	cout << m5.getNrLuni() << endl;
	for (int i = 0; i < m5.getNrLuni(); i++)
	{
		cout << m5.getVenituriLunare()[i] << " ; ";
	}
	cout << endl;
	cout << m5.getSuprafataMagazin() << endl;
	cout << m5.getEsteNonStop() << endl;
	cout << m5.getTVA() << endl;
	cout << endl << endl;

	cout << endl << endl << "Metoda elimina din vector dupa pozitie" << endl << endl;
	cout << "Obiectul m5 inainte de modificare:" << endl << endl;
	cout << m5.getOras() << endl;
	cout << m5.getNumeMagazin() << endl;
	cout << m5.getNrAngajati() << endl;
	cout << m5.getNrLuni() << endl;
	for (int i = 0; i < m5.getNrLuni(); i++)
	{
		cout << m5.getVenituriLunare()[i] << " ; ";
	}
	cout << endl;
	cout << m5.getSuprafataMagazin() << endl;
	cout << m5.getEsteNonStop() << endl;
	cout << m5.getTVA() << endl;
	cout << endl << endl;

	m5.eliminaVenitDupaPozitie(1);

	cout << "Obiectul m5 dupa modificare:" << endl << endl;

	cout << m5.getOras() << endl;
	cout << m5.getNumeMagazin() << endl;
	cout << m5.getNrAngajati() << endl;
	cout << m5.getNrLuni() << endl;
	for (int i = 0; i < m5.getNrLuni(); i++)
	{
		cout << m5.getVenituriLunare()[i] << " ; ";
	}
	cout << endl;
	cout << m5.getSuprafataMagazin() << endl;
	cout << m5.getEsteNonStop() << endl;
	cout << m5.getTVA() << endl;
	cout << endl << endl;

	cout << endl << endl << "Metoda elimina din vector dupa valoare" << endl << endl;
	cout << "Obiectul m5 inainte de modificare:" << endl << endl;
	cout << m5.getOras() << endl;
	cout << m5.getNumeMagazin() << endl;
	cout << m5.getNrAngajati() << endl;
	cout << m5.getNrLuni() << endl;
	for (int i = 0; i < m5.getNrLuni(); i++)
	{
		cout << m5.getVenituriLunare()[i] << " ; ";
	}
	cout << endl;
	cout << m5.getSuprafataMagazin() << endl;
	cout << m5.getEsteNonStop() << endl;
	cout << m5.getTVA() << endl;
	cout << endl << endl;

	m5.eliminaDupaValoare(10000);

	cout << "Obiectul m5 dupa modificare:" << endl << endl;

	cout << m5.getOras() << endl;
	cout << m5.getNumeMagazin() << endl;
	cout << m5.getNrAngajati() << endl;
	cout << m5.getNrLuni() << endl;
	for (int i = 0; i < m5.getNrLuni(); i++)
	{
		cout << m5.getVenituriLunare()[i] << " ; ";
	}
	cout << endl;
	cout << m5.getSuprafataMagazin() << endl;
	cout << m5.getEsteNonStop() << endl;
	cout << m5.getTVA() << endl;
	cout << endl << endl;




	//OPERATORI
	cout << "--------------------------------------OPERATORI------------------------" << endl << endl;
	cout << m5 << endl << endl;

	//cin >> m5;

	cout << endl << endl << m5 << endl << endl;

	cout << "Venitul pentru magazinul m5 din luna 1 este:" << m5[1] << endl;
	cout << "Venitul pentru magazinul m5 din luna 1 este:" << m5[1000] << endl;
	cout << "Venitul pentru magazinul m5 din luna 1 este:" << m5[-1] << endl;

	cout << endl << m3 << endl << endl;
	cout << endl << m5 << endl << endl;
	cout << "Magazinul m3 are suprafata mai mare decat magazinul m5? 1-da 0-nu: " << (m3 > m5) << endl;
	cout << "Magazinul m3 are 90 de anagjati? 1-da 0-nu: " << (m3 == 90) << endl;
	cout << endl << endl;
	cout << m5 << endl << endl;
	m5(1, 500);
	cout << m5 << endl << endl;

	cout << "--------------Operatori de cast-----------" << endl << endl;
	cout << "Nr de luni care depasesc venitul de 500 RON pentru magazinul m5:" << (int)m5 << endl;
	cout << "Media veniturilor din primele doua luni pentru m5:" << (float)m5 << endl;
	cout << (string)m5 << endl;

	cout << endl << endl;
	cout << m5 << endl << endl;
	!m5;
	cout << m5 << endl << endl;
	cout << endl << endl;


	cout << m5 << endl << endl;
	m5 += 1000.78;
	cout << m5 << endl << endl << endl << endl << endl << endl;
	m5 -= 2;
	cout << m5 << endl << endl << endl << endl << endl << endl;

	cout << m5.getNrAngajati() << endl;
	cout << m3.getNrAngajati() << endl;
	m5 = m3++;
	cout << m5.getNrAngajati() << endl;
	cout << m3.getNrAngajati() << endl;







	//FISIERE
	cout << "--------------------------------------FISIERE------------------------" << endl << endl;

	//FISIERE TEXT
	cout << "--------------------------------------FISIERE TEXT------------------------" << endl << endl;

	
	ofstream fisier1("MagazineFisierText.txt", ios::out);

	//2.SCRIEREA OBIECTELOR IN FISIER TEXT PRIN APELUL OP <<
	fisier1 << m5;

	//3. INCHIDEREA FISIERULUI TEXT
	fisier1.close();

	//CITIREA DIN FISIERE TEXT
	
	ifstream fisier2("TEST.txt", ios::in);

	//2.CITIREA OBIECTELOR DIN FISIER TEXT PRIN APELUL OP >>
	fisier2 >> m3;

	//3. INCHIDEREA FISIERULUI TEXT
	fisier2.close();

	cout << m3 << endl << endl;



	//FISIERE BINARE
	cout << "--------------------------------------FISIERE BINARE------------------------" << endl << endl;

	
	fstream fisier3("MagazineFisierBinar.bin", ios::binary | ios::out);
	
	m5.scriereBinar(fisier3);
	fisier3.close();

	//CITIREA DIN FISIER BINAR
	fstream fisier4("MagazineFisierBinar.bin", ios::binary | ios::in);
	m3.citireBinar(fisier4);
	fisier4.close();

	cout << m5 << endl << endl;
	cout << m3 << endl << endl;
	cout << endl << endl << endl << endl << endl;



	//clasa derivata Magazin de Electrocasnice
	cout << "--------------------------------------clasa derivata Magazin de Electrocasnice------------------------" << endl << endl;
	MagazinDeElectrocasnice e;
	float venituri5[] = { 9000.9,5000,4000 };
	MagazinDeElectrocasnice e1(1, 0.02, "Bucuresti", "Flanco", 100, 3, venituri5, 105, 0.02, 0.19);

	//Getteri
	cout << e1.getLivrareLaDomiciliu() << endl;
	cout << e1.getDobandaRate() << endl;
	cout << e1.getOras() << endl;
	cout << e1.getNumeMagazin() << endl;
	cout << e1.getNrAngajati() << endl;
	cout << e1.getNrLuni() << endl;
	for (int i = 0; i < e1.getNrLuni(); i++)
	{
		cout << e1.getVenituriLunare()[i] << " ; ";
	}
	cout << endl;
	cout << e1.getSuprafataMagazin() << endl;
	cout << e1.getEsteNonStop() << endl;
	cout << e1.getTVA() << endl;
	cout << endl << endl;

	//Setteri
	e1.setLivrareLaDomiciliu(0);
	e1.setDobandaRate(0.05);
	e1.setOras("Suceava");
	e1.setNumeMagazin("Altex");
	e1.setNrAngajati(50);
	e1.setVenituriLunare(4, vector3);
	e1.setSuprafataMagazin(78.55);
	e1.setEsteNonStop(0);

	cout << e1.getLivrareLaDomiciliu() << endl;
	cout << e1.getDobandaRate() << endl;
	cout << e1.getOras() << endl;
	cout << e1.getNumeMagazin() << endl;
	cout << e1.getNrAngajati() << endl;
	cout << e1.getNrLuni() << endl;
	for (int i = 0; i < e1.getNrLuni(); i++)
	{
		cout << e1.getVenituriLunare()[i] << " ; ";
	}
	cout << endl;
	cout << e1.getSuprafataMagazin() << endl;
	cout << e1.getEsteNonStop() << endl;
	cout << e1.getTVA() << endl;
	cout << endl << endl;


	//Constructorul de copiere

	//Upcasting

	Magazin m6 = e1; //am transformat magazinul de electrocasnice e1 intr-un magazin normal prin construirea unui nou obiect, obiectul m6
	cout << m6 << endl << endl;
	cout << e1.getLivrareLaDomiciliu() << endl;
	cout << e1.getDobandaRate() << endl;
	cout << e1.getOras() << endl;
	cout << e1.getNumeMagazin() << endl;
	cout << e1.getNrAngajati() << endl;
	cout << e1.getNrLuni() << endl;
	for (int i = 0; i < e1.getNrLuni(); i++)
	{
		cout << e1.getVenituriLunare()[i] << " ; ";
	}
	cout << endl;
	cout << e1.getSuprafataMagazin() << endl;
	cout << e1.getEsteNonStop() << endl;
	cout << e1.getTVA() << endl;
	cout << endl << endl;

	//Downcasting
	MagazinDeElectrocasnice e2 = m4;
	cout << e2.getLivrareLaDomiciliu() << endl;
	cout << e2.getDobandaRate() << endl;
	cout << e2.getOras() << endl;
	cout << e2.getNumeMagazin() << endl;
	cout << e2.getNrAngajati() << endl;
	cout << e2.getNrLuni() << endl;
	for (int i = 0; i < e2.getNrLuni(); i++)
	{
		cout << e2.getVenituriLunare()[i] << " ; ";
	}
	cout << endl;
	cout << e2.getSuprafataMagazin() << endl;
	cout << e2.getEsteNonStop() << endl;
	cout << e2.getTVA() << endl;
	cout << endl << endl;

	cout << m4 << endl << endl;


	//OPERTAORUL =
	cout << "--------------------------------------OPERTAORUL =------------------------" << endl << endl;
	cout << e.getLivrareLaDomiciliu() << endl;
	cout << e.getDobandaRate() << endl;
	cout << e.getOras() << endl;
	cout << e.getNumeMagazin() << endl;
	cout << e.getNrAngajati() << endl;
	cout << e.getNrLuni() << endl;
	for (int i = 0; i < e.getNrLuni(); i++)
	{
		cout << e.getVenituriLunare()[i] << " ; ";
	}
	cout << endl;
	cout << e.getSuprafataMagazin() << endl;
	cout << e.getEsteNonStop() << endl;
	cout << e.getTVA() << endl;
	cout << endl << endl;

	cout << e2.getLivrareLaDomiciliu() << endl;
	cout << e2.getDobandaRate() << endl;
	cout << e2.getOras() << endl;
	cout << e2.getNumeMagazin() << endl;
	cout << e2.getNrAngajati() << endl;
	cout << e2.getNrLuni() << endl;
	for (int i = 0; i < e2.getNrLuni(); i++)
	{
		cout << e2.getVenituriLunare()[i] << " ; ";
	}
	cout << endl;
	cout << e2.getSuprafataMagazin() << endl;
	cout << e2.getEsteNonStop() << endl;
	cout << e2.getTVA() << endl;
	cout << endl << endl;

	cout << "DUPA MODFIICARE!!!!!!!!!!!!!!!!!!!!" << endl << endl;
	e = e2;

	cout << e.getLivrareLaDomiciliu() << endl;
	cout << e.getDobandaRate() << endl;
	cout << e.getOras() << endl;
	cout << e.getNumeMagazin() << endl;
	cout << e.getNrAngajati() << endl;
	cout << e.getNrLuni() << endl;
	for (int i = 0; i < e.getNrLuni(); i++)
	{
		cout << e.getVenituriLunare()[i] << " ; ";
	}
	cout << endl;
	cout << e.getSuprafataMagazin() << endl;
	cout << e.getEsteNonStop() << endl;
	cout << e.getTVA() << endl;
	cout << endl << endl;


	cout << "--------------------------------------METODE------------------------" << endl << endl;
	cout << "Venitul maxim pt magazinul de electrocasnice e2 este:" << e2.maximVenituri() << endl << endl;
	cout << e2.getLivrareLaDomiciliu() << endl;
	cout << e2.getDobandaRate() << endl;
	cout << e2.getOras() << endl;
	cout << e2.getNumeMagazin() << endl;
	cout << e2.getNrAngajati() << endl;
	cout << e2.getNrLuni() << endl;
	for (int i = 0; i < e2.getNrLuni(); i++)
	{
		cout << e2.getVenituriLunare()[i] << " ; ";
	}
	cout << endl;
	cout << e2.getSuprafataMagazin() << endl;
	cout << e2.getEsteNonStop() << endl;
	cout << e2.getTVA() << endl;
	cout << endl << endl;
	e2.adaugaVenit(20000);
	cout << e2.getLivrareLaDomiciliu() << endl;
	cout << e2.getDobandaRate() << endl;
	cout << e2.getOras() << endl;
	cout << e2.getNumeMagazin() << endl;
	cout << e2.getNrAngajati() << endl;
	cout << e2.getNrLuni() << endl;
	for (int i = 0; i < e2.getNrLuni(); i++)
	{
		cout << e2.getVenituriLunare()[i] << " ; ";
	}
	cout << endl;
	cout << e2.getSuprafataMagazin() << endl;
	cout << e2.getEsteNonStop() << endl;
	cout << e2.getTVA() << endl;
	cout << endl << endl;

	cout << "Dobanda pentru produsul frigider in valoare de 3000 RON este:" << e1.calculDobandaProdus(3000) << endl;
	//cout << "Dobanda pentru produsul frigider in valoare de 3000 RON este:" << m.calculDobandaProdus(3000) << endl;  nu se poate, clasa magazin nu mosteneste clasa magazin de electrocasnice, ci relatia este inversa

	cout << "--------------------------------------OPERATORI------------------------" << endl << endl;
	cout << e1.getLivrareLaDomiciliu() << endl;
	cout << e1.getDobandaRate() << endl;
	cout << e1.getOras() << endl;
	cout << e1.getNumeMagazin() << endl;
	cout << e1.getNrAngajati() << endl;
	cout << e1.getNrLuni() << endl;
	for (int i = 0; i < e1.getNrLuni(); i++)
	{
		cout << e1.getVenituriLunare()[i] << " ; ";
	}
	cout << endl;
	cout << e1.getSuprafataMagazin() << endl;
	cout << e1.getEsteNonStop() << endl;
	cout << e1.getTVA() << endl;
	cout << endl << endl;

	e1 += 100;
	cout << e1.getLivrareLaDomiciliu() << endl;
	cout << e1.getDobandaRate() << endl;
	cout << e1.getOras() << endl;
	cout << e1.getNumeMagazin() << endl;
	cout << e1.getNrAngajati() << endl;
	cout << e1.getNrLuni() << endl;
	for (int i = 0; i < e1.getNrLuni(); i++)
	{
		cout << e1.getVenituriLunare()[i] << " ; ";
	}
	cout << endl;
	cout << e1.getSuprafataMagazin() << endl;
	cout << e1.getEsteNonStop() << endl;
	cout << e1.getTVA() << endl;
	cout << endl << endl;

	cout << e1;

	//cin >> e1;

	cout << endl << endl << e1 << endl << endl;


	//FUNCTII VIRTUALE
	cout << m.returneazaClasaInCareMaAflu() << endl;
	cout << e1.returneazaClasaInCareMaAflu()<<endl;


	
	Magazin* pointerBaza; //pointer la clasa de baza
	MagazinDeElectrocasnice* pointerDerivat; //pointer la clasa derivata
	pointerDerivat = new MagazinDeElectrocasnice(e1); // pointerul la clasa deivata va contine adresa unui obiect de tipul clasei derivate
	cout << pointerDerivat << endl; //aici afisam adresa obiectului e1
	cout << *pointerDerivat << endl; //aici compilatorul acceseaza adresa de memorie a obiectului e1 si afiseaza pe ecran ceea ce a regasit la acea adresa, adica atributele lui e1 (deferentiere)
	pointerBaza = pointerDerivat; //upcasting, am transformat polinter-ul clasei derivate in pointer la clasa de baza
	
	cout << pointerBaza->returneazaClasaInCareMaAflu() << endl;
	cout << pointerDerivat->returneazaClasaInCareMaAflu() << endl;


}
