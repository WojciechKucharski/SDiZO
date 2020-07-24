#include "head.hpp"

void bubble(vector<float>*base) {

	cout << endl << "Trwa sortowanie..." << endl;

	double time = bubbleA(base, 1);

	cout << "Algorytm wykonywal sie: " << time << "[s]" << endl;
	cout << endl << "Plik zostal posortowany" << endl;
	cont();
}

double bubbleA(vector<float>*base, bool save) {

	int N = (*base).size();
	float *Save = new float[N];
	float done, tmp;
	if (!save) {
		for (int i = 0; i <= N-1; i++) {
			Save[i] = (*base)[i];
		}
	}
	double start = clock();
	for (int i = 1; i <= N; i++)
	{
		done = 1;
		for (int j = 0; j < N - i ; j++)
		{
			if (((*base)[j]) > ((*base)[j + 1]))
			{
				tmp = ((*base)[j+1]);
				((*base)[j+1]) = ((*base)[j]);
				((*base)[j]) = tmp;
				done = 0;
			}
		}
		if (done == 1) break;
	}
	double stop = clock();
	if (!save) {
		for (int i = 0; i <= N - 1; i++) {
			(*base)[i] = Save[i];
		}
	}
	return (double(stop - start) / CLOCKS_PER_SEC);
}
