#include "pch.h"
#include <iostream>
#include "Stack.h"
#include <string>
#include "Formula.h"
using namespace std;

int main()
{  
	
	int a[500];
	char string[500];
	gets_s(string);
	TFormula f(string);
	int e;
	double e2;
     e = f.FormulaChecker(a);
	if (e == 0)
	{
        f.FormulaConverter();
		try
		{
			e2 = f.FormulaCalculator();
			cout <<"  the result = "<<e2<<endl;
		}
		catch (int c )
		{
			if (c == 1)
			{
				cout << "  division by 0"<<endl;
			}
			if (c == 2)
			{
				cout << "  not enough operands"<<endl;
			}
			cout << "  the result cannot be calculated" << endl;
		}
	}
	else
	{
		cout << e << "  errors of positioning of the brackets" << endl;
		cout << "  the result cannot be calculated" << endl;
	}
	
}