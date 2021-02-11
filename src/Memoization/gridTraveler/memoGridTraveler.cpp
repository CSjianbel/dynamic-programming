#include <iostream>
#include <unordered_map>
#include <map>
using namespace std;

class GridTraveler
{
public:
	int gridTraveler(int rows, int cols)
	{
        if (memo.find({rows, cols}) != memo.end())
            return memo[{rows, cols}];
		if (rows == 1 && cols == 1) 
			return 1;
		if (rows == 0 || cols == 0)
			return 0;
		return memo[{rows, cols}] = gridTraveler(rows - 1, cols) + gridTraveler(rows, cols - 1);
	}
private:
    map<pair<int,int>,int> memo;
};

int main()
{
	// Tests - testcase {rows, cols} : expected result
	map<pair<int,int>,int> tests({
		{{1, 1}, 1},
		{{2, 3}, 3},
		{{3, 2}, 3},
		{{3, 3}, 6},
		{{10, 10}, 48620}
	});

	GridTraveler g;

	for (map<pair<int,int>,int>::iterator itr = tests.begin(); itr != tests.end(); itr++)
	{
		cout << "Testcase: " << "(" << itr->first.first << ", " << itr->first.second << ")" << " - " << "Expected: " << itr->second << endl;
		int res = g.gridTraveler(itr->first.first, itr->first.second);
		cout << "Result: " << res;
		if (res == itr->second)
			cout << "\t:)\n\n";
		else
			cout << "\t:(\n\n";
	}

	return 0;
}
