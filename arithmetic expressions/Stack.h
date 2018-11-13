#pragma once
#include "pch.h"
#include <iostream>
using namespace std;

template <class T>
class TStack 
{
	T * pMem; // указатель на массив элементов
	int MemSize; // размер памяти для СД
	int Hi; // индекс вершины стека
public:
		TStack(int Size = 25);//конструктор
		~TStack(); //деструктор
		int IsEmpty(void) const; // контроль пустоты
		int IsFull(void) const; // контроль переполнения
		void Put(const T &Val);// добавить значение
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