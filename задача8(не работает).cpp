#include <iostream>
#include <fstream>
#include <string>
 
using namespace std;
 
// считает сколько каких цифр
int* countDigits(string s) {
	int *res = new int[10];
	for (int i = 0; i < 10; ++i)
		res[i] = 0;
 
	for (int i = 0; i < s.length(); ++i) {
		++res[s[i] - '0'];
	}
 
	return res;
}
 
string buildNumber(string s) {
	string res = "";
 
	// считаем, сколько пар цифр
	int *evenDigsCount = new int[10];
	for (int i = 0; i < 10; ++i)
		evenDigsCount[i] = 0;
 
	// здесь будут нечетные остатки
	int *oddDigsCount = countDigits(s);
 
	for (int i = 0; i < 10; ++i) {
		if (oddDigsCount[i] > 0) {
			evenDigsCount[i] = oddDigsCount[i] / 2; // сколько пар чисел есть
			oddDigsCount[i] = oddDigsCount[i] % 2; // остаток после того как отняли пары (0 или 1)
		}
	}
 
	// дописываем в середину нолики (ВСЕ пары)
	for (int i = 0; i < evenDigsCount[0]; ++i) {
		res += "00";
	}
 
	for (int i = 9; i > 0; --i) {
		for (int j = 0; j < evenDigsCount[i]; ++j) {
			char c = '0' + i;
			res = c + res + c; // приписываем слева и справа цифры
		}
	}
 
	// дописываем самую маленькую цифру в середину
	int i;
	for (i = 0; i < 10; ++i) {
		if (oddDigsCount[i]) // если не 0, то нашли самую маленькую цифру
			break;
	}
 
	char c = '0' + i;
	res.insert(s.length() / 2, 1, c);
 
	return res;
}
 
int main() {
	string in, out;
	cout << "Enter input file path:" << endl;
	getline(cin, in);
	cout << "Enter output file path:" << endl;
	getline(cin, out);
 
	ifstream f(in);
	ofstream g(out);
 
	if (!f || !g) {
		cout << "Error, blyat";
		return -1;
	}
 
	while (!f.eof()) {
		string line, nums = "";
		getline(f, line);
 
		for (int i = 0; i < line.length(); ++i) {
			if ('0' <= line[i] && line[i] <= '9') {
				nums += line[i];
			}
		}
 
		string res = buildNumber(nums);
		g << res << endl;
	}
 
	f.close();
	g.close();
 
	return 0;
}
