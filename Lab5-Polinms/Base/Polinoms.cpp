#include "Polinoms.h"
#include <string>

using namespace std;

int PartOfStringToInt(string str, int& pos)
{
	int res;
	int j = pos;
	int count = 0;
	char *str2;
	string tmpstr;
	while ((str[j] >= '0') && (str[j] <= '9'))
	{
		count++;
		j++;
	}
	tmpstr = str.substr(pos,count);
	str2 = new char[tmpstr.size() + 1];
	pos = j;
	for (j = 0; j < tmpstr.size() + 1; j++)
		str2[j] = tmpstr[j];
	res = strtod(str2, NULL);

	return res;
}

int TPolinom::maxDegree;

TPolinom::TPolinom()
{
	this->pFirst = new TLink;
	this->pFirst->monom.coef = 0;
	this->pFirst->monom.degree = -1;
	this->pFirst->pNext = pFirst;
	this->elemCount = 0;
}

TPolinom::TPolinom(char* strch)
{
	setlocale(LC_ALL, "Russian");
	string str(strch);
	int size = str.size();
	string tmpstr;
	char now;
	int i, j, count;
	for (i = 0; i < size; i++)
	{
		now = str[i];
		if (!((now == '*') || (now == '^') || (now == '+') || (now == '-') || (now == 'x') || (now == 'y') || (now == 'z') || ((now >= '0') && (now <= '9'))) || (now == ' '))
			throw"Введён недопустимый символ";
	}
	TLink* linkStart = new TLink;
	linkStart->monom.degree = -1;
	linkStart->monom.coef = 0;
	TLink* currentPartOfLink = linkStart;
	i = 0;
	elemCount = 0;
	while (i < size)
	{
		j = i;
		count = 0;
		if ((str[j] == '-') || (str[j] == '+'))
		{
			j++;
			count++;
		}
		while ((str[j] != '+') && (str[j] != '-'))
		{
			count++;
			j++;
			if (j == size)
				break;
		}
		tmpstr = str.substr(i, count);
		j = 0;
		currentPartOfLink->pNext = new TLink;
		currentPartOfLink = currentPartOfLink->pNext;
		currentPartOfLink->monom.coef = 1;
		if (tmpstr[j] == '-')
		{
			currentPartOfLink->monom.coef = -1;
			j++;
		}
		if (tmpstr[j] == '+')
			j++;
		if ((tmpstr[j] >= '0') && (tmpstr[j] <= '9'))
			currentPartOfLink->monom.coef *= PartOfStringToInt(tmpstr, j);
		else if ((tmpstr[j] == 'x') || (tmpstr[j] == 'y') || (tmpstr[j] == 'z'));
		else
			throw"Ошибка ввода полинома: Неверно начат полином";
		if (tmpstr[j] == '*')
			j++;
		currentPartOfLink->monom.degree = 0;
		if (tmpstr[j] == 'x')
		{
			j++;
			if (tmpstr[j] == '^')
			{
				j++;
				if (!((tmpstr[j] >= '0') && (tmpstr[j] <= '9')))
					throw "Ошибка ввода полинома: Неправильная запись монома 1";
			}
			if ((tmpstr[j] >= '0') && (tmpstr[j] <= '9'))
				currentPartOfLink->monom.degree += maxDegree*maxDegree*PartOfStringToInt(tmpstr, j);
			else
				currentPartOfLink->monom.degree += maxDegree*maxDegree * 1;
		}
		if (tmpstr[j] == '*')
			j++;
		if (tmpstr[j] == 'y')
		{
			j++;
			if (tmpstr[j] == '^')
			{
				j++;
				if (!((tmpstr[j] >= '0') && (tmpstr[j] <= '9')))
					throw"Ошибка ввода полинома: Неправильная запись монома 2";
			}
			if ((tmpstr[j] >= '0') && (tmpstr[j] <= '9'))
				currentPartOfLink->monom.degree += maxDegree*PartOfStringToInt(tmpstr, j);
			else
				currentPartOfLink->monom.degree += maxDegree * 1;
		}
		if (tmpstr[j] == '*')
			j++;
		if (tmpstr[j] == 'z')
		{
			j++;
			if (tmpstr[j] == '^')
			{
				j++;
				if (!((tmpstr[j] >= '0') && (tmpstr[j] <= '9')))
					throw"Ошибка ввода полинома: Неправильная запись монома 3";
			}
			if ((tmpstr[j] >= '0') && (tmpstr[j] <= '9'))
				currentPartOfLink->monom.degree += PartOfStringToInt(tmpstr, j);
			else
				currentPartOfLink->monom.degree += 1;
		}
		if (j != tmpstr.size())
			throw"Ошибка ввода полинома: Неправильная запись монома 4";
		i += j;
		elemCount++;
	}
	currentPartOfLink->pNext = linkStart;
	this->pFirst = linkStart;
	this->SortByMaxDegree();
}

