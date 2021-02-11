#include <iostream>
#include <vector>
#include <map>
using namespace std;

class CanSum
{
public:
	bool canSum(vector<int>& numbers, int target)
	{
		if (target == 0)
			return true;
		if (target < 0)
			return false;

		for (int n : numbers)
			if (canSum(numbers, target - n))
				return true;
		return false;
	}
};

void printVector(vector<int>& v);
vector<int> copyVector(const vector<int> v);

int main()
{
	// Tests - testcase : expected result
	// {target, [numbers]} : bool
	map<pair<int,vector<int>>, bool> tests({
		{{7, {2, 3}}, true},
		{{7, {5, 3, 4, 7}}, true},
		{{7, {2, 4}}, false},
		{{8, {2, 3, 5}}, true},
		{{300, {7, 14}}, false}
	});

	for (map<pair<int,vector<int>>, bool>::iterator itr = tests.begin(); itr != tests.end(); itr++)
	{
		CanSum c;

		vector<int> tmp = copyVector(itr->first.second);
		cout << "Testcase: " << itr->first.first << " : "; 
		printVector(tmp);
		cout << " - " << "Expected: " << itr->second << endl;

		int res = c.canSum(tmp, itr->first.first);
		cout << "Result: " << res;
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
