#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <fstream>
#include <unordered_set>
using namespace std;

int main() {
	const string toIgnore = { ".,()" };
	unordered_set<string> bannedWords = { "i", "or", "and", "that", "the", "of", "not", "a", "if", "as", "to", "is", "us", "this"};
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
				auto found = toIgnore.find(word[i]);
				if (found == string::npos){
					newWord += tolower(word[i]);
				}
			}
			auto foundBanned = find(bannedWords.begin(), bannedWords.end(), newWord);
			if (foundBanned == bannedWords.end())
			{
				it = orderedMap.find(newWord);
				if (it == orderedMap.end()){
					orderedMap.insert({ newWord, 1 });
				}
				else
				{
					(*it).second++;
				}
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
	for (auto it = sortedMap.rbegin(); it != sortedMap.rend() && counter < 10; ++it, ++counter)
	{
		cout << (*it).first << " : " << (*it).second << endl;
	}
	return 0;
}