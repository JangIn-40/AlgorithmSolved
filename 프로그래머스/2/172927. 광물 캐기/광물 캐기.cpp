#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> picks, vector<string> minerals) 
{
    struct taskData
    {
        int fatigue;
        int index;
        int count;
    };

    int answer = 0;
    int sumPicks{};
    for (auto& pick : picks)
    {
        sumPicks += pick;
    }
    vector<taskData> fatigue(sumPicks);
    vector<int> temp{ 1, 1, 1, 5, 1, 1, 25, 5, 1 };

    for (int j = 0; j < sumPicks; ++j)
    {
        int dia{}, iron{}, stone{};
        int i = 0;
        for (; i < 5 && i + j * 5 < minerals.size(); ++i)
        {
            if (minerals[i + j * 5] == "diamond")
            {
                ++dia;
            }
            else if (minerals[i + j * 5] == "iron")
            {
                ++iron;
            }
            else
            {
                ++stone;
            }
        }
        fatigue[j] = { dia * 25 + iron * 5 + stone * 1, j, i };
    }
    
    sort(fatigue.begin(), fatigue.end(), [](taskData a, taskData b)
        {
            if (a.fatigue == b.fatigue)
            {
                return a.count < b.count;
            }
            return a.fatigue > b.fatigue;
        });

    for (int i = 0; i < sumPicks; ++i)
    {
        int idx = fatigue[i].index;
        int k{};
        if (picks[0] != 0)
        {
            k = 0;
            --picks[0];
        }
        else if (picks[1] != 0)
        {
            k = 3;
            --picks[1];
        }
        else if (picks[2] != 0)
        {
            k = 6;
            --picks[2];
        }
        else
        {
            break;
        }

        for (int j = 0; j < 5 && idx * 5 + j < minerals.size(); ++j)
        {
            if (minerals[idx * 5 + j] == "diamond")
            {
                answer += temp[k];
            }
            else if (minerals[idx * 5 + j] == "iron")
            {
                answer += temp[k + 1];
            }
            else
            {
                answer += temp[k + 2];
            }
        }
    }

    return answer;
}