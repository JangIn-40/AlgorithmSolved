#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies)
{
	vector<int> answer;
	stringstream ss;
	unordered_map<char, string> periodInformation;

	for (const string& str : terms)
	{
		char terms;
		int period;
		while (ss << str)
		{
			ss >> terms >> period;
		}
		ss.clear();
		
        int year = period / 12;
        int date = period % 12;
        string day = string(to_string(year)) + '0' + (date >= 10 ? string(to_string(date)) : '0' + string(to_string(date)));
        day.insert(0, 3, '0');
		periodInformation[terms] = day;
	}

    int k{};
	for (string& str: privacies)
	{
		char terms = str[str.size() - 1];
		string period = periodInformation[terms];

        int carry{ 0 };
        string temp;
        for (int i = period.size(); i >= 0; --i)
        {
            if (str[i] == '.')
            {
                if (temp > "12")
                {
                    int num = stoi(temp);
                    str[6] = num % 12 % 10 + '0';
                    str[5] = num % 12 / 10 + '0';
                    carry = num / 12;
                }
                temp.clear();
                continue;
            }

            int sum = (period[i] - '0') + (str[i] - '0') + carry;
            carry = sum / 10;
            str[i] = sum % 10 + '0';
            temp.insert(temp.begin(), str[i]);
        }
		
        ++k;
        string date = string(str.begin(), str.end() - 2);
        if (today >= date)
        {
            answer.push_back(k);
        }
	}

	return answer;
}
