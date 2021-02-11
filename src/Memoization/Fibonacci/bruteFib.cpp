#include <iostream>
#include <map>
using namespace std;

class Fib
{
public:
	int fib(int n)
	{
		if (n <= 2)
			return 1;
		return fib(n - 1) + fib(n - 2);
	}
};

int main()
{
	// Tests - testcase : expected result
	// 46th fibonacci number is the last number a signed int with 4 bytes can store in C++
	map<int,int> tests({
		{6, 8},
		{7, 13},
		{8, 21},
		{46, 1836311903}
	});

	Fib f;

	for (map<int,int>::iterator itr = tests.begin(); itr != tests.end(); itr++)
	{
		cout << "Testcase: " << itr->first << " - " << "Expected: " << itr->second << endl;
		int res = f.fib(itr->first);
		cout << "Result: " << res;
		if (res == itr->second)
			cout << "\t:)\n\n";
		else
			cout << "\t:(\n\n";
	}

	return 0;
}
