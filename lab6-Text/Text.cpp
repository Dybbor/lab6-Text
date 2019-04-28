#include "..\Header\Text.h"
#include <conio.h>

TText::TText(TTextLink *p)
{
	if (p != NULL)
		pFirst = p;
	else 
		pFirst = new TTextLink();
	pCurr = pFirst;
	LevelText = 0;
}

TTextLink* TText::GetCurr() {
	return pCurr;
}

void TText::GoNextLink()
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
		pCurr->pNext = tmp;
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
		if (pCurr->pNext != NULL)
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
				TTextLink*p = new TTextLink(buff);
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
		std::cout << " ";
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

int TText::MoveCursor(TTextLink *tmp) 
{
	int count = 1;
	if (tmp->pDown != NULL)
		count += MoveCursor(tmp->pDown);
	if (tmp->pNext != NULL)
		count += MoveCursor(tmp->pNext);
	return count;
}
void TText::KeyHandler()
{
	pCurr = pFirst;
	int key = 0;
	std::string str;
	int x = 0, y = 4;
	gotoxy(x, y);
	Print();
	while (key!=79)
	{
		if (key == 48 || key == 49 || key == 50 || key == 51 || key == 52 || key==0) {
			gotoxy(0, 0);
			clreol();
			std::cout << "Навигация по звеньям осуществляется с помощью стрелок" << std::endl;
			gotoxy(0, 1);
			clreol();
			std::cout << "Insert -  вставка звена" << std::endl;
			gotoxy(0, 2);
			std::cout << "Delete - удаление звена" << std::endl;
			gotoxy(0, 3);
			clreol();
		}
		gotoxy(x, y);
		key = _getch();
		
		switch (key)
		{
		case 80: 		//Dowm
			if (pCurr->pNext != NULL) 
			{
				st.Push(pCurr); 
				if (pCurr->pDown != NULL)
					y += MoveCursor(pCurr->pDown) + 1;
				else
					y++;
				pCurr = pCurr->pNext;
			}
			gotoxy(x, y);
			break;
		case 77:  //Right	
			if (pCurr->pDown != NULL)
			{
				st.Push(pCurr);
				pCurr = pCurr->pDown;
				x += 3;;
				y++;
			}
			gotoxy(x, y);
			break;
		case 72: //Up
			if (pCurr != NULL && (!st.IsEmpty()))
			{
				if (st.Top()->pNext == pCurr)
				{
					if (st.Top()->pDown != NULL)
						y -= MoveCursor(st.Top()->pDown) + 1;
					else
						y--;
					pCurr = st.Pop();
				}
				else 
					if (st.Top()->pDown == pCurr)
					{
						x -= 3;
						y--;
						pCurr = st.Pop();
	
					}
					gotoxy(x, y);
			}
			break;
		case 82: //Insert
			while (key!=48 && key != 49 && key != 50 && key!=51 && key!=52)
			{
				gotoxy(0, 0);
				clreol();
				std::cout << "1 - вставка строку в тот же уровень   2 - вставка раздела в тот же уровень" << std::endl;
				gotoxy(0, 1);
				clreol();
				std::cout << "3 - вставка строки в подуровень       4 - вставка раздела в подуровень  " << std::endl;
				gotoxy(0, 2);
				clreol();
				std::cout << "0 - отмена" << std::endl;
				gotoxy(x, y);
				key = _getch();
				switch (key)
				{
				case 48:
					break;
				case 49: // 1
					clrscr();
					std::cout << "Введите название звена" << std::endl;
					std::cin >> str;
					InsNextLine(str);
				/*	gotoxy(0, 4);
					Print();*/
					break;
				case 50: // 2
					clrscr();
					std::cout << "Введите название звена" << std::endl;
					std::cin >> str;
					InsNextSection(str);
					/*gotoxy(0, 4);
					Print();*/
					break;
				case 51: // 3
					clrscr();
					std::cout << "Введите название звена" << std::endl;
					std::cin >> str;
					InsDownLine(str);
					/*gotoxy(0, 4);
					Print();*/
					break;
				case 52: // 4
					clrscr();
					std::cout << "Введите название звена" << std::endl;
					std::cin >> str;
					InsDownSection(str);
					/*gotoxy(0, 4);
					Print();*/
					break;
				}
				gotoxy(0, 4);
				Print();
			}
			break;
		case 83: //delete
			while (key != 48 && key != 49 && key != 50)
			{
				gotoxy(0, 0);
				clreol();
				std::cout << "1 - Удалить следующюю строчку" << std::endl;
				gotoxy(0, 1);
				clreol();
				std::cout << "2 - Удалить вложенную строчку" << std::endl;
				gotoxy(0, 2);
				clreol();
				std::cout << "0 - Отмена" << std::endl;
				gotoxy(x, y);
				key = _getch();
				switch (key)
				{
				case 48:
					break;
				case 49:
					DelNext();
					break;
				case 50:
					DelDown();
					break;

				}
			}
			if (key != 48)
			{
				clrscr();
				gotoxy(0, 4);
				Print();
			}
			break;
		
		}
	}
}