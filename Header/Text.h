#pragma once
#include "TTextLink.h"
#include "List_stack.h"
class TText 
{
protected:
	TTextLink *pFirst,  //��������� �� ������ �������
			 *pCurr;	//��������� �� ������� �������
	TStack <TTextLink*> st;	//���� ���������� 
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