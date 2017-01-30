#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <fstream>

using namespace std;

int main() {
	const string toIgnore = { ".,()" };
	int counter = 0;
	map<string, int> orderedMap{};
	multimap<int, string> sortedMap{};
	map<string, int>::iterator it;
	std::ifstream ifs;
	ifs.open("test.txt");
	string word;
	if (ifs.is_open())
	{
		while (ifs >> word)
		{
			string newWord;
			for (size_t i = 0; i < word.length(); i++)
			{
				size_t found = toIgnore.find(word[i]);
				if (found == string::npos)
					newWord += tolower(word[i]);
			}
			it = orderedMap.find(newWord);
			if (it == orderedMap.end()){
				orderedMap.insert(pair<string, int>(newWord, 1));
			}
			else
			{
				(*it).second++;
			}
		}
	}
	else
	{
		std::cout << "Error opening file";
	}
	for ( it = orderedMap.begin(); it != orderedMap.end(); ++it)
	{
		sortedMap.insert(pair<int, string>((*it).second, (*it).first));
	}
	for (auto it = sortedMap.rbegin(); it != sortedMap.rend(), counter < 10; ++it, ++counter)
	{
		cout << (*it).first << " : " << (*it).second << endl;
	}
	return 0;
}