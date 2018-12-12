#include <iostream>
#include <string>
#include <vector>

using namespace std;

void InsertToFrom(vector<string>& to, const vector<string>& from)
{
	to.insert(end(to), begin(from), end(from));
}

void Remove(int day, vector < vector < string>>& v, string& delet)
{
	for (int i = 0; i < v[day].size(); i++)
	{
		if (v[day][i] == delet)
		{
			v[day].erase(v[day].begin() + i);
		}
	}
}

int main()
{
	setlocale(LC_ALL, "rus");
	int kolichestvo;
	int month = 0;
	vector<vector<string>> v(31);
	string command;
	cout << "Введите количество команд: ";
	cin >> kolichestvo;
	while (kolichestvo)
	{
		cout << "Введите команду(NEXT-Следующий месяц, DUMP-Вывести, ADD-Добавить, REMOVE-Удалить): ";
		cin >> command;
		if (command == "NEXT")
		{
			++month;
			if (month > 11)
				month = 0;
			if (month == 1)
			{
				for (int i = 28; i<31; ++i)
				{
					InsertToFrom(v[27], v[i]);
				}
				v.resize(28);
			}
			else if (month == 7 || month == 0)
			{
			}
			else
			{
				if (v.size() == 30 || v.size() == 28)
				{
					v.resize(31);
				}
				else
				{
					InsertToFrom(v[29], v[30]);
					v.resize(30);
				}
			}
		}
		else
		{
			int day;
			cout << "Введите день: ";
			cin >> day;
			if (day <= v.size() && day > 0)
			{
				--day;
				if (command == "DUMP")
				{
					cout << v[day].size() << " ";
					for (auto i : v[day])
						cout << i << " ";
					cout << "\n";
				}
				else if (command == "ADD")
				{
					string task;
					cout << "Введите дело: ";
					cin >> task;
					v[day].push_back(task);
				}
				else if (command == "REMOVE")
				{
					string delet;
					cout << "Введите дело: ";
					cin >> delet;
					Remove(day, v, delet);
				}
			}
		}
		--kolichestvo;
	}
	system("pause");
	return 0;
}