TPolinom::TPolinom(string str)
{
	setlocale(LC_ALL, "Russian");
	int size = str.size();
	string tmpstr;
	char now;
	int i, j, count;
	for (i = 0; i < size; i++)
	{
		now = str[i];
		if (!((now == '*') || (now == '^') || (now == '+') || (now == '-') || (now == 'x') || (now == 'y') || (now == 'z')||((now>='0')&&(now<='9'))) || (now == ' '))
			throw"Введён недопустимый символ";
	}
	TLink* linkStart = new TLink;
	linkStart->monom.degree = -1;
	linkStart->monom.coef = 0;
	TLink* currentPartOfLink = linkStart;
	i = 0;
	elemCount = 0;
	while (i < size)
	{
		j = i;
		count = 0;
		if ((str[j] == '-') || (str[j] == '+'))
		{
			j++;
			count++;
		}
		while ((str[j] != '+') && (str[j] != '-'))
		{
			count++;
			j++;
			if (j == size)
				break;
		}
		tmpstr = str.substr(i, count);
		j = 0;
		currentPartOfLink->pNext = new TLink;
		currentPartOfLink = currentPartOfLink->pNext;
		currentPartOfLink->monom.coef = 1;
		if (tmpstr[j] == '-')
		{
			currentPartOfLink->monom.coef = -1;
			j++;
		}
		if (tmpstr[j] == '+')
			j++;
		if ((tmpstr[j] >= '0') && (tmpstr[j] <= '9'))
			currentPartOfLink->monom.coef *= PartOfStringToInt(tmpstr, j);
		else if ((tmpstr[j] == 'x') || (tmpstr[j] == 'y') || (tmpstr[j] == 'z'));
		else
			throw"Ошибка ввода полинома: Неверно начат полином";
		if (tmpstr[j] == '*')
			j++;
		currentPartOfLink->monom.degree = 0;
		if (tmpstr[j] == 'x')
		{
			j++;
			if (tmpstr[j] == '^')
			{
				j++;
				if (!((tmpstr[j] >= '0') && (tmpstr[j] <= '9')))
					throw "Ошибка ввода полинома: Неправильная запись монома 1";
			}
			if ((tmpstr[j] >= '0') && (tmpstr[j] <= '9'))
				currentPartOfLink->monom.degree += maxDegree*maxDegree*PartOfStringToInt(tmpstr, j);
			else
				currentPartOfLink->monom.degree += maxDegree*maxDegree*1;
		}
		if (tmpstr[j] == '*')
			j++;
		if (tmpstr[j] == 'y')
		{
			j++;
			if (tmpstr[j] == '^')
			{
				j++;
				if (!((tmpstr[j] >= '0') && (tmpstr[j] <= '9')))
					throw"Ошибка ввода полинома: Неправильная запись монома 2";
			}
			if ((tmpstr[j] >= '0') && (tmpstr[j] <= '9'))
				currentPartOfLink->monom.degree += maxDegree*PartOfStringToInt(tmpstr, j);
			else
				currentPartOfLink->monom.degree += maxDegree*1;
		}
		if (tmpstr[j] == '*')
			j++;
		if (tmpstr[j] == 'z')
		{
			j++;
			if (tmpstr[j] == '^')
			{
				j++;
				if (!((tmpstr[j] >= '0') && (tmpstr[j] <= '9')))
					throw"Ошибка ввода полинома: Неправильная запись монома 3";
			}
			if ((tmpstr[j] >= '0') && (tmpstr[j] <= '9'))
				currentPartOfLink->monom.degree += PartOfStringToInt(tmpstr, j);
			else
				currentPartOfLink->monom.degree += 1;
		}
		if (j != tmpstr.size())
			throw"Ошибка ввода полинома: Неправильная запись монома 4";
		i += j;
		elemCount++;
	}
	currentPartOfLink->pNext = linkStart;
	this->pFirst = linkStart;
	this->SortByMaxDegree();
}

TPolinom::~TPolinom()
{
	TLink *tmp = this->pFirst;
	tmp = tmp->pNext;
	TLink *tmpDel;
	while (tmp->monom.degree != -1)
	{
		tmpDel = tmp;
		tmp = tmp->pNext;
		delete tmpDel;
	}
	delete tmp;
}

