#pragma once
#include "pch.h"
#include <iostream>
using namespace std;

template <class T>
class TStack 
{
	T * pMem; // ��������� �� ������ ���������
	int MemSize; // ������ ������ ��� ��
	int Hi; // ������ ������� �����
public:
		TStack(int Size = 25);//�����������
		~TStack(); //����������
		int IsEmpty(void) const; // �������� �������
		int IsFull(void) const; // �������� ������������
		void Put(const T &Val);// �������� ��������
		T Get(void); 
};

template <class T>
TStack<T>::TStack(int Size)
{
	MemSize = Size;
	pMem = new T[Size];
	Hi = -1;
}

template <class T>
TStack<T>:: ~TStack()
{
	delete[] pMem;
}

template <class T>
int TStack<T>::IsEmpty(void) const
{
	return -1==Hi;
}

template <class T>
int TStack<T>::IsFull(void) const
{
	return Hi + 1 == MemSize;
}

template <class T>
void TStack<T>::Put (const T &Val)
{
	Hi++;
	pMem[Hi] = Val;
}

template <class T>
T TStack<T>::Get()
{
	Hi--;
	return pMem[Hi + 1];
}