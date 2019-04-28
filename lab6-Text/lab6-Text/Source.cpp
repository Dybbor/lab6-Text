#include <iostream>
#include "..\..\Header\Text.h"
#include "..\DesignConsole.h"

using namespace std;

TTextMem  TTextLink::mem;

void main()
{
	setlocale(LC_ALL, "Russian");
	TTextLink::InitMem(20);
	ifstream ifs("test2.txt");
	ofstream ofs("NewText.txt",/* std::*/ios::trunc);
	TText t;
	t.Read((char *)("test2.txt"));
	ifs.close();
	cout << "\n\n" << endl;
	t.KeyHandler();
	t.Write((char*)("NewText.txt"));
	ofs.close();
	clrscr();
	cout << "Печать свободных до чистки" << endl;
	TTextLink::PrintFree();
	TTextLink::CleanMem(t);
	cout << "Печать свободных после чистки" << endl;
	TTextLink::PrintFree();
	system("pause");
}