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
	~TLink()
	{
// Тут типо удаляет
	}
};

class TPolinom
{
	TLink* pFirst;
	static int maxDegree;

public:
	TPolinom();
	TPolinom(char* strch);
	TPolinom(string str);
	~TPolinom();

	void SetMaxDegree(unsigned int var)
	{
		if (var > 10000)
			throw("Слишком большая степень");
		if ((var == 10) || (var == 100) || (var == 1000))
			maxDegree = var;
		else
			throw("Степень должна быть кратна 10");
	}
	void SortByMaxDegree();
	TPolinom operator+(const TPolinom &polinom);
	TPolinom operator*(int var);
	void ShowPolinom();
	int Calculate(int x, int y, int z);           // решение полинома по введённым числам
	TPolinom Differentiate(double difVar);         // дифферинцирование
	TPolinom Integrate(double integrVar);          // интегрирование
};

#endif
