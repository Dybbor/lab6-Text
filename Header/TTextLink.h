#pragma once
#include <string>

const int MaxLen = 81;
class TTextLink 
{
public:
	char str[MaxLen];
	TTextLink *pNext, //Следующее звено
		*pDown;		  //Вложенное звено
	TTextLink(char*_str = NULL, TTextLink* _pNext = NULL, TTextLink* _pDown = NULL);
	/*{
		

			pNext = _pNext;
			pDown = _pDown;
			if (_str == NULL)
				str[0] = '\0';
			else
				strcpy(str, _str);

		
	}*/
};
