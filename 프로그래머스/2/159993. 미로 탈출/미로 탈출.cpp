#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(vector<string> maps)
{
    struct Position
    {
        int x;
        int y;
        int count;
    };

    int answer = -1;
    queue<Position> q;
    bool touchLever{};
    vector<vector<bool>> visited(maps.size(), vector<bool>(maps[0].size(), false));

    int x{}, y{};
    for (; y < maps.size(); ++y)
    {
        bool findStartLocation{};
        for (x = 0; x < maps[y].size(); ++x)
        {
            if (maps[y][x] == 'S')
            {
                findStartLocation = true;
                maps[y][x] = 'O';
                break;
            }
        }

        if (findStartLocation)
        {
            break;
        }
    }

    q.push({ x, y, 0 });
    vector<pair<int, int>> directions = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
    visited[y][x] = true;

    while (!q.empty())
    {
        Position position = q.front();

        if (maps[position.y][position.x] == 'L' && !touchLever)
        {
            touchLever = true;
            visited.assign(maps.size(), vector<bool>(maps[0].size(), false));
            while (!q.empty())
            {
                q.pop();
            }
            q.push({ position.x, position.y, position.count });
        }
        else if (maps[position.y][position.x] == 'E' && touchLever)
        {
            answer = position.count;
            break;
        }

        ++position.count;
        q.pop();

        for (const auto& dir : directions)
        {
            int newY = position.y + dir.first;
            int newX = position.x + dir.second;

            if (newY >= 0 && newY < maps.size() && newX >= 0 && newX < maps[0].size() && !visited[newY][newX] &&
                (maps[newY][newX] == 'O' || maps[newY][newX] == 'E' || maps[newY][newX] == 'L'))
            {
                visited[newY][newX] = true;
                q.push({ newX, newY, position.count });
            }
        }
    }

    return answer;
}
