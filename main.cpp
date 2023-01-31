#include<iostream>
#include<vector>
#include<algorithm>

bool endTimeSort(std::pair<int,int>x, std::pair<int, int> y)
{
	if (x.second == y.second)
		return x.first < y.first;

	return x.second < y.second;
}

int main()
{
	int user;

	std::cin >> user;

	std::vector<std::pair<int,int>> TimeTable(user);

	for (int i = 0; i < user; ++i)
	{
		std::cin  >> TimeTable[i].first >> TimeTable[i].second;
	}

	sort(TimeTable.begin(), TimeTable.end(),endTimeSort);
	
	int count = 0;
	int conference = TimeTable[0].first;

	for (int i = 0; i < user; i++)
	{
		if (conference <= TimeTable[i].first)
		{
			count++;
			conference = TimeTable[i].second;
		}
	}

	std::cout << count;
}