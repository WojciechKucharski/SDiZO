#include "head.hpp"


void hsortAA(vector<float>*);
void vali(vector<float>*, int, int);

void hsort(vector<float>*base) {

	cout << endl << "Plik zostal posortowany w: "<<hsortA(base,1)<<" s\n" << endl;
	cont();
}


double hsortA(vector<float>*base, bool save) {
	int N = (*base).size();
	float *Save = new float[N];
	if (!save) {
		for (int i = 0; i <= N - 1; i++) {
			Save[i] = (*base)[i];
		}
	}
	double start = clock();

	hsortAA(base);

	double stop = clock();
	if (!save) {
		for (int i = 0; i <= N - 1; i++) {
			(*base)[i] = Save[i];
		}
	}
	return (double(stop - start) / CLOCKS_PER_SEC);
	
}
void hsortAA(vector<float>*base) {
	int N = (*base).size();
	for (int i = N / 2 - 1; i >= 0; i--) {
		vali(base, N, i);
	}
	for (int i = N - 1; i > 0; i--) {
		float tmp = (*base)[0];
		(*base)[0] = (*base)[i];
		(*base)[i] = tmp;
		vali(base, --N, 0);
	}
}
void vali(vector<float>*base, int size, int parent){
	int v[3];
	v[0] = parent;
	v[1] = parent * 2 + 1;
	v[2] = v[1] + 1;
	for (int i = 1; i < 3; i++) {
		if (v[i]<size && (*base)[v[i]]>(*base)[v[0]]) v[0] = v[i];
	}
	if (v[0] != parent) {
		float tmp = (*base)[v[0]];
		(*base)[v[0]] = (*base)[parent];
		(*base)[parent] = tmp;
		vali(base, size, v[0]);
	}
}