#include <iostream>
#include <string>
#include <stack>
using namespace std;

int solution(string s)
{
    int answer = 0;
    stack<char> alphabet;

    for (const char& ch : s)
    {
        if (!alphabet.empty() && alphabet.top() == ch)
        {
            alphabet.pop();
        }
        else
        {
            alphabet.push(ch);
        }
    }

    if (alphabet.empty())
    {
        answer = 1;
    }

    return answer;
}