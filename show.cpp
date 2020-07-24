#include "head.hpp"

void show(vector<float>*base) 
{
		int sel = InterfaceSelect(4);
		int A, N = (*base).size();
		if (sel != 3) {

			if (sel == 1) A = 1;
			else A = N / 9;
			for (int i = 0; i < N; i+=A)
			{
				cout << i + 1 << ": " << ((*base)[i]) << endl;
			}
			cont();
		}
}