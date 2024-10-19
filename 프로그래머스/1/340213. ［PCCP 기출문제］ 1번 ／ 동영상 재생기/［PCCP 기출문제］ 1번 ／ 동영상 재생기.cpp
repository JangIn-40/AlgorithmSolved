#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands)
{
    string answer = "";

    if (pos >= op_start && pos < op_end)
    {
        pos = op_end;
    }

    for (const string& str : commands)
    {
        int second{}, carry{}, minute{};
        if (str == "next")
        {
            second = stoi(pos.substr(3, 2)) + 10;
            carry = second / 60;
            second %= 60;
            minute = stoi(pos.substr(0, 2)) + carry;
        }
        else if (str == "prev")
        {
            second = stoi(pos.substr(3, 2)) - 10;
            carry = second < 0;
            if (second < 0)
            {
                second += 60;
            }
             minute = stoi(pos.substr(0, 2)) - carry;
        }


        if (!minute)
        {
            pos = "00";
        }
        else if (minute < 10)
        {
            pos = string('0' + to_string(minute));
        }
        else
        {
            pos = string(to_string(minute));
        }

        if (!second)
        {
            pos += ":00";
        }
        else if (second < 10)
        {
            pos += string(":0" + to_string(second));
        }
        else
        {
            pos += string(':' + to_string(second));
        }

        if (pos < "00:00")
        {
            pos = "00:00";
        }
        else if (pos > video_len)
        {
            pos = video_len;
        }

        if (pos >= op_start && pos < op_end)
        {
            pos = op_end;
        }
    }

    answer = pos;
    return answer;
}
