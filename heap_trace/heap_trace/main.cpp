#include <iostream>
#include <sstream>
#include <string>

#include "func_dependent.h"

using namespace std;

int main()
{
	string sinput;
	while (1)
	{
		cout << "input n [new] or d [delete] to operate heap" << endl;
		cout << "input ch or dh to create or destroy a heap" << endl;
		cout << "input qh to query heap" << endl;
		cin >> sinput;
		if (sinput == "n")
		{
			NewPieceOfMemory();
		}
		else if (sinput == "d")
		{
			DeletePieceOfMemory();
		}
		else if (sinput == "ch")
		{
			CreateHeap();
		}
		else if (sinput == "dh")
		{
			DestroyHeap();
		}
		else if (sinput == "qh")
		{
			QueryHeaps();
		}
		else
		{
			
		}

	}
	return 0;
}