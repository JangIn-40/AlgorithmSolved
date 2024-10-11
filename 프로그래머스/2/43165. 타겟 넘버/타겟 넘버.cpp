#include <string>
#include <vector>

using namespace std;

int FindTargetNumber(vector<int> numbers, int target, int index, int sum)
{
    if (index == numbers.size() && target == sum)
    {
        return 1;
    }
    else if (index == numbers.size())
    {
        return 0;
    }


    int add = FindTargetNumber(numbers, target, index + 1, sum + numbers[index]);
    int subtract = FindTargetNumber(numbers, target, index + 1, sum - numbers[index]);
    

    return add + subtract;
}

int solution(vector<int> numbers, int target) 
{
    int answer = 0;

    answer = FindTargetNumber(numbers, target, 0, 0);
    return answer;
}