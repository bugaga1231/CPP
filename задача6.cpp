#include "pch.h"
#include <iostream>
using namespace std;

/*У исполнителя Калькулятор две команды, которым присвоены номера:
1.Прибавь 1,
2.Увеличь число десятков на 1.
Сколько есть программ, которые натуральное число А преобразуют в число В?*/

int Calculator(int A, int B) {
	int result = 0;
	if (B - 10 < A) {
		result = 1;
	}
	else
	{
		result = Calculator(A, B - 1) + Calculator(A, B - 10);
	}
	return result;
}

int main() {
	int A, B;
	cout << "Enter A,B " << endl;
	cin >> A >> B;
	cout << "Number of programs : " << Calculator(A, B) << endl;
	system("pause");
}
