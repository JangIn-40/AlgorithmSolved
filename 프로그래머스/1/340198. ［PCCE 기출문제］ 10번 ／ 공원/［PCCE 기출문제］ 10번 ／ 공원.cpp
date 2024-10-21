#include <string>
#include <vector>

using namespace std;

int solution(vector<int> mats, vector<vector<string>> park) 
{
    int answer = 0;
    int max{};

    for (int i = 0; i < park.size(); ++i)
    {
        for (int j = 0; j < park[i].size(); ++j)
        {
            if (!isalpha(park[i][j][0]))
            {
                int k = j - 1, l = i - 1;
                if (k >= 0 && l >= 0 && !isalpha(park[l][k][0]))
                {
                    int m = stoi(park[l][k]);
                    bool haveAlpha{};
                    int x{}, y{};
                    for (; x < m; ++x)
                    {
                        if (isalpha(park[i][k - x][0]))
                        {
                            haveAlpha = true;
                            break;
                        }
                    }
                    for (; y < m; ++y)
                    {
                        if (isalpha(park[l - y][j][0]))
                        {
                            haveAlpha = true;
                            break;
                        }
                    }

                    if (!haveAlpha)
                    {
                        park[i][j] = to_string(m + 1);
                        if (max < m + 1)
                        {
                            max = m + 1;
                        }
                    }
                    else
                    {
                        int small = min(x, y);
                        park[i][j] = to_string(small + 1);
                    }
                }
                else
                {
                    park[i][j] = "1";
                    if (max < 1)
                    {
                        max = 1;
                    }
                }
            }
        }
    }

    bool layMat{};
    for (int i = 0; i < mats.size(); ++i)
    {
        if (mats[i] <= max && answer < mats[i])
        {
            answer = mats[i];
            layMat = true;
        }
    }
    if (!layMat)
    {
        answer = -1;
    }
    return answer;
}