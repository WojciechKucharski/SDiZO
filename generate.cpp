#include "head.hpp"

void generate(vector<float>*base)
{	
	float N1 = 0;
	float N2 = 0;
	float N3 = 0;

	cout << "Podaj liczbe wpisow do wygenerowania:" << endl;
	cin >> N1;
	cout << "Podaj minimalna wartosc:" << endl;
	cin >> N2;
	cout << "Podaj maksymalna wartosc:" << endl;
	cin >> N3;


	generateA(base, N1, N2, N3);
	

	cout << endl << "Dane zostaly wprowadzony do pamieci" << endl;
	cont();
}

void generateA(vector<float>*base, float N1, float N2, float N3) {

	srand(time(NULL));
	(*base).clear();
	for (int i = 0; i < N1; i++) {
		(*base).push_back(N2 + (((float)rand()) / (float)RAND_MAX) * (N3 - N2));
		//(*base).push_back(rand()%((int)N3) - (int)N2);
	}

}

void generateA2(vector<float>*base, int N1) {

	srand(time(NULL));
	(*base).clear();
	for (int i = 0; i < N1; i++) {
		//(*base).push_back(N2 + (((float)rand()) / (float)RAND_MAX) * (N3 - N2));
		(*base).push_back(rand() % INT_MAX);
		//(*base).push_back(INT_MAX-i);
	}

}