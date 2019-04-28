#pragma once
#include "TTextLink.h"
#include "List_stack.h"
#include "../lab6-Text/DesignConsole.h"
#include <fstream>
#include <string>

class TText 
{

	//TTextLink *pFirst,  //Указатель на первую строчку
	//		 *pCurr;	//Указатель на текущую строчку
	TTextLink *pFirst, *pCurr;
	TStack <TTextLink*> st;	//Стек указателей 
	int LevelText;		//Уровень  отступа
public :
	TText(TTextLink *p = NULL);
	TTextLink* GetCurr();
	void GoNextLink();
	void GoDownLink();
	void GoPrevLink();
	void GoFirstLink();
	std::string GetStr();
	void SetStr(std::string str);
	void InsNextLine(std::string s);	//Вставка строки в тот же уровень
	void InsNextSection(std::string s);	//Вставка раздела в тот же уровень
	void InsDownLine(std::string s);	//Вствака строки в подуровень
	void InsDownSection(std::string s);	//Вставка раздела в подуровень
	void DelNext();
	void DelDown();
	TTextLink* ReadText(std::ifstream &ifs);
	void Read(char * fn);
	void PrintText(TTextLink *tmp);
	void Print();
	void Reset();
	bool IsEmpty();
	void GoNext();
	int MoveCursor(TTextLink *tmp);
	void KeyHandler();
};

