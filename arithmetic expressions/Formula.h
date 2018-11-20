#pragma once
#include "pch.h"
#include <iostream>
#include "Stack.h"
using namespace std;


const int MaxLength = 255; // ������������ ������ ������� ������
class TFormula {
private:
	int priority(const char & a);
	char Formula[MaxLength]; // ������� ������
	char PostfixForm[MaxLength]; // ����������� ������
public:
	TFormula(char form[]);
	int FormulaChecker(int *Brackets);// �������� ������������
	void FormulaConverter(void); // ������� � ����������� �����
	double FormulaCalculator(void); // ���������� ����������
};