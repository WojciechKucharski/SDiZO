#include "head.hpp"

void qsortAA(vector<float>*, int, int,int);

void qsort(vector<float>*base) {

	int N = (*base).size();

	int wyb = InterfaceSelect(3);


	if (wyb == 1){ 
		cout << "Pivot po lewej: QSort posortowal w: " << qsortA(base, 0, (*base).size() - 1, 1, 0) << "[s]" << endl; 
	}
	else if (wyb == 2){ 
		cout << "Pivot w srodku: QSort posortowal w: " << qsortA(base, 0, (*base).size() - 1, 1, 1) << "[s]" << endl; 
	}
	else if (wyb == 3){ 
		cout << "Pivot po prawej: QSort posortowal w: " << qsortA(base, 0, (*base).size() - 1, 1, 2) << "[s]" << endl; 
	}
	else if (wyb == 4){ 
		cout << "Pivot dobierany losowo: QSort posortowal w: " << qsortA(base, 0, (*base).size() - 1, 1, 3) << "[s]" << endl; 
	}
	else if (wyb == 5) {
		cout << endl << "Trwa sortowanie..." << endl;
		cout << "Pivot po lewej: QSort posortowal w: " << qsortA(base, 0, (*base).size() - 1, 0, 0) << "[s]" << endl;
		cout << "Pivot w srodku: QSort posortowal w: " << qsortA(base, 0, (*base).size() - 1, 0, 1) << "[s]" << endl;
		cout << "Pivot po prawej: QSort posortowal w: " << qsortA(base, 0, (*base).size() - 1, 0, 2) << "[s]" << endl;
		cout << "Pivot dobierany losowo: QSort posortowal w: " << qsortA(base, 0, (*base).size() - 1, 1, 3) << "[s]" << endl;
	}
	else { 
		wyb = 0; 
	}

	if (wyb == 0) {
		cout << endl << "Plik zostal posortowany" << endl;
		cont();
	}
	_getch();
}


double qsortA(vector<float>*base, int A, int B, bool save,int I) {
	
	if (B <= 0) B = (*base).size() - 1;

	float *Save=new float[B];
	if (!save) {
		for (int i = 0; i <= B - 1; i++) {
			Save[i] = (*base)[i];
		}
	}
	double start = clock();
	qsortAA(base, A, B, I);
	double stop = clock();
	if (!save) {
		for (int i = 0; i <= B - 1; i++) {
			(*base)[i]=Save[i];
		}
	}
	return (double(stop - start) / CLOCKS_PER_SEC);

}


void qsortAA(vector<float>*base, int A, int B,int I) {

	int i = A, j = B;
	if(i>=j){}
	else {
		float pivot;
		if(I==0) pivot = (*base)[i];
		if(I==1) pivot = (*base)[(i+j)/2];
		if(I==2) pivot = (*base)[j];
		if(I==3) pivot = (*base)[rand()%(j+1-i)+i];
		do {
			while ((*base)[i] < pivot) {
				i++; 
			}
			while ((*base)[j] > pivot) { 
				j--; 
			}

			if (i <= j) {
				float tmp;
				tmp = (*base)[i];
				(*base)[i] = (*base)[j];
				(*base)[j] = tmp;
				i++;
				j--;
			}
		} while (i <= j);

		if (A < j) qsortAA(base, A, j, I);
		if (i < B) qsortAA(base, i, B, I);
	}

}