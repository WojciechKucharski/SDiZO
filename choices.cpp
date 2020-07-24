#include "head.hpp"

int exist(vector <float>*);
void todo();

void choices(int Select,vector <float>*base)
{
	switch (Select)
	{
	case 1:
		read(base);
		break;
	case 2:
		generate(base);
		break;
	case 3:
		if (exist(base)) bubble(base);
		break;	
	case 4:	
		if (exist(base)) qsort(base);
		break;
	case 5:
		if (exist(base)) hsort(base);
		break;	
	case 6:
		if (exist(base)) csort(base);
		break;	
	case 7:
		if (exist(base)) analyze(base);
		break;
	case 8:
		if (exist(base)) stats(base);
		break;
	case 9:
		if (exist(base)) show(base);
		break;
	case 10:
		if (exist(base)) write(base);
		break;
	case 11:
		plot(base);
	default:
		break;
	}
}

int exist(vector <float>*base) {

	if ((*base).size() == 0) {
		cout << "Zaden plik nie zostal wczytany.";
		cont();
		return 0;
	}
	return 1;
}

void todo() {
	cout << endl << "Ta opcja nie jest dostepna" << endl;
	cont();
}