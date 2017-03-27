#include "Polinoms.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	string str;
	unsigned int degree;
	int x, y, z;
	cout << "Введите максимальную степень переменной" << endl;
	cin >> degree;
	cout << "Введите полином" << endl;
	cin >> str;
	try
	{
		TPolinom::SetMaxDegree(degree);
		TPolinom Polinom(str);
		cout << "Введённый полином:" << endl;
		Polinom.ShowPolinom();
		cout << "Введите x" << endl;
		cin >> x;
		cout << "Введите y" << endl;
		cin >> y;
		cout << "Введите z" << endl;
		cin >> z;
		cout << "Ответ:" << Polinom.Calculate(x, y, z) << endl;
		string tmpstring = Polinom.PolinomToString();
		cout << tmpstring << endl;
		TPolinom Pol;
		Pol = Polinom.Differentiate(1);
		tmpstring = Pol.PolinomToString();
		Pol.ShowPolinom();
		cout << tmpstring << endl;
		TPolinom Pol1;
		Pol1 = Polinom.Integrate(1);
		Pol1.ShowPolinom();
		tmpstring = Pol1.PolinomToString();
		cout << tmpstring << endl;
	}
	catch (char* ch)
	{
		cout << ch << endl;
	}
	return 0;
}