#include <iostream>
#include <string>
#include <vector>
//#include <algorithm> Äëÿ reverse

using namespace std;

bool IsPalindrom(string& s)
{
	string word;
	for (int i = s.size() - 1; i >= 0; --i)
	{
		word += s[i];
	}
	return (s == word);
}

/*bool IsPalindrom(string s)                   reverse
{
	string word = s;
	reverse(s.begin(), s.end());
	if (s == word)
		return true;
	else
		return false;
}*/

vector<string> PalindromFilter(vector<string> words, int minLength)
{
	vector<string> result;
	for (string i : words)
	{
		if (i.size() >= minLength && IsPalindrom(i))
			result.push_back(i);
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