#include "head.hpp"

void choice(vector<float>*, int);
void bvsqs(vector<float>*);
void nqs(vector<float>*);
void nqsa(vector<float>*);

void analyze(vector<float>*base) {
	int Select;
	do{
		Select = InterfaceSelect(2);
		choice(base, Select);
	} while (Select != 4);
}

void choice(vector<float>*base, int Select) {
	switch (Select){
	case 1:
		bvsqs(base);
		break;
	case 2:
		nqs(base);
		break;
	case 3:
		nqsa(base);
		break;
	default:
		break;
	}
}

void bvsqs(vector<float>*base) {
	cout << "Jesli wczytano dane typu float, Counting sort ignoruje wartosci po przecinku \n\n";
	cout << "Quick sort posortowal w: " << qsortA(base, 0, (*base).size() - 1, 0, 0) << "[s]" << endl;
	cout << "Heap sort posortowal w: " << hsortA(base, 0) << "[s]" << endl;
	cout << "Counting sort posortowal w: " << csortA(base, 0) << "[s]" << endl;
	cout << "Bubble sort posortowal w: " << bubbleA(base, 0) << "[s]" << endl;

	cont();
}
void nqs(vector<float>*base) {
	cout << "Ile razy wykonac QSort?" << endl;
	int k;
	cin >> k;
	for (int i = 1; i <= k; i++) {
		cout << i << endl;
		cout << "Pivot po lewej: QSort posortowal w: " << qsortA(base, 0, (*base).size() - 1, 0, 0) << "[s]" << endl;
		cout << "Pivot w srodku: QSort posortowal w: " << qsortA(base, 0, (*base).size() - 1, 0, 1) << "[s]" << endl;
		cout << "Pivot po prawej: QSort posortowal w: " << qsortA(base, 0, (*base).size() - 1, 0, 2) << "[s]" << endl;
		cout << "Pivot dobierany losowo: QSort posortowal w: " << qsortA(base, 3, (*base).size() - 1, 0, 3) << "[s]" << endl;
	}
	cont();
}
void nqsa(vector<float>*base){
	cout << "Ile razy wykonac QSort?" << endl;
	double k;
	cin >> k;
	double L[4] = { 0,0,0,0 };
	for (int i = 1; i <= k; i++) {
		L[0] += qsortA(base, 0, (*base).size() - 1, 0, 0) / k;
		L[1] += qsortA(base, 0, (*base).size() - 1, 0, 1) / k;
		L[2] += qsortA(base, 0, (*base).size() - 1, 0, 2) / k;
		L[3] += qsortA(base, 3, (*base).size() - 1, 0, 3) / k;
	}
	cout << "Pivot po lewej: QSort posortowal sredio w: " << L[0] << "[s]" << endl;
	cout << "Pivot w srodku: QSort posortowal sredio w: " << L[1] << "[s]" << endl;
	cout << "Pivot po prawej: QSort posortowal sredio w: " << L[2] << "[s]" << endl;
	cout << "Pivot dobierany losowo: QSort posortowal sredio w: " << L[3] << "[s]" << endl;
	cont();
}