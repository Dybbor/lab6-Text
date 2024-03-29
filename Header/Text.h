#pragma once
#include "TTextLink.h"
#include "List_stack.h"
#include "../lab6-Text/DesignConsole.h"
#include <fstream>
#include <string>

class TText 
{

	//TTextLink *pFirst,  //��������� �� ������ �������
	//		 *pCurr;	//��������� �� ������� �������
	TTextLink *pFirst, *pCurr;
	TStack <TTextLink*> st;	//���� ���������� 
	int LevelText;		//�������  �������
public :
	TText(TTextLink *p = NULL);
	TTextLink* GetCurr();
	void GoNextLink();
	void GoDownLink();
	void GoPrevLink();
	void GoFirstLink();
	std::string GetStr();
	void SetStr(std::string str);
	void InsNextLine(std::string s);	//������� ������ � ��� �� �������
	void InsNextSection(std::string s);	//������� ������� � ��� �� �������
	void InsDownLine(std::string s);	//������� ������ � ����������
	void InsDownSection(std::string s);	//������� ������� � ����������
	void DelNext();
	void DelDown();
	TTextLink* ReadText(std::ifstream &ifs);
	void Read(char * fn);
	void WriteInFile(TTextLink *tmp, std::ofstream &ofs);
	void Write(char *fn);
	void PrintText(TTextLink *tmp);
	void Print();
	void Reset();
	bool IsEmpty();
	void GoNext();
	int MoveCursor(TTextLink *tmp);
	void KeyHandler();
};

