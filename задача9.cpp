// ConsoleApplication2.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <iostream>
#include <fstream>
using namespace std;
struct student
{
	char second_name[21];
	char name[16];
	int mark1;
	int mark2;
	int mark3;
	int mark4;
	int mark = 0;
};

int main()
{
	int n; cin >> n;
	student b;
	ofstream f;
	f.open("F.bin", ios::binary);
	for (int i = 0; i < n; ++i)
	{
		cout << "Enter second name :" << endl;
		cin >> b.second_name;
		cout << "Enter name :" << endl;
		cin >> b.name;
		cout << "Enter marks :" << endl;
		cin >> b.mark1;
		cin >> b.mark2;
		cin >> b.mark3;
		cin >> b.mark4;
		f.write((char*)&b, sizeof(student));
	}
	f.close();
	f.flush();

	string s;
	student *a = new student[n];
	ifstream F("F.bin", ios::binary || ios::in);
	for (int i = 0; i < n; i++) {
		F.read((char*)&a[i], sizeof(student));
		(int)a[i].mark = (int)a[i].mark1 + (int)a[i].mark2 + (int)a[i].mark3 + (int)a[i].mark4;
	}
	F.close();

	student temp;
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (a[i].mark < a[j].mark) {
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}

	cout << a[0].second_name << ' ' << a[0].name << endl;
	cout << a[1].second_name << ' ' << a[1].name << endl;
	cout << a[2].second_name << ' ' << a[2].name << endl;

	system("pause");
	return 0;
}
