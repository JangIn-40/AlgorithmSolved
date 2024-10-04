#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

int solution(string word)
{
    int answer = 0;
    unordered_map<char, int> um{ {'A', 0}, {'E', 1}, {'I', 2}, {'O', 3}, {'U', 4} };
    vector<int> nums{ 781, 156, 31, 6, 1 };

    for (int i = 0; i < word.size(); ++i)
    {
        answer += um[word[i]] * nums[i] + 1;
    }

    return answer;
}
