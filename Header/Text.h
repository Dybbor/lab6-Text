#pragma once
#include "TTextLink.h"
#include "List_stack.h"
class TText 
{
protected:
	TTextLink *pFirst,  //Указатель на первую строчку
			 *pCurr;	//Указатель на текущую строчку
	TStack <TTextLink*> st;	//Стек указателей 
public :
	void GoNextLink();
	void GoDownLink();
};

void TText :: GoNextLink() 
{
	if (pCurr != NULL)
		if (pCurr->pNext != NULL)
		{
			st.Push(pCurr);
			pCurr = pCurr->pNext;
		}
} 
void TText::GoDownLink()
{
	if (pCurr != NULL)
		if (pCurr->pDown != NULL)
		{
			st.Push(pCurr);
			pCurr = pCurr->pDown;
		}
}