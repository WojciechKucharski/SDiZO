#include "head.hpp"

void write(vector<float>*base){
	cout << endl << "Podaj nazwe pliku (wraz z rozszerzeniem):" << endl;
	string filename = "dane.csv";


	cin >> filename;
	char *NP = new char[filename.size() + 1];
	strcpy(NP, filename.c_str());
	ofstream plik(NP, ios::out | ios::trunc);


	if (!plik)
	{
		cout << endl << "Utworzono nowy plik" << endl;
	}


	plik << "# Plik z danymi SDiZO grupa TP 11 15" << endl;
	plik << "[SDIZO]" << endl;
	plik << "READ_RECORDS = " << (*base).size() <<" # Liczba rekordów do wczytania" << endl;
	plik<< "READ_AS=float # Typ danych do wczytania - float/int"<< endl;
	plik<<"[DATA]" << endl;


	for (int i = 0; i<(*base).size(); i++)
	{
		plik << ((*base)[i]) << endl;
	}
	plik.close();

	cont();
}

void writeplot(vector<float>*base, string filename) {
	char *NP = new char[filename.size() + 1];
	strcpy(NP, filename.c_str());
	ofstream plik(NP, ios::out | ios::trunc);
	int j = 0;
	plik << "L-Rekordow, BubbleSort, CountSort, HeapSort, QuickSortLeftPivot, QuickSortMiddlePivot, QuickSortRightPivot, QuickSortRandomPivot" << endl;
	for (int i = 0; i < (*base).size(); i++)
	{
		j = 0;
		for (j = 0; j < 7; j++) {
			plik << ((*base)[i]) << ", ";
			i++;
		}
		plik << ((*base)[i]) << endl;
	}
	plik.close();
}