void TPolinom::SortByMaxDegree()
{
	return;
	int max = -1;
	int start = 1;
	TLink* prePointer;
	TLink* postPointer;
	TLink *lastPointer;
	TLink *maxPointer;
	TLink *temp;
	int count = 0;
	TLink *tmp = this->pFirst;
	tmp = tmp->pNext;
	while (tmp->monom.degree != -1)
	{
		tmp = tmp->pNext;
		count++;
	}
	for (int j = 0; j < count; j++)
	{
		tmp = this->pFirst;
		for (int i = 0; i < start; i++)
		{
			lastPointer = tmp;
			tmp = tmp->pNext;
		}
		for (tmp; tmp->monom.degree != -1; tmp = tmp->pNext)
		{
			if (tmp->monom.degree > max)
			{
				max = tmp->monom.degree;
				maxPointer = tmp;
				postPointer = tmp->pNext;
				prePointer = lastPointer;
			}
			lastPointer = tmp;
		}
		tmp = this->pFirst;
		for (int i = 0; i < start; i++)
		{
			tmp = tmp->pNext;
		}
		temp = tmp->pNext;
		prePointer->pNext = postPointer;
		tmp->pNext = maxPointer;
		tmp = tmp->pNext;
		tmp->pNext = temp;
		start++;
	}
}

TPolinom TPolinom::operator+(const TPolinom &polinom)
{
	TPolinom tmp;


	return tmp;;
}

TPolinom TPolinom::operator*(int var)
{
	TPolinom tmp;


	return tmp;;
}

void TPolinom::ShowPolinom()
{
	TLink *tmp = this->pFirst;
	int count = 0;
	tmp = tmp->pNext;
	while (tmp->monom.degree != -1)
	{
		tmp = tmp->pNext;
		count++;
	}
	tmp = this->pFirst;
	tmp = tmp->pNext;
	for (int i = 0; i < count; i++)
	{
		if (tmp->monom.coef != 1)
			cout << tmp->monom.coef;
		if (tmp->monom.degree / (maxDegree*maxDegree) > 0)
		{
			cout << "x";
			if (tmp->monom.degree / (maxDegree*maxDegree) > 1)
				cout << "^" << tmp->monom.degree / (maxDegree*maxDegree);
		}
		if (tmp->monom.degree / maxDegree % maxDegree > 0)
		{
			cout << "y";
			if (tmp->monom.degree / maxDegree % maxDegree > 1)
				cout << "^" << tmp->monom.degree / maxDegree % maxDegree;
		}
		if (tmp->monom.degree % maxDegree > 0)
		{
			cout << "z";
			if (tmp->monom.degree % maxDegree > 1)
				cout << "^" << tmp->monom.degree % maxDegree;
		}
		tmp = tmp->pNext;
		if (tmp->monom.coef != 0)
			if (tmp->monom.coef > 0)
				cout << "+";
	}
	cout << endl;
}

int TPolinom::Calculate(int x, int y, int z)
{
	TLink *tmp = this->pFirst;
	int count = 0;
	int res = 0;
	int tmpint;
	tmp = tmp->pNext;
	while (tmp->monom.degree != -1)
	{
		count = tmp->monom.coef;
		tmpint = 1;
		if (tmp->monom.degree / (maxDegree*maxDegree) != 0)
		{
			for (int i = 0; i < (tmp->monom.degree / (maxDegree*maxDegree)); i++)
				tmpint *= x;
			count *= tmpint;
		}
		tmpint = 1;
		if ((tmp->monom.degree / maxDegree) % maxDegree != 0)
		{
			for (int i = 0; i < (tmp->monom.degree / maxDegree % maxDegree); i++)
				tmpint *= y;
			count *= tmpint;
		}
		tmpint = 1;
		if (tmp->monom.degree % maxDegree != 0)
		{
			for (int i = 0; i < (tmp->monom.degree % maxDegree); i++)
				tmpint *= z;
			count *= tmpint;
		}
		res += count;
		tmp = tmp->pNext;
	}
	return res;
}

