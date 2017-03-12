#include "Polinoms.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	string str;
	int degree;
	cin >> degree;
	cin >> str;
	try
	{
		TPolinom tmp;
		tmp.SetMaxDegree(degree);
		TPolinom Polinom(str);
		Polinom.SetMaxDegree(degree);
		Polinom.ShowPolinom();
	}
	catch (char* ch)
	{
		cout << ch << endl;
	}
	return 0;
}