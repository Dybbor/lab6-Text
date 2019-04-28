#include "..\Header\TTextLink.h"
#include "..\Header\Text.h"
TTextLink::TTextLink(char*_str, TTextLink* _pNext, TTextLink* _pDown)
{


	pNext = _pNext;
	pDown = _pDown;
	if (_str == NULL)
		str[0] = '\0';
	else
		strcpy(str, _str);
}

void* TTextLink::operator new(size_t s) 
{
	TTextLink *tmp = mem.pFree;
	if (mem.pFree != NULL)
	{
		mem.pFree = mem.pFree->pNext;
		return tmp;
	}
	else 
		return NULL;
}
void TTextLink::operator delete(void* p) 
{
	TTextLink * tmp = (TTextLink*)p;
	tmp->pNext = mem.pFree;
	mem.pFree = tmp;
}
void TTextLink::InitMem(int n) 
{
	mem.pFirst = (TTextLink*) new char[sizeof(TTextLink)* n];
	TTextLink *tmp = mem.pFirst;
	mem.pFree = mem.pFirst;
	mem.pLast = mem.pFirst + (n - 1);
	for (int i = 0; i < n - 1; i++) 
	{
		tmp->pNext = tmp + 1;
		tmp->str[0] = '\0';
		tmp++;
	}
	mem.pLast->pNext = NULL;
	mem.pLast->str[0] = '\0';
}

void TTextLink::CleanMem(TText &txt) 
{
	TTextLink* tmp = mem.pFree;
	while (tmp!=NULL)
	{
		strcat(tmp->str, "&"); ///strcpy!!!!
		tmp = tmp->pNext;
	}
	for (txt.Reset(); !txt.IsEmpty(); txt.GoNext()) 
		strcat(txt.GetCurr()->str, "&");
	tmp = mem.pFree;
	while (tmp <= mem.pLast) 
	{
		if (strstr(tmp->str, "&") != NULL)
		{
			int len = strlen(tmp->str);
			tmp->str[len - 1] = '\0';
		}
		else
			delete tmp;
		tmp++;
	}
}

void TTextLink::PrintFree() {
	TTextLink *tmp = mem.pFree;
	while (tmp != NULL) {
		if (strlen(tmp->str) == 0)
			std::cout <<"Empty" << std::endl;
		else
			std::cout << tmp->str << std::endl;
		tmp = tmp->pNext;
	}
}