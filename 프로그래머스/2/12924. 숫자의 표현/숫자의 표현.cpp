#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n)
{
    int answer = 0;

    for (int i = 1; i <= n; ++i)
    {
        int sum{};
        int j = i;
        while (sum < n)
        {
            sum += j++;
        }

        if (sum == n)
        {
            ++answer;
        }
    }

    return answer;
}
