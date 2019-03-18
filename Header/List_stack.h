#pragma once
#include <iostream>
template <class T>
struct TLink 
{
	T val;			// ��������
	TLink <T> *pNext;   // ����������� ��������� �������
};

template <class T>
class TStack
{
	TLink <T> *pFirst;	// ��������� �� ������ �����
public:
	TStack() { pFirst = NULL; } // ����������� �� ���������
	~TStack();
	void Push(T elem);	//�������� ������� � ����
	T Pop();			//���������� ������� �� �����
	T Top();			//���������� ��� ��������� �� ������� �����
	bool IsEmpty();		//�������� �� ������� �����
	int  Count();		//���������� ������� � �����
	void Clear();
};

template <class T>
TStack <T> ::~TStack()
{
	TLink <T> *tmp = pFirst;
	while (pFirst != NULL) 
	{
		pFirst = pFirst->pNext;
		delete tmp;
		tmp = pFirst;
	}
}
template <class T>
void TStack <T> ::Push(T elem) 
{
	TLink <T> *tmp =  new TLink <T>;
	tmp->val = elem;
	tmp->pNext = pFirst;
	pFirst = tmp;
}
template <class T>
T TStack <T> ::Pop() 
{	
	if (IsEmpty())
		throw "Error";
	T elem;
	TLink <T> *tmp=pFirst;
	pFirst = pFirst->pNext;
	elem = tmp->val;
	delete tmp;
	return elem;

}
 template <class T>
 T TStack <T>::Top() 
 {
	 if (IsEmpty())
		 throw "Error";
	 return pFirst->val;
 }

 template <class T>
 bool TStack <T>::IsEmpty() 
 {
	 return (pFirst==NULL);
 }

 template <class T>
 int TStack <T> ::Count() 
 {
	 int count = 0;
	 if (IsEmpty())
		 return count;
	 else
	 {
		 TLink <T> * tmp = pFirst;
		 while (tmp->pNext != NULL)
		 {
			 tmp = tmp->pNext;
			 count++;
		 }
		 return count;
	 }
 }

 template <class T>
 void TStack <T>  ::Clear() 
 {
	 TLink <T> *tmp = pFirst;
	 while (pFirst != NULL)
	 {
		 pFirst = pFirst->pNext;
		 delete tmp;
		 tmp = pFirst;
	 }
	 pFirst = NULL;
 }
