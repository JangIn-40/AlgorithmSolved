#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

vector<int> solution(int n, vector<string> words) 
{
    vector<int> answer;
    unordered_map<string, int> wordCount;

    for (int i = 0; i < words.size(); ++i)
    {
        if (i > 0 && words[i - 1][words[i - 1].size() - 1] != words[i][0])
        {
            answer.emplace_back(i % n + 1);
            answer.emplace_back(i / n + 1);
            break;
        }

        if (++wordCount[words[i]] > 1)
        {
            answer.emplace_back(i % n + 1);
            answer.emplace_back(i / n + 1);
            break;
        }
    }

    if (answer.empty())
    {
        answer.emplace_back(0);
        answer.emplace_back(0);
    }

    return answer;
}