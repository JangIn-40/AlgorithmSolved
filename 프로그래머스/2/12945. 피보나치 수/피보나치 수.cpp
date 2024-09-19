#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

int Fibonacci(int n, unordered_map<int, int>& dpFibonacci)
{
    if (dpFibonacci.count(n) == 1)
    {
        return dpFibonacci[n];
    }
    else if (n == 1)
    {
        return 1;
    }
    else if (n == 0)
    {
        return 0;
    }

    dpFibonacci[n] = (Fibonacci(n - 1, dpFibonacci) + Fibonacci(n - 2, dpFibonacci)) % 1234567;

    return dpFibonacci[n];
}

int solution(int n) 
{
    int answer = 0;
    unordered_map<int, int> dpFibonacci;
    
    answer = Fibonacci(n, dpFibonacci);

    return answer;
}