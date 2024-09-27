#include<vector>
#include <queue>
using namespace std;


int solution(vector<vector<int>> maps)
{
    int answer = 0;
    queue<pair<int, int>> wayQueue;
    vector<vector<bool>> visited(maps.size(), vector<bool>(maps[0].size(), false));
    vector<vector<int>> distance(maps.size(), vector<int>(maps[0].size(), 0));
    wayQueue.push({ 0, 0 });
    visited[0][0] = true;
    distance[0][0] = 1;

    while (!wayQueue.empty())
    {
        auto way = wayQueue.front();
        wayQueue.pop();

        int row = way.first;
        int col = way.second;

        if (row == maps.size() - 1 && col == maps[0].size() - 1)
        {
            return distance[row][col];
        }

        if (col - 1 >= 0 && !visited[row][col - 1] && maps[row][col - 1])
        {
            visited[row][col - 1] = true;
            distance[row][col - 1] = distance[row][col] + 1;
            wayQueue.push({ row, col - 1 });
        }
        if (row - 1 >= 0 && !visited[row - 1][col] && maps[row - 1][col])
        {
            visited[row - 1][col] = true;
            distance[row - 1][col] = distance[row][col] + 1;
            wayQueue.push({ row - 1, col});
        }
        if (maps[0].size() > col + 1 && !visited[row][col + 1] && maps[row][col + 1])
        {
            visited[row][col + 1] = true;
            distance[row][col + 1] = distance[row][col] + 1;
            wayQueue.push({ row, col + 1 });
        }
        if (maps.size() > row + 1 && !visited[row + 1][col] && maps[row + 1][col])
        {
            visited[row + 1][col] = true;
            distance[row + 1][col] = distance[row][col] + 1;
            wayQueue.push({ row + 1, col });
        }

    }
    
    return answer = -1;
}