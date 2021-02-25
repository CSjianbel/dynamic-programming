// UNfinishe:
#include <iostream>
#include <map>
#include <vector>
using namespace std;

class AllConstruct
{
public:
    vector<vector<string>> allConstruct(string target, vector<string> prefixes)
    {

    }
};

// Prototypes
void printVector(vector<string>& v);

template<typename T>
vector<T> copyVector(const vector<T> v);

int main(void)
{
    map<pair<string,vector<string>>,vector<vector<string>>> tests({
        {
            {"purple", {"purp", "p", "ur", "le", "purpl"}},
            {
                {"purp", "le"},
                {"p", "ur", "p", "le"}
            }
        },
        {
            {"abcdef", {"ab", "abc", "cd", "def", "abcd", "ef", "c"}},
            {
                {"ab", "cd", "ef"},
                {"ab", "c", "def"},
                {"abc", "def"},
                {"abcd", "ef"}
            }
        },
        {
            {"skateboard", {"bo", "rd", "ate", "t", "ska", "sk", "boar"}},
            {
                {}
            }
        }
        {
            {"aaaaaaaaaaaaaaaaaaaz", {"a", "aa", "aaa", "aaaaa", "aaaaaaa"}},
            {
                {}
            }
        }
    });

    // Testcase: "target" : ["t", "a", "rget"] - Expected: [[]]
    for (map<pair<string,vector<string>>,vector<vector<string>>>::iterator it = tests.begin(); it != tests.end(); it++)
    {
        AllConstruct ac;

        vector<string> tmp = copyVector(it->first.second);
        cout << "Testcase: \'" << it->first.first << "\' : ";
        printVector(ac);
        cout << " - Expected: ";
        // TODO!
        print2dVector(it->second);

        vector<vector<string>> res = ac.allConstruct(it->first.second, tmp);
        cout << "Result: ";
        print2dVector(res);
        cout << endl;
    }
}

void printVector(vector<string>& v)
{
    cout << "[";
    for (int i = 0; i < v.size();)
    {
        cout << "\'" << v[i] << "\'";
        if (i++ != v.size())
            cout << ", ";
    }
    cout << "]";
}

template<typename T>
vector<T> copyVector(const vector<T> v)
{
    vector<T> copy;
    for (T c : v) copy.push_back(c);
    return copy;
}