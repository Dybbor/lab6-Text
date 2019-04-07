#include <iostream>
#include "../../Header/Text.h"
#include "..\DesignConsole.h"
using namespace std;

void main()
{
	ifstream ifs("text.txt");
	TText t;
	t.Read((char *)("text.txt"));
	ifs.close();
	t.Print();
	t.KeyHandler();
}