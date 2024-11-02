#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int solution(int n, int k, vector<int> enemy)
{
    int answer = 0;
    priority_queue<int> max;

    for (; answer < enemy.size(); ++answer)
    {
        if(k > 0)
        {
            max.push(enemy[answer]);    
        }

        if (k > 0 && n < enemy[answer])
        {
            n += max.top();
            max.pop();
            --k;
        }
        else if(k <= 0 && n < enemy[answer])
        {
            break;
        }

        n -= enemy[answer];
    }

    return answer;
}