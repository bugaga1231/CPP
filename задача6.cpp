#include <iostream>

using namespace std;


int Calculator(int A,int B){
	int result = 0;
	if (A == B) {
		result = 1;
	}
	else
	{
		if (A + 10 < B) result = Calculator(A + 1, B) + Calculator(A + 10 ,B);
		else result = Calculator(A + 1, B);
	}
	return result;
}

int main() {
	int A, B;
	cout << "Enter A,B " << endl;
	cin >> A >> B;
	cout << "Number of programs : " << Calculator(A, B) << endl;
	return 0;
}
