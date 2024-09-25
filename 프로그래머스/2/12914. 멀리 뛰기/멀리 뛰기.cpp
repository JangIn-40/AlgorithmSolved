#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int CountJump(int n, unordered_map<int, int>& dp)
{
    if (dp.count(n))
    {
        return dp[n];
    }

    if (n < 0)
    {
        return 0;
    }
    else if (n == 0)
    {
        return 1;
    }

    dp[n] = (CountJump(n - 1, dp) + CountJump(n - 2, dp)) % 1234567;

    return dp[n];
}

long long solution(int n) 
{
    long long answer = 0;
    unordered_map<int, int> dp;

    answer = CountJump(n, dp);
    return answer;
}