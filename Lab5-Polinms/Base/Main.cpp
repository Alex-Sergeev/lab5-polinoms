#include "Polinoms.h"
#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	string strIn;
	unsigned int degree;
	int x, y, z;
	TPolinom TPolArray[50];
	int choice;
	int choice2;
	int choice3;
	int resultCalculate;
	int currentAmountOfPolinoms = 1;
	cout << "                       Лабораторная работа №5" << endl;
	cout << "                               Полиномы" << endl;
	cout << "Введите максимальную степень монома" << endl;
	cin >> degree;
	cout << "Введите начальный полином" << endl;
	cin >> strIn;
	TPolinom result;
	try 
	{
		TPolinom::SetMaxDegree(degree);
		TPolinom Polinom(strIn);
		TPolArray[0] = Polinom;
	}
	catch (char* ch)
	{
		cout << ch << endl;
		return 1;
	}
	while (true)
	{
		cout << endl;
		cout << "          Меню" << endl;
		cout << "1. Показать все полиномы" << endl;
		cout << "2. Показать выбранный полином" << endl;
		cout << "3. Ввести новый полином" << endl;
		cout << "4. Сложить полиномы" << endl;
		cout << "5. Умножить полином на число" << endl;
		cout << "6. Продифферинцировать полином" << endl;
		cout << "7. Проинтегрировать полином" << endl;
		cout << "8. Ввести коэффициэнты x,y,z и вычислить полином" << endl;
		cout << "0. Выйти из программы" << endl;
		cin >> choice;
		system("cls");
		switch (choice)
		{
		case 1:
			cout << "Полиномы:" << endl;
			for (int i = 0; i < currentAmountOfPolinoms; i++)
			{
				cout << i << ". ";
				TPolArray[i].ShowPolinom();
			}
			break;
		case 2:
			cout << "Введите индекс выводимого полинома" << endl;
			cin >> choice2;
			if ((choice2 < 0) || (choice2 >= currentAmountOfPolinoms))
				break;
			cout << "Полином: ";
			TPolArray[choice2].ShowPolinom();
			break;
		case 3:
			cin >> strIn;
			try
			{
				TPolinom Polinom(strIn);
				TPolArray[currentAmountOfPolinoms] = Polinom;
				currentAmountOfPolinoms++;
			}
			catch (char* ch)
			{
				cout << ch << endl;
			}
			break;
		case 4:
			cout << "Введите индекс 1 складываемого полинома" << endl;
			cin >> choice2;
			cout << "Введите индекс 2 складываемого полинома" << endl;
			cin >> choice3;
			if ((choice2 < 0) || (choice2 >= currentAmountOfPolinoms))
				break;
			if ((choice3 < 0) || (choice3 >= currentAmountOfPolinoms))
				break;
			result = TPolArray[choice2] + TPolArray[choice3];
			cout << "Получившийся полином: ";
			result.ShowPolinom();
			cout << "Сохранить получившийся полином? 1 да ,0 нет" << endl;
			cin >> choice3;
			if (choice3 == 0)
				break;
			if (choice3 == 1)
			{
				TPolArray[currentAmountOfPolinoms] = result;
				currentAmountOfPolinoms++;
			}
			break;
		case 5:
			cout << "Введите число на которое множается полином:" << endl;
			cin >> choice2;
			cout << "Введите индекс умножаемого полинома:" << endl;
			cin >> choice3;
			if ((choice3 < 0) || (choice3 >= currentAmountOfPolinoms))
				break;
			result = TPolArray[choice3] * choice2;
			cout << "Получившийся полином: ";
			result.ShowPolinom();
			cout << "Сохранить получившийся полином? 1 да ,0 нет" << endl;
			cin >> choice3;
			if (choice3 == 0)
				break;
			if (choice3 == 1)
			{
				TPolArray[currentAmountOfPolinoms] = result;
				currentAmountOfPolinoms++;
			}
			break;
		case 6:
			cout << "Введите индекс дифферинцируемого полинома" << endl;
			cin >> choice2;
			if ((choice2 < 0) || (choice2 >= currentAmountOfPolinoms))
				break;
			cout << "Введите по какой переменной ведётся дифферинцирование 1.x 2.y 3.z" << endl;
			cin >> choice3;
			if ((choice3 < 1) || (choice3 > 3))
				break;
			result = TPolArray[choice2].Differentiate(choice3);
			cout << "Получившийся полином: ";
			result.ShowPolinom();
			cout << "Сохранить получившийся полином? 1 да ,0 нет" << endl;
			cin >> choice3;
			if (choice3 == 0)
				break;
			if (choice3 == 1)
			{
				TPolArray[currentAmountOfPolinoms] = result;
				currentAmountOfPolinoms++;
			}
			break;
		case 7:
			cout << "Введите индекс интегрируемого полинома" << endl;
			cin >> choice2;
			if ((choice2 < 0) || (choice2 >= currentAmountOfPolinoms))
				break;
			cout << "Введите по какой переменной ведётся интегрирование 1.x 2.y 3.z" << endl;
			cin >> choice3;
			if ((choice3 < 1) || (choice3 > 3))
				break;
			result = TPolArray[choice2].Integrate(choice3);
			cout << "Получившийся полином: ";
			result.ShowPolinom();
			cout << "Сохранить получившийся полином? 1 да ,0 нет" << endl;
			cin >> choice3;
			if (choice3 == 0)
				break;
			if (choice3 == 1)
			{
				TPolArray[currentAmountOfPolinoms] = result;
				currentAmountOfPolinoms++;
			}
			break;
		case 8:
			cout << "Введите индекс полинома для вычесления:" << endl;
			cin >> choice2;
			if ((choice2 < 0) || (choice2 >= currentAmountOfPolinoms))
				break;
			TPolArray[choice2].ShowPolinom();
			cout << "Введите х:" << endl;
			cin >> x;
			cout << "Введите y:" << endl;
			cin >> y;
			cout << "Введите z:" << endl;
			cin >> z;
			resultCalculate = TPolArray[choice2].Calculate(x,y,z);
			cout << "Получившийся результат: " << resultCalculate << endl;
			break;
		case 0:
			return 0;
		}
	}
}