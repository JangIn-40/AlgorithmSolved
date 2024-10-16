#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> wallet, vector<int> bill) {
    int answer = 0;
    int walletMax{}, walletMin{}, billMax{}, billMin{};
    
    walletMax = max(wallet[0], wallet[1]);
    walletMin = min(wallet[0], wallet[1]);
    billMax = max(bill[0], bill[1]);
    billMin = min(bill[0], bill[1]);
    
    while(billMin > walletMin || billMax > walletMax)
    {
        int temp = billMax / 2;
        billMax = max(temp, billMin);
        billMin = min(temp, billMin);
        ++answer;
    }
    
    return answer;
}