#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	float a1 = 0;
	float a2 = 1;
	float sum = 0;
	float x;
	float eps;
	cin >> x;
	cin >> eps;
	
	for(int i = 1; abs(a1-a2) > eps; i++){
		a1 = a2;
		a2 *= (-1 * x * x)/((2 * i)*(2 * i - 1));
		sum += a2;
	}
	cout << sum;
	cout << a1 << endl << a2;
	return 0;
}
