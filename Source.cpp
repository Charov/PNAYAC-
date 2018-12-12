#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool IsPalindrom(string s)
{
	string word;
	for (int i = s.size() - 1; i >= 0; --i)
	{
		word += s[i];
	}
	if (s == word)
		return true;
	else
		return false;
}

vector<string> PalindromFilter(vector<string> words, int minLength)
{
	vector<string> result;
	for (string i : words)
	{
		if (i.size() >= minLength)
		{
			if (IsPalindrom(i))
				result.push_back(i);
		}
	}
	return result;
}

int main()
{
	vector<string> input = { "qwwq", "qwerty", "asdsa", "asd", "zxccxz" };
	vector<string> output;
	output = PalindromFilter(input, 4);
	for (string i : output)
	{
		cout << i << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}
