#include "pch.h"
#include <iostream>
using namespace std;

int main() {
	int a;
	int b;
	cout << "ENTER A1 : ";
	cin >> a;
	if (a != 0) {
		cout << "ENTER A2 : ";
		cin >> b;
		int length = 0;
		int max_length = 0;
		for (int j = 3; b != 0; j++) {
			if (a > b) {
				length++;
			}
			else {
				if (max_length < length) {
					max_length = length;
					length = 0;
				}
			}
			a = b; 
			cout << "ENTER A" << j << " : ";
			cin >> b;
		}
		cout << "MAX LENGTH = ";
		if (max_length > length) cout << max_length;
		else cout << length;
	}
	else {
		cout << "END";
	}

}
