#include <iostream>
#include <vector>
#include <map>
using namespace std;

class CanConstruct
{
public:
    bool canConstruct(string target, vector<string>& prefixes)
    {
        if (target == "")
            return true;
        
        for (string& prefix : prefixes)
        {
            if (prefix.length() > target.length())
                continue;
            
            if (prefix == target.substr(0, prefix.length()))
                if (canConstruct(target.substr(prefix.length(), target.length()), prefixes))
                    return true;
        }

        return false;
    }

};

void printVector(vector<string>& v);
vector<string> copyVector(const vector<string> v);
void printBool(bool b);

int main(void)
{
    map<pair<string,vector<string>>,bool> tests({
        {{"abcdef", {"ab", "abc", "cd", "def", "abcd"}}, true},
        {{"skateboard", {"bo", "rd", "ate", "t", "ska", "sk", "boar"}}, false},
        {{"enterapotentpot", {"a", "p", "ent", "enter", "ot", "o", "t"}}, true},
        {
            {
                "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", 
                {"e", "ee", "eee", "eeee", "eeeee", "eeeeee", "eeeeeee"}
            }, false
        }
    });

    for (map<pair<string,vector<string>>,bool>::iterator it = tests.begin(); it != tests.end(); it++)
    {
        CanConstruct c;

        vector<string> tmp = copyVector(it->first.second);
        cout << "Testcase: " << it->first.first << " : ";
        printVector(tmp);
        cout << " - Expected: ";
        printBool(it->second);
        cout << "\nResult: ";
        bool res = c.canConstruct(it->first.first, tmp);
        printBool(res);
        cout << (res == it->second ? "\t:)\n\n" : "\t:(\n\n");
    }

    return 0;
}

void printVector(vector<string>& v)
{
	cout << "[";
	for (vector<string>::iterator itr = v.begin(); itr != v.end(); itr++)
	{
		cout << *itr;
		if (itr + 1 != v.end())
			cout << ", ";
	}
	cout << "]";
}

vector<string> copyVector(const vector<string> v)
{
	vector<string> newVector;
	for (int i = 0; i < v.size(); i++)
		newVector.push_back(v[i]);
	return newVector;
}

void printBool(bool b)
{
    cout << (b ? "true" : "false");
}
