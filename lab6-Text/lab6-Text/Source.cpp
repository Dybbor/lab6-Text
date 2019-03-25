#include <iostream>
#include "../../Header/Text.h"
using namespace std;

void main() 
{
	ifstream ifs("text.txt");
	TText t;
	t.Read((char *) ("text.txt"));
	t.Print();
	system("pause");
}