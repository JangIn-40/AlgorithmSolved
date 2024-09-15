#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int solution(vector<int> arr) 
{
    int answer = 0;

    if (arr.size() == 1)
    {
        return arr[0];
    }
    
    answer = arr[0] * arr[1] / gcd(arr[0], arr[1]);

    for (int i = 2; i < arr.size(); ++i)
    {
        answer = answer * arr[i] / gcd(answer, arr[i]);
    }

    return answer;
}