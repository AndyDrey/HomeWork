#include <iostream>
#include <string>
using namespace std;


void toUpper(string s){
	s[0] = toupper(s[0]);
	for (int i = 0; i < s.length(); i++) {
    	if(s[i] == ' '){
    		cout << s[i];
    		s[i+1] = toupper(s[i+1]);
    	}
    	else cout << s[i];
	}
	}
	
	
int main() {
    string s;
	getline(cin, s);
	if(!s.empty()){
		toUpper(s);
	}
	else cout << "Your string is empty!!!";
  return 0;
}