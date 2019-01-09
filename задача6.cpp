#include "pch.h"
#include <iostream>
using namespace std;

/*У исполнителя Калькулятор две команды, которым присвоены номера:
1.Прибавь 1,
2.Увеличь число десятков на 1.
Сколько есть программ, которые натуральное число А преобразуют в число В?*/
int F(int x, int y){
	if (x == y) return 1;
	if (x < y) {
		if(((x/10)%10) != 9)
			return F(x+10, y) + F(x+1, y);
		else return F(x +1, y);
	}
		else
			return 0;
}

int main() {
	int A, B;
	cout << "Enter A,B " << endl;
	cin >> A >> B;
	cout << "Number of programs : " << Calculator(A, B) << endl;
	system("pause");
}
