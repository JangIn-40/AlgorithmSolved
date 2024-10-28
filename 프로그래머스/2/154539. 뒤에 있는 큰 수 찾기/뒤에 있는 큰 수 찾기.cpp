#include <string>
#include <vector>
#include <iostream>
#include <stack>
using namespace std;

std::vector<int> solution(const std::vector<int> numbers) 
{
    std::vector<int> answer(numbers.size(), -1);
    std::stack<int> s;

    for (int i = 0; i < numbers.size(); ++i)
    {
        while (!s.empty() && numbers[s.top()] < numbers[i]) 
        {
            answer[s.top()] = numbers[i];
            s.pop();
        }
        s.push(i);
    }

    return answer;
}