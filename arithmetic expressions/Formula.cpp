#include "pch.h"
#include <string>
#include "Formula.h"
using namespace std;

TFormula:: TFormula (char form[])
{
	strcpy_s(Formula, 255, form);
}


int TFormula::FormulaChecker(int * Brackets)
{
	int eror = 0;
	int b_num = 0;
	int k =-1;
	TStack <int> s(500);
	for (int i = 0; i < strlen(Formula); i++)
	{
		if (Formula[i] == '(')
		{
			s.Put(++b_num);
		}
		if (Formula[i] == ')')
		{
			if (!s.IsEmpty())
			{
				Brackets[++k] = s.Get();
				Brackets[++k] = ++b_num;
				k++;
			}
			else
			{
				eror++;
				Brackets[++k] = 0;
				Brackets[++k] = ++b_num;
			}
		}
	}
	while (!s.IsEmpty() )
	{
		eror++;
		Brackets[++k] = s.Get();
		Brackets[++k] = 0;
	}
	return eror;
	
}

int TFormula::priority(const char & a)
{
	int k = 0;
	switch (a)
	{
	case '(':
		break;
	case ')':
		k = 1;
		break;
	case '+':
		k = 2;
		break;
	case '-':
		k = 2;
		break;
	case '*':
		k = 3; 
		break;
	case '/':
		k = 3;
		break;
	default:
		k = -1;
	}
	return k;
}


void TFormula::FormulaConverter()
{
	int start_ind;
	int post_ind = -1;
	char hed_st;
	TStack <char> s(500);
	for (int i = 0; i < strlen(Formula); i++)
	{
		if (Formula[i] >= '0'&&Formula[i] <= '9')
		{
			start_ind = i;
			while (i < strlen(Formula) && (Formula[i] >= '0'&&Formula[i] <= '9' || Formula[i] == '.'))
			{
				i++;
			}
			for (int j= start_ind;j<i;j++)
			{

				PostfixForm[++post_ind] = Formula[j];
			}
			PostfixForm[++post_ind] = ' ';
		}
		if (priority(Formula[i])>=0)
		{
			if (s.IsEmpty() || priority(Formula[i]) == 0)
			{
				s.Put(Formula[i]);
			}
			else
			{
				hed_st = s.Get();
				if (priority(Formula[i]) > priority(hed_st))
				{
					s.Put(hed_st);
					s.Put(Formula[i]);
				}
				else
				{
					if (Formula[i] == ')')
					{
						while (hed_st != '(')
						{
							PostfixForm[++post_ind] = hed_st;
							PostfixForm[++post_ind] = ' ';
							hed_st = s.Get();
						}
					}
					else
					{
						while (priority(Formula[i]) <= priority(hed_st) )
						{
							PostfixForm[++post_ind] = hed_st;
							PostfixForm[++post_ind] = ' ';
							if (s.IsEmpty())
							{
								break;
							}
							hed_st = s.Get();
						}
						if (priority(Formula[i]) > priority(hed_st))
						{
							s.Put(hed_st);
						}
						s.Put(Formula[i]);
					}
				}
			}
		}
	}
	while (!s.IsEmpty())
	{
		PostfixForm[++post_ind] = s.Get();
		PostfixForm[++post_ind] = ' ';
	}
	PostfixForm[++post_ind] = '\0';
	cout << "  the postfix entry ";
	for (int i = 0; i <= post_ind; i++)
	{
		cout << PostfixForm[i];
	}
	cout << endl;
}



double TFormula::FormulaCalculator()
{
	TStack <double> s(500);
	double k = 0, j = 0;
	double a, b;
	for (int i = 0; i < strlen(PostfixForm);i++)
	{
		if (PostfixForm[i] >= '0'&& PostfixForm[i] <= '9')
		{
			while (PostfixForm[i] != ' '&& i < strlen(PostfixForm))
			{
				if (PostfixForm[i] != '.')
				{
					k = k * 10 + (PostfixForm[i] - '0');
				}
				else
				{
					j = i;
				}
				i++;
			}
			if (j != 0)
			{
				k = k / pow(10, i - j - 1);
			}
			s.Put(k); 
			j = 0;
			k = 0;
		}
		if (priority(PostfixForm[i]) == 2 || priority(PostfixForm[i]) == 3)
		{
			if (s.IsEmpty())
			{
				throw 2;
			}
			a = s.Get();
			if (s.IsEmpty())
			{
				if (PostfixForm[i] == '-')
				{
					b = 0;
				}
				else
				{
					throw 2;
				}
			}
			else
			{
				b = s.Get();
			}
			switch (PostfixForm[i])
			{
			case '+':
				b = b + a;
				break;
			case '-':
				b = b - a;
				break;
			case '*':
				b = b * a;
				break;
			case '/':
				b = b / a;
				if (a == 0)
				{
					throw 1;
				}
				break;
			}
			s.Put(b);
		}
	}
	return s.Get();
}
