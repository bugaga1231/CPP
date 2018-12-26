#include <iostream>

int main(){
  int kol, n;
  string s;
  getline(cin, s);
  kol = 0;
  for(int i = 0; i < s.length(); i++){
    if ((s[i] >= '0') && (s[i] <= '9')){
      if (i == 0)
      {
        j = i + 1;
        while(s[j] != ' '){
          j++;
        }
        if ((s[j-1] >='0') && (s[j-1] <= '9')){
          kol++;
        }
        i = j;
      }
    }
    else{
      if(s[i-1] == ' '){
        j = i + 1;
        while(s[j] != ' '){
          j++;
        }
        if((s[j-1] >= '0') && (s[j-1] <='9')) {
          kol++;
        }
        i = j;
      }
    }
  cout << kol;
}
