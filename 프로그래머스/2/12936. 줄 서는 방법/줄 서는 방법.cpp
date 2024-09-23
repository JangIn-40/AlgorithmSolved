#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long Factorial(int n)
{
    long long result = 1;
    for (int i = 2; i <= n; ++i)
    {
        result *= i;
    }

    return result;
}

vector<int> solution(int n, long long k) 
{
    vector<int> answer;
    vector<int> numbers;

    for (int i = 1; i <= n; i++) 
    {
        numbers.push_back(i);
    }

    k--;
    for (int i = n; i >= 1; i--) 
    {
        long long fact = Factorial(i - 1);
        int index = k / fact;

        answer.push_back(numbers[index]);
        numbers.erase(numbers.begin() + index);

        k %= fact;
    }

    return answer;
}
