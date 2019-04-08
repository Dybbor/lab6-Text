#include <iostream>
#include "../../Header/Text.h"
#include "..\DesignConsole.h"
using namespace std;

void main()
{
	ifstream ifs("test2.txt");
	TText t;
	t.Read((char *)("test2.txt"));
	ifs.close();
	t.Print();
	t.KeyHandler();
	system("pause");
}