#pragma once
#include "TTextLink.h"
#include "List_stack.h"
#include <fstream>
class TText 
{
protected:
	TTextLink *pFirst,  //Указатель на первую строчку
			 *pCurr;	//Указатель на текущую строчку
	TStack <TTextLink*> st;	//Стек указателей 
	int LevelText;		//Уровень  отступа
public :
	TText(TTextLink *p = NULL);
	void GoNextLink();
	void GoDownLink();
	void GoPrevLink();
	void GoFirstLink();
	std::string GetStr();
	void SetStr(std::string str);
	void InsNextLine(std::string s);
	void InsNextSection(std::string s);
	void InsDownLine(std::string s);
	void InsDownSection(std::string s);
	void DelNext();
	void DelDown();
	TTextLink* ReadText(std::ifstream &ifs);
	void Read(char * fn);
	void PrintText(TTextLink *tmp);
	void Print();
	void Reset();
	bool IsEmpty();
	void GoNext();
};

