#include <string>
#include <iostream>
#include <stack>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char> stack;

    for (const char& ch : s)
    {
        if (ch == '(')
        {
            stack.push(ch);
        }
        else
        {
            if (stack.empty())
            {
                answer = false;
                break;
            }

            if (stack.top() != '(')
            {
                answer = false;
                break;
            }
            stack.pop();
        }
    }

    if (!stack.empty())
    {
        answer = false;
    }
    return answer;
}