TPolinom TPolinom::Differentiate(int difVar)
{
	TPolinom result;
	TLink *tmp = this->pFirst;
	tmp = tmp->pNext;
	TLink *currentPartOfLink = result.pFirst;
	while (tmp->monom.degree != -1)
	{
		if (difVar == 1)
		{
			if ((tmp->monom.degree / (maxDegree*maxDegree) - 1) >= 0)
			{
				currentPartOfLink->pNext = new TLink;
				currentPartOfLink = currentPartOfLink->pNext;
				currentPartOfLink->monom.degree = tmp->monom.degree;
				currentPartOfLink->monom.degree -= 1*maxDegree*maxDegree;
				currentPartOfLink->monom.coef = tmp->monom.coef*(tmp->monom.degree / (maxDegree*maxDegree));
			}
		}
		if (difVar == 2)
		{
			if (((tmp->monom.degree / maxDegree % maxDegree) - 1) >= 0)
			{
				currentPartOfLink->pNext = new TLink;
				currentPartOfLink = currentPartOfLink->pNext;
				currentPartOfLink->monom.degree = tmp->monom.degree;
				currentPartOfLink->monom.degree -= 1 * maxDegree;
				currentPartOfLink->monom.coef = tmp->monom.coef*(tmp->monom.degree / maxDegree % maxDegree);
			}
		}
		if (difVar == 3)
		{
			if ((tmp->monom.degree % maxDegree - 1) >= 0)
			{
				currentPartOfLink->pNext = new TLink;
				currentPartOfLink = currentPartOfLink->pNext;
				currentPartOfLink->monom.degree = tmp->monom.degree;
				currentPartOfLink->monom.degree--;
				currentPartOfLink->monom.coef = tmp->monom.coef*(tmp->monom.degree % maxDegree);
			}
		}
		tmp = tmp->pNext;
	}
	currentPartOfLink->pNext = result.pFirst;
	return result;
}

TPolinom TPolinom::Integrate(int integrVar)
{
	TPolinom result;
	TLink *tmp = this->pFirst;
	tmp = tmp->pNext;
	TLink *currentPartOfLink = result.pFirst;
	while (tmp->monom.degree != -1)
	{
		if (integrVar == 1)
		{
			if ((tmp->monom.degree / (maxDegree*maxDegree))+1 == maxDegree)
			{
				cout << "Невозможно проинтегрировать слишком большая степень в результате" << endl;
				return 0;
			}
				currentPartOfLink->pNext = new TLink;
				currentPartOfLink = currentPartOfLink->pNext;
				currentPartOfLink->monom.degree = tmp->monom.degree;
				currentPartOfLink->monom.degree += 1 * maxDegree*maxDegree;
				currentPartOfLink->monom.coef = tmp->monom.coef / ((tmp->monom.degree / (maxDegree*maxDegree)) + 1);
		}
		if (integrVar == 2)
		{
			if ((tmp->monom.degree / maxDegree % maxDegree)+1 == maxDegree)
			{
				cout << "Невозможно проинтегрировать слишком большая степень в результате" << endl;
				return 0;
			}
				currentPartOfLink->pNext = new TLink;
				currentPartOfLink = currentPartOfLink->pNext;
				currentPartOfLink->monom.degree = tmp->monom.degree;
				currentPartOfLink->monom.degree += 1 * maxDegree;
				currentPartOfLink->monom.coef = tmp->monom.coef / ((tmp->monom.degree / maxDegree % maxDegree) + 1);

		}
		if (integrVar == 3)
		{
			if ((tmp->monom.degree % maxDegree) + 1 == maxDegree)
			{
				cout << "Невозможно проинтегрировать слишком большая степень в результате" << endl;
				return 0;
			}
				currentPartOfLink->pNext = new TLink;
				currentPartOfLink = currentPartOfLink->pNext;
				currentPartOfLink->monom.degree = tmp->monom.degree;
				currentPartOfLink->monom.degree++;
				currentPartOfLink->monom.coef = tmp->monom.coef / ((tmp->monom.degree % maxDegree) + 1);
		}
		tmp = tmp->pNext;
	}
	currentPartOfLink->pNext = result.pFirst;
	return result;
}

string TPolinom::PolinomToString()
{
	string str;
	TLink *tmp = this->pFirst;
	int count = 0;
	tmp = tmp->pNext;
	while (tmp->monom.degree != -1)
	{
		tmp = tmp->pNext;
		count++;
	}
	tmp = this->pFirst;
	tmp = tmp->pNext;
	for (int i = 0; i < count; i++)
	{
		if (tmp->monom.coef != 1)
			str+= to_string(tmp->monom.coef);
		if (tmp->monom.degree / (maxDegree*maxDegree) > 0)
		{
			str += "x";
			if (tmp->monom.degree / (maxDegree*maxDegree) > 1)
			{
				str += "^";
				str += to_string(tmp->monom.degree / (maxDegree*maxDegree));
			}
		}
		if (tmp->monom.degree / maxDegree % maxDegree > 0)
		{
			str += "y";
			if (tmp->monom.degree / maxDegree % maxDegree > 1)
			{
				str += "^";
				str += to_string(tmp->monom.degree / maxDegree % maxDegree);
			}
		}
		if (tmp->monom.degree % maxDegree > 0)
		{
			str += "z";
			if (tmp->monom.degree % maxDegree > 1)
			{
				str += "^";
				str += to_string(tmp->monom.degree % maxDegree);
			}
		}
		tmp = tmp->pNext;
		if (tmp->monom.coef != 0)
			if (tmp->monom.coef > 0)
				str+="+";
	}

	return str;
}