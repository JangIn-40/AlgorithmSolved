#include <string>
#include <vector>

using namespace std;

string solution(int n) 
{
    string answer = "";

    while (n)
    {
        answer = string(1, n % 3 + '0') + answer;
        n /= 3;
    }

    while (answer.find('0') != answer.npos)
    {
        for (int i = 1; i < answer.size(); ++i)
        {
            if (answer[i] == '0')
            {
                answer[i] = '4';
                --answer[i - 1];
                if (answer[i - 1] == '3')
                {
                    --answer[i - 1];
                }
            }
        }

        if (answer[0] == '0')
        {
            answer = answer.substr(1);
        }
    }

    return answer;
}
