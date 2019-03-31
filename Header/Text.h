#pragma once
#include "TTextLink.h"
#include "List_stack.h"
#include <fstream>
class TText 
{
protected:
	TTextLink *pFirst,  //��������� �� ������ �������
			 *pCurr;	//��������� �� ������� �������
	TStack <TTextLink*> st;	//���� ���������� 
	int LevelText;		//�������  �������
public :
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

void TText::GoPrevLink() 
{
	if (!st.IsEmpty())
		pCurr = st.Pop();
}

void TText::GoFirstLink() 
{
	st.Clear();
	pCurr = pFirst;
}
std::string TText::GetStr()
{
	if (pCurr == NULL)
		return std::string("");
	else
		return std::string(pCurr->str);
}

void TText::SetStr(std::string s) 
{
	if (pCurr != NULL)
		strcpy(pCurr->str, s.c_str());
}

void TText::InsNextLine(std::string s) 
{
	if (pCurr != NULL) 
	{
 		TTextLink *tmp = new TTextLink((char*)s.c_str());
		tmp->pNext = pCurr->pNext;
		pCurr->pNext = tmp;
	}
}

void TText::InsNextSection(std::string s)
{
	if (pCurr != NULL)
	{
		TTextLink *tmp = new TTextLink((char*)s.c_str());
		tmp->pDown = pCurr->pNext;
		pCurr -> pNext = tmp;
	}
}

void TText::InsDownLine(std::string s)
{
	if (pCurr != NULL)
	{
		TTextLink *tmp = new TTextLink((char*)s.c_str());
		tmp->pNext = pCurr->pDown;
		pCurr->pDown = tmp;
	}
}

void TText::InsDownSection(std::string s)
{
	if (pCurr != NULL)
	{
		TTextLink *tmp = new TTextLink((char*)s.c_str());
		tmp->pDown = pCurr->pDown;
		pCurr->pDown = tmp;
	}
}

void TText::DelNext() 
{
	if (pCurr != NULL)
		if (pCurr->pNext!=NULL)
	{
		TTextLink *tmp = pCurr->pNext;
		pCurr->pNext = tmp->pNext;
		delete tmp;
	}
} 

void TText::DelDown()
{
	if (pCurr != NULL)
		if (pCurr->pDown != NULL)
		{
			TTextLink *tmp = pCurr->pDown;
			pCurr->pDown = tmp->pNext;
			delete tmp;
		}
}
TTextLink* TText::ReadText(std::ifstream &ifs) 
{
	TTextLink *pHead,
		*tmp;
	char buff[MaxLen];
	tmp = new TTextLink;
	pHead = tmp;
	while (!ifs.eof())
	{
		ifs.getline(buff, MaxLen, '\n');
		if (buff[0] == '}')
			break;
		else
			if (buff[0] == '{')
				tmp->pDown = ReadText(ifs);
			else
			{
				TTextLink*p= new TTextLink(buff);
				tmp->pNext = p;
				tmp = tmp->pNext;
			}
	}
	tmp = pHead->pNext;
	delete pHead;
	return tmp;
}

void TText::Read(char *fn) 
{
	std::ifstream ifs(fn);
	pFirst = ReadText(ifs);
}

void TText::PrintText(TTextLink * tmp) 
{
	if (tmp != NULL) 
	{
		for (int i = 0; i < LevelText; i++)
			std::cout << "   ";
		std::cout << tmp->str << std::endl;
		if (tmp->pDown != NULL)
		{
			LevelText++;
			PrintText(tmp->pDown);
			LevelText--;
		}
		if (tmp->pNext != NULL)
			PrintText(tmp->pNext);
		
	}
}

void TText::Print() 
{
	LevelText = 0;
	PrintText(pFirst);
}

void TText::Reset() 
{
	st.Clear();
	pCurr = pFirst;
	st.Push(pCurr);
	if (pCurr->pDown != NULL)
		st.Push(pCurr->pDown);
	if (pCurr->pNext != NULL)
		st.Push(pCurr->pNext);
}

bool TText::IsEmpty() 
{
	return st.IsEmpty();
}

void TText::GoNext() 
{
	pCurr = st.Pop();
	if (pCurr != pFirst)
	{
		if (pCurr->pDown != NULL)
			st.Push(pCurr->pDown);
		if (pCurr->pNext != NULL)
			st.Push(pCurr->pNext);
	}
}
