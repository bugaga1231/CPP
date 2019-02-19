#include <iostream>
#include <string>

using namespace std;

bool isLetterOrDigit(char c) {
	return ('a' <= c && c <= 'z') || ('0' <= c && c <= '9');
}

int main() {
	string s = " ", input;
	getline(cin, input);
	s += input + " "; // чтобы начало и конец были пробелами

	int res = 0;

	int wordStart, wordEnd;
	for (int i = 0; i < s.length() - 1; ++i) {
		if (s[i] == ' ' && isLetterOrDigit(s[i + 1]))
			wordStart = i + 1;
		
		// нашли слово
		if (isLetterOrDigit(s[i]) && s[i + 1] == ' ') {
			wordEnd = i;
			
			if ('0' <= s[wordStart] && s[wordStart] <= '9' && '0' <= s[wordEnd] && s[wordEnd] <= '9')
				++res;
		}
	}

	cout << res << endl;

	return 0;
}
