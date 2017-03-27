#ifndef __POLINOMS_H__
#define __POLINOMS_H__
#include <string>
#include <iostream>

using namespace std;

struct TMonom
{
	double coef;
	int degree;
};

struct TLink
{
	TMonom monom;
	TLink* pNext;
};

class TPolinom
{
	TLink* pFirst;
	static int maxDegree;
	int elemCount;

	void SortByMaxDegree();

public:
	TPolinom();
	TPolinom(char* strch);
	TPolinom(string str);
	~TPolinom();

	static void SetMaxDegree(unsigned int var)
	{
		if (var > 10000)
			throw("Слишком большая степень");
		if ((var == 10) || (var == 100) || (var == 1000))
			maxDegree = var;
		else
			throw("Степень должна быть кратна 10");
	}
	TPolinom operator+(const TPolinom &polinom);
	TPolinom operator*(int var);
	void ShowPolinom();
	string PolinomToString();
	int Calculate(int x, int y, int z);           // решение полинома по введённым числам
	TPolinom Differentiate(int difVar);         // дифферинцирование
	TPolinom Integrate(int integrVar);          // интегрирование
};

#endif
