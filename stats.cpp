#include "head.hpp"


void stats(vector<float>*base)
{
	cout << "Jesli plik nie zostal wczesniej posortowany,\nwartosc mediany bedzie przeklamana. \n Kliknij ENTER aby kontynuowac.";
	_getch();

	int N = (*base).size();
	int i = 0;
	float SUM = 0;
	float av = 0;
	long float avgeo = 1;
	float avhar = 0;
	float avkwa = 0;
	float med = 0;
	float var = 0;
	float max = 0, min = 999999;

	for (i = 0; i < N; i++)
	{
		av += (*base)[i];
		avgeo =avgeo * (*base)[i];
		avhar += 1/(*base)[i];
		avkwa += pow((*base)[i], 2.0);
		if ((*base)[i] > max) max = (*base)[i];
		if ((*base)[i] < min) min = (*base)[i];
	}
	av = av / N;
	float iN = pow(N, -1.0);
	avgeo = pow(avgeo,iN);
	avhar = N / avhar;
	avkwa = pow(avkwa / N, 0.5);
	for (i = 0; i < N; i++)
	{
		var += ((*base)[i] - av)*((*base)[i] - av);
	}
	var = var / N;
	if (N % 2 == 1)
	{
		med = (*base)[(i - 1) / 2];
	}
	else
	{
		med = ((*base)[i/2] + (*base)[i/2-1]) / 2;
	}


	cout << endl << "Liczba wpisow: " << N;
	cout << endl << "Najmniejsza wartosc: " << min;
	cout << endl << "Najwieksza wartosc: " << max;
	cout << endl << "Mediana: " << med;
	cout << endl << "Srednia arytmetyczna: " << av;
	cout << endl << "Srednia harmoniczna: " << avhar;
	cout << endl << "Srednia kwadratowa: " << avkwa;
	cout << endl << "Wariancja: " << var;
	cout << endl << "Odchylenie standardowe: " << pow(var,0.5);



	cont();
}