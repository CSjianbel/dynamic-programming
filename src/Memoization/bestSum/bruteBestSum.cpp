#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

class BestSum
{
public:
	vector<int> bestSum(vector<int>& numbers, int target)
	{
		if (target == 0)
			return {};	
		if (target < 0)
			return {-1};

		vector<int> shortest = {-1};

		for (int n : numbers)
		{
			vector<int> tmp = bestSum(numbers, target - n);
			if (!tmp.empty() && tmp[0] == -1)
				continue;

			tmp.push_back(n);
			if ((!shortest.empty() && shortest[0] == -1) || tmp.size() < shortest.size())
				shortest = tmp;
		}

		return shortest;
	}
};

void printVector(vector<int>& v);
vector<int> copyVector(const vector<int> v);

int main()
{
	// Tests - testcase : expected result
	// {target, [numbers] : [results]
	// no possible answer = {-1}
	// results are sorted in ascending order
	map<pair<int,vector<int>>,vector<int>> tests({
		{
			{7, {5, 3, 4, 7}},
			{7}
		},
		{
			{8, {2, 3, 5}},
			{3, 5}
		},
		{
			{8, {1, 4, 5}}, 
			{4, 4}
		},
		{
			{100, {1, 2, 5, 25}}, 
			{25, 25, 25, 25}
		},
		{
			{300, {1, 2, 5, 25, 50, 100}},
			{100, 100, 100}
		}
	});

	for (map<pair<int,vector<int>>,vector<int>>::iterator itr = tests.begin(); itr != tests.end(); itr++)
	{
		BestSum c;

		vector<int> tmp = copyVector(itr->first.second);
		cout << "Testcase: " << itr->first.first << " : "; 
		printVector(tmp);
		cout << " - " << "Expected: ";
		printVector(itr->second);
		cout << endl;

		vector<int> res = c.bestSum(tmp, itr->first.first);
		sort(res.begin(), res.end());
		cout << "Result: ";
		printVector(res);
		if (res == itr->second)
			cout << "\t:)\n\n";
		else
			cout << "\t:(\n\n";
	}

	return 0;
}

void printVector(vector<int>& v)
{
	cout << "[";
	for (vector<int>::iterator itr = v.begin(); itr != v.end(); itr++)
	{
		cout << *itr;
		if (itr + 1 != v.end())
			cout << ", ";
	}
	cout << "]";
}

vector<int> copyVector(const vector<int> v)
{
	vector<int> newVector;
	for (int i = 0; i < v.size(); i++)
		newVector.push_back(v[i]);
	return newVector;
}
