#include <iostream>
#include "../../Header/Text.h"
#include "../DesignConsole.h"
using namespace std;

void main()
{
	setlocale(LC_ALL, "Russian");
	ifstream ifs("test2.txt");
	TText t;
	t.Read((char *)("test2.txt"));
	ifs.close();
	cout << "\n\n" << endl;
	//t.Print();
	t.KeyHandler();
	
	system("pause");
}