#include "head.hpp"


int read(vector <float>*base)
{
	cout << endl << "Podaj nazwe pliku (wraz z rozszerzeniem):" << endl;
	string filename="dane.csv";


	cin >> filename;
	if (filename.size() < 4) filename = "dane.csv";
	readA(base, filename);


	cout << endl << "Plik zostal wprowadzony do pamieci" << endl;
	cont();

	return 1;
}

int readA(vector <float>*base, string filename)
{
	bool I = 0;
	char *NP = new char[filename.size() + 1];
	strcpy(NP, filename.c_str());
	ifstream plik(NP, ios::in);
	int j = 0;
	if (!plik)
	{
		cout << endl << "Plik nie znaleziony" << endl;
		return 1;
	}
	(*base).clear();
	do
	{
		
		string tmp;
		getline(plik, tmp);
		if (j == 3) {
			if (tmp[8] == 'i') I = 1;
		}
		if (j > 4) {
			if(I) (*base).push_back((int)(float)atof(tmp.c_str()));
			else (*base).push_back((float)atof(tmp.c_str()));
		}
		j++;
	} while (!plik.eof());
	plik.close();
}
