#include "head.hpp"

void InterfaceOptions(vector <string>*, int);
void printInterface(vector <string>, int);

void InterfaceOptions(vector <string>*options, int Interface)
{
	switch(Interface){
	case 1:
		(*options).push_back("1. Wgraj plik wejsciowy");
		(*options).push_back("2. Generuj plik");
		(*options).push_back("3. Sortowanie: Bubble sort");
		(*options).push_back("4. Sortowanie: Quick sort");
		(*options).push_back("5. Sortowanie: Heap sort");
		(*options).push_back("6. Sortowanie: Counting sort");
		(*options).push_back("7. Sortowanie: Porownanie czasow");
		(*options).push_back("8. Wyswietl dane statystyczne");
		(*options).push_back("9. Wyswietl plik");
		(*options).push_back("10. Zapisz plik");
		(*options).push_back("11. Wygeneruj wykresy");
		(*options).push_back("12. Zamknij program");
		break;
	case 2:
		(*options).push_back("1. Porownanie czasu - rozne metody");
		(*options).push_back("2. N prob Quicksort - Zmienny Pivot");
		(*options).push_back("3. Srednia z N prob Quicksort - Zmienny Pivot");
		(*options).push_back("4. Powrot");
		break;
	case 3:
		(*options).push_back("1. Pivot - lewy element");
		(*options).push_back("2. Pivot - srodkowy element");
		(*options).push_back("3. Pivot - prawy element");
		(*options).push_back("4. Pivot - losowy element");
		(*options).push_back("5. Pivot - kazdy");
		(*options).push_back("6. Powrot");
		break;
	case 4:
		(*options).push_back("1. Wyswietl wszystko");
		(*options).push_back("2. Wyswietl 10 elementow");
		(*options).push_back("3. Powrot");
	}

}

void printInterface(vector <string> options, int select)
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	unsigned int max_length = 0;
	int swt = 2;
	char LG = 201;
	char PG = 187;
	char LD = 200;
	char PD = 188;
	char LK = 204;
	char PK = 185;
	char poz = 205;
	char pion = 186;
	for (string s : options)
	{
		if (s.length() > max_length) max_length = s.length();
	}
	if (max_length < 4)
	{
		cout << "Nadluzsza z opcji musi miec przynajmniej 4 znaki" << endl;
		return;
	}
	if (max_length % 2 == 0) swt = 1;
	cout << LG;
	for (int i = 0; i < max_length + 2; i++) cout << poz;
	cout << PG << endl << pion;
	for (int i = 0; i < (max_length - 4) / 2 + 1; i++) cout << " ";
	cout << "MENU";
	for (int i = 0; i < (max_length - 4) / 2 + swt; i++) cout << " ";
	cout << pion << endl << LK;
	for (int i = 0; i < max_length + 2; i++) cout << poz;
	cout << PK << endl;
	int x = 0;
	for (string s : options)
	{
		cout << pion;
		if (x == select) SetConsoleTextAttribute(hOut, FOREGROUND_RED);
		cout << s;
		for (int i = 0; i < (max_length - s.length()) / 2 + 1; i++) cout << " ";
		SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		if (s.length() % 2 == 0)
		{
			for (int i = 0; i < (max_length - s.length()) / 2 + swt; i++) cout << " ";
		}
		else
		{
			for (int i = 0; i < (max_length - s.length()) / 2 + abs(swt - 3); i++) cout << " ";
		}
		cout << pion << endl;
		x++;
	}
	cout << LD;
	for (int i = 0; i < max_length + 2; i++) cout << poz;
	cout << PD;
}

int InterfaceSelect(int Interface) {

	vector <string> options;
	InterfaceOptions(&options, Interface);
	int selected = 0;
	while (true)
	{
		system("cls");
		printInterface(options, selected);
		char pick;
		pick = _getch();
		if (pick == 'w' || pick == 'W' || pick == 72)
		{
			if (selected > 0) selected--;
			else selected = (options).size() - 1;
		}
		else if (pick == 's' || pick == 'S' || pick == 80)
		{
			if (selected < (options).size() - 1) selected++;
			else selected = 0;
		}
		else if (pick == 13)
		{
			system("cls");
			return selected + 1;
		}
	}
}
void cont() {
	cout << endl << "Kliknij ENTER aby kontynuowac" << endl;
	_getch();
}