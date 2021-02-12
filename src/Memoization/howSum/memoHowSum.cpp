#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <map>
using namespace std;

class HowSum
{
public:
	vector<int> howSum(vector<int>& numbers, int target)
	{
        if (memo.find(target) != memo.end())
            return memo[target];

		if (target == 0)
			return {};	
		if (target < 0)
			return {-1};

		for (int n : numbers)
		{
			vector<int> tmp = howSum(numbers, target - n);
			if (!tmp.empty() && tmp[0] == -1)
				continue;
			tmp.push_back(n);
			return memo[target] = tmp;
		}
		return memo[target] = {-1};
	}
private:
    unordered_map<int,vector<int>> memo;
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
			{7, {2, 3}}, 
			{2, 2, 3}
		},
		{
			{7, {5, 3, 4, 7}}, 
			{3, 4}
		},
		{
			{7, {2, 4}},
			{-1}
		},
		{
			{8, {2, 3, 5}}, 
			{2, 2, 2, 2}
		},
		{
			{300, {7, 14}}, 
			{-1}
		}
	});

	for (map<pair<int,vector<int>>,vector<int>>::iterator itr = tests.begin(); itr != tests.end(); itr++)
	{
		HowSum c;

		vector<int> tmp = copyVector(itr->first.second);
		cout << "Testcase: " << itr->first.first << " : "; 
		printVector(tmp);
		cout << " - " << "Expected: ";
		printVector(itr->second);
		cout << endl;

		vector<int> res = c.howSum(tmp, itr->first.first);
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
