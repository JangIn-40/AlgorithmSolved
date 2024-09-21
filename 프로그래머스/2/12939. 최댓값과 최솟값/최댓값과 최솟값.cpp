#include <string>
#include <vector>
#include <sstream>
#include <numeric>
#include <iostream>
using namespace std;

string solution(string s)
{
    string answer = "";
    stringstream ss(s);
    int minimum = numeric_limits<int>::max(), maximum = numeric_limits<int>::min(), num{};
    cout << minimum << " " << maximum << endl;

    while (ss >> num)
    {
        cout << num << endl;
        minimum = min(minimum, num);
        maximum = max(maximum, num);
    }

    answer = to_string(minimum) + " " + to_string(maximum);
    return answer;
}