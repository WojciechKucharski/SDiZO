#include "head.hpp"

double plot2(vector <float>*, int);
int plot(vector <float>*base) {
	vector <float> plotbase;
	cout << "Zostana stworzone wykresy dla wszystkich algorytmow" << endl;
	cout << "OY: Czas sortowania, OX: Liczba rekordow" << endl;
	int N[5];
	string filename;
	///////////////////////////////////////////////////////////////////////////////////////////////////////////
	cout << endl << "Pominac BUBBLE? [1:TAK,0:NIE]" << endl;
	cout << endl << "(Bubble trwa bardzo dlugo, lepiej zrobic dla niego osobny plik)" << endl;
	cin >> N[0];
	cout << endl << "Podaj poczatek OX [poczatek wykresu]" << endl;
	cin >> N[1];
	cout << endl << "Podaj koniec OX [koniec wkresu]" << endl;
	cin >> N[2];
	cout << endl << "Podaj liczbe probek OX [liczba punktow na wykrsie]" << endl;
	cin >> N[3];
	cout << endl << "Ile wykonac eksperymentow na probke \n[ile razy wykonac eksperyment dla danej liczby rekordow,\nwynik zostanie usredniony]" << endl;
	cin >> N[4];
	cout << endl << "Podaj nazwe pliku z rozszerzeniem" << endl;
	cin >> filename;
	if (N[1] < 1) N[1] = 1;
	if (N[2] <= N[1]) N[2] = N[1] + 5;
	if (N[3] < 3) N[3] = 3;
	///////////////////////////////////////////////////////////////////////////////////////////////////////////
	int dx = (N[2] - N[1]) / N[3];
	int T = 0;
	double sample[7] = { 0,0,0,0,0,0,0 };
	for (int i = 0; i < N[3]; i++) {
		T = N[1] + i * dx;
		
		plotbase.push_back(T);
		for (int j = 0; j < 7; j++) {
			sample[j] = 0;
			if (j != 0) {
				for (int k = 0; k < N[4]; k++) {
					generateA2(base, T);
					sample[j] += plot2(base, j);
				}
				sample[j] = sample[j] / N[4];
			}
			else {
				if (!N[0]) {
					generateA2(base, T);
					sample[j] += plot2(base, j);
				}
			}
			plotbase.push_back(sample[j]);
		}
	}
	writeplot(&plotbase, filename);
	///////////////////////////////////////////////////////////////////////////////////////////////////////////
}
double plot2(vector <float>*base, int sort) {
	if (sort < 0) sort = 0;
	if (sort > 6) sort = 6;
	switch (sort) {
	case 2:
		return hsortA(base, 0);
		break;
	case 1:
		return csortA(base, 0);
		break;
	case 0:
		return bubbleA(base, 0);
		break;
	default:
		return qsortA(base, 0, 0, 0, sort-3);
		break;
	}
}