#include <iostream>
#include <string>
using namespace std;


void delete1stLetter(string s){
	for (int i = 1; i < s.length(); i++) {
    	if(s[i] == ' '){
    		cout << s[i];
    		i++;
    	}
    	else cout << s[i];
	}
	}
	
	
int main() {
    string s;
	getline(cin, s);
	if(!s.empty()){
		delete1stLetter(s);
	}
	else cout << "Your string is empty!!!";
  return 0;
}