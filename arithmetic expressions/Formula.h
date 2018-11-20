#pragma once
#include "pch.h"
#include <iostream>
#include "Stack.h"
using namespace std;


const int MaxLength = 255; // максимальный размер входной строки
class TFormula {
private:
	int priority(const char & a);
	char Formula[MaxLength]; // входная строка
	char PostfixForm[MaxLength]; // постфиксная запись
public:
	TFormula(char form[]);
	int FormulaChecker(int *Brackets);// проверка правильности
	void FormulaConverter(void); // перевод в постфиксную форму
	double FormulaCalculator(void); // вычисление результата
};