#include <string>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

vector<int> Dijkstra(int n, int s, const vector<vector<pair<int, int>>>& adjList)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> distance(n + 1, INT_MAX);
    distance[s] = 0;
    pq.push({0, s});
    
    while(!pq.empty())
    {
        int fee = pq.top().first;
        int start = pq.top().second;  
        pq.pop();
        
        for(const auto& node : adjList[start])
        {
            int end = node.first;
            int newFee = node.second + fee;
            
            if(distance[end] > newFee)
            {
                distance[end] = newFee;
                pq.push({newFee, end});
            }
        }
    }
    
    return distance;
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = INT_MAX;
    vector<vector<pair<int, int>>> adjList(n + 1);
    
    for(const auto& fare : fares)
    {
        int start = fare[0];
        int end = fare[1];
        int fee = fare[2];
        
        adjList[start].push_back({end, fee});
        adjList[end].push_back({start, fee});
    }
    
    auto dijkS = Dijkstra(n, s, adjList);
    auto dijkA = Dijkstra(n, a, adjList);
    auto dijkB = Dijkstra(n, b, adjList);
    
    for(int i = 1; i <= n; ++i)
    {
        if(dijkS[i] == INT_MAX || dijkA[i] == INT_MAX || dijkB[i] == INT_MAX)
        {
            continue;
        }
        
        int newFee = dijkS[i] + dijkA[i] + dijkB[i];
        answer = min(answer, newFee);
    }
    
    return answer;
}