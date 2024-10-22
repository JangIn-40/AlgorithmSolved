#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
#include <unordered_map>
using namespace std;

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    stack<string> stk;
    unordered_map<string, int> mp;
    vector<pair<int, string>> arr;

    for (int i = 0; i < plans.size(); i++) 
    {
        string s = plans[i][0];
        int startTime = stoi(plans[i][1].substr(0, 2)) * 60 + stoi(plans[i][1].substr(3, 2));
        int moreTime = stoi(plans[i][2]);
        arr.push_back({ startTime,s });
        mp[s] = moreTime;
    }

    sort(arr.begin(), arr.end());

    for (int i = 0, j = 0; i <= 1440; i++)
    {
        if (i == arr[j].first) 
        {
            stk.push(arr[j].second);
            j++;
        }
        if (stk.empty())
        {
            continue;
        }

        mp[stk.top()]--;

        if (mp[stk.top()] == 0) 
        {
            answer.push_back(stk.top());
            stk.pop();
        }
        if (j == arr.size())
        {
            break;
        }
    }
    while (!stk.empty())
    {
        answer.push_back(stk.top());
        stk.pop();
    }

    return answer;
}