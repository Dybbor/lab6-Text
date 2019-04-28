#include <iostream>
#include "../../Header/Text.h"

using namespace std;

TTextMem  TTextLink::mem;

void main()
{
	setlocale(LC_ALL, "Russian");
	TTextLink::InitMem(30);
	ifstream ifs("test2.txt");
	TText t;
	t.Read((char *)("test2.txt"));
	ifs.close();
	cout << "\n\n" << endl;
	//t.Print();
	t.KeyHandler();
	
	system("pause");
}