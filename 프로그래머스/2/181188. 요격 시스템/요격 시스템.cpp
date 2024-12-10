#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> targets) 
{
    int answer = 0;

    sort(targets.begin(), targets.end(), [](vector<int>& a, vector<int>& b) {
        return a[1] < b[1];
    });

    int currentShot = targets[0][0];
    
    for(const auto& target : targets)
    {
        if(target[0] >= currentShot)
        {
            currentShot = target[1];
            ++answer;
        }
    }

    return answer;
}