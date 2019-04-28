#pragma once
#include <string>

class TTextLink;
class TText;

struct TTextMem {
	TTextLink *pFirst, *pLast, *pFree;
};

const int MaxLen = 81;

class TTextLink 
{
public:
	static TTextMem mem;
	char str[MaxLen];
	TTextLink *pNext, //Следующее звено
		*pDown;		  //Вложенное звено
	TTextLink(char*_str = NULL, TTextLink* _pNext = NULL, TTextLink* _pDown = NULL);
	void* operator new(size_t s);
	void operator delete(void* p);
	static void InitMem(int n);
	static void CleanMem(TText &txt);
};
