#include <string>
#include <vector>

using namespace std;

int solution(int n) 
{
    int answer = 0;
    int temp = n;
    int num{ 1 };

    while (!(temp & 0b1))
    {
        temp >>= 1;
        num <<= 1;
    }

    int count{ -2 };
    while (num)
    {
        int carry = (n & num) << 1;
        n = n ^ num;
        num = carry;
        ++count;
    }

    temp = n;
    num = 0;
    while (count)
    {
        if (!(temp & 0b1))
        {
            --count;
            num = num << 1 | 0b1;
        }
        else
        {
            num <<= 1;
        }

        temp >>= 1;
    }

    answer = n + num;
    return answer;
}
