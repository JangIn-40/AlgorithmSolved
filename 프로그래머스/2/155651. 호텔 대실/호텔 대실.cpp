#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;

int solution(vector<vector<string>> book_time) 
{
    int answer = 0;
    vector<pair<int, int>> useTime;

    for (const auto& time : book_time)
    {
        int startTime = stoi(time[0].substr(0, 2)) * 60 + stoi(time[0].substr(3, 2));
        int endTime = stoi(time[1].substr(0, 2)) * 60 + stoi(time[1].substr(3, 2)) + 10;

        useTime.push_back({ startTime, endTime });
    }

    std::sort(useTime.begin(), useTime.end());
    vector<int> room;

    for (int i = 0, j = 0; i < 1440; ++i)
    {
        for (int k = 0; k < room.size(); ++k)
        {
            if (room[k] == i)
            {
                room.erase(room.begin() + k);
            }
        }

        while (j < useTime.size() && useTime[j].first == i)
        {
            room.push_back(useTime[j].second);
            ++j;
        }

        if (room.size() > answer)
        {
            answer = room.size();
        }
    }

    return answer;
}