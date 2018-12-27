#include "stdafx.h"
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

int main() {
	int count = 0;
	int n;
	fstream F, G;
	string s;
	F.open("F.txt", ios::out);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		F << s;
	}
	F.close();

	F.open("F.txt", ios::in);
	G.open("G.txt", ios::out); //Привязываем и открываем файлы
	
	string SG = { " " };
	int Col = 1;
	char NumberChar;
	int Mas[10] = { 0 }; // 2 Массива 1 кол-во i  цифр в Mas[i] и кол-во этих же цифр поделеных на 2
	int Mas1[10] = { 0 };
	int Number;
	while (!F.eof()) {
		for (int i = 1; i < 10; i++) {
			Mas[i] = { 0 };
			Mas1[i] = { 0 };
		}
		Col = 1;
		getline(F, s);
		cout << s << endl;
		for (int i = 0; i < size(s); i++) {
			NumberChar = s.operator[](i); // В NumberChar символ, в Number само число из NumberChar 
			Number = (NumberChar & 0x0F);
			Mas[Number]++;
		}
		Number = 0;
		for (int i = 1; i < 10; i++) {
			NumberChar = i;
			while (Mas[i] >= 2) {
				Number = Number + i * Col;
				Col = Col * 10;
				Mas1[i]++;
				Mas[i] -= 2; // Составляем первую половину числа , и запоминаем сколько чисел мы уже записали 
			}
		}
		for (int i = 9; i > 0; i--) {
			while (Mas1[i] >= 1) {
				Number = Number + i * Col;
				Col = Col * 10;
				Mas1[i]--; // Дописываем остальную часть числа 
			}
		}

		G << Number << endl;
		SG.clear();
	}
	F.close();
	G.close();

	G.open("G.txt", ios::in);
	for (int i = 0; i < n; i++) {
		getline(G, s);
		cout << s;
	}
	system("pause");
	return 0;
}
