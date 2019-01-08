#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct student
{
	string second_name;
	string name;
	string mark;
};

struct student_ {
	string second_name;
	string name;
	int mark1 = 0;
	int mark2 = 0;
	int mark3 = 0;
	int mark4 = 0;
	int mark = 0;
};
int main()
{
	int n; cin >> n;
	student b;
	ofstream f;
	f.open("F.txt");
	for (int i = 0; i < n; ++i)
	{
		cout << "Enter second name :" << endl;
		cin >> b.second_name;
		cout << "Enter name :" << endl;
		cin >> b.name;
		cout << "Enter mark :" << endl;
		cin.ignore(32767, '\n');
		getline(cin, b.mark);
		f << b.second_name << " " << b.name << " " << b.mark << endl;
	}
	f.close();

	string s;
	ifstream F;
	student_ *a = new student_[n];
	F.open("F.txt");
	for(int i = 0; i < n; i++) {
		getline(F, s);
		int j, k, z1, z2, z3, z4;
		for (j = 0; s[j] != ' '; j++)
			a[i].second_name += s[j];
		for (k = j + 1; s[k] != ' '; k++)
			a[i].name += s[k];
		for (z1 = k + 1; s[z1] != ' '; z1++){
			a[i].mark1 += (s[z1] & 0x0F);
			a[i].mark1 *= 10;
		}
		a[i].mark1 /= 10;
		for (z2 = z1 + 1; s[z2] != ' '; z2++) {
			a[i].mark2 += (s[z2] & 0x0F);
			a[i].mark2 *= 10;
		}
		a[i].mark2 /= 10;
		for (z3 = z2 + 1; s[z3] != ' '; z3++) {
			a[i].mark3 += (s[z3] & 0x0F);
			a[i].mark3 *= 10;
		}
		a[i].mark3 /= 10;
		for (z4 = z3 + 1; z4 < s.length(); z4++) {
			a[i].mark4 += (s[z4] & 0x0F);
			a[i].mark4 *= 10;
		}
		a[i].mark4 /= 10;

		a[i].mark = a[i].mark1 + a[i].mark2 + a[i].mark3 + a[i].mark4;

	}
	F.close();

	student_ temp;
	for(int i = 0; i < n - 1; i++)
		for (int j =  i + 1; j < n; j++)
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
