#include "head.hpp"


void csortAA(vector<float>*,int,int,int,int, int unique[]);

void csort(vector<float>*base) {

	cout << endl << "Plik zostal posortowany w: "<<csortA(base,1)<<" s\n" << endl;
	cont();
}


double csortA(vector<float>*base, bool save) {
	int N = (*base).size();
	float min = FLT_MAX, max = -FLT_MAX;
	for (int i = 0; i < N; i++) {
		if ((*base)[i] > max) max = (*base)[i];
		if ((*base)[i] < min) min = (*base)[i];
	}
	float *Save = new float[N];
	if (!save) {
		for (int i = 0; i <= N - 1; i++) {
			Save[i] = (*base)[i];
		}
	}
	int S = (int)max - (int)min + 1;
	int * unique = new int[S];
	for (int i = 0; i < S; i++) unique[i] = 0;
	double start = clock();

	csortAA(base, (int)min, (int)max, S, N, unique);

	double stop = clock();
	if (!save) {
		for (int i = 0; i <= N - 1; i++) {
			(*base)[i] = Save[i];
		}
	}
	return (double(stop - start) / CLOCKS_PER_SEC);
	
}
void csortAA(vector<float>*base, int min, int max, int S, int N,int unique[]) {

	float *out = new float[N];
	for (int i = 0; i < N; i++) {
		++unique[(int)(*base)[i] - min];
	}
	for (int i = 1; i < S; i++) {
		unique[i] = unique[i] + unique[i - 1];
	}
	for (int i = 0; i < N; i++) {
			out[--unique[(int)(*base)[i] - min]] = (*base)[i];
	}
	for (int i = 0; i < N; i++) { (*base)[i] = out[i]; }

}
