#include <string>
#include <vector>
#include <queue>
#include <limits.h>
#include <algorithm>

using namespace std;

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<int> answer;
    vector<vector<pair<int, int>>> graph(n + 1);
    vector<int> bongwoori(n + 1, 0);
    
    for(const auto& summit : summits)
    {
        bongwoori[summit] = 1;
    }
    
    for(const auto& path : paths)
    {
        int start = path[0];
        int end = path[1];
        int time = path[2];
        
        graph[start].push_back({end, time});
        graph[end].push_back({start, time});
    }

    vector<int> distance(n + 1, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for(auto& gate : gates)
    {
        pq.push({0, gate});
        distance[gate] = 0;
    }

    while(!pq.empty())
    {
        int start = pq.top().second;
        int intensity = pq.top().first;
        pq.pop();
        
        if(bongwoori[start] == 1)
        {
            continue;
        }
        
        for(const auto& node : graph[start])
        {
            int end = node.first;
            int time = node.second;
            int newIntensity = max(intensity, time);

            if(distance[end] > newIntensity)
            {
                distance[end] = newIntensity; 
                pq.push({newIntensity, end});
            }
        }
    }
    
    int minIntensity = INT_MAX;
    int place;
    sort(summits.begin(), summits.end());
    
    for(auto& summit : summits)
    {
        if(minIntensity > distance[summit])
        {
            minIntensity = distance[summit];
            place = summit;
        }
    }
    
    answer.push_back(place);
    answer.push_back(minIntensity);
    return answer;
}