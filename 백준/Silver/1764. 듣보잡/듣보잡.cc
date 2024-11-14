#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>

int main()
{
    int countNoHearing, countNoSeeing;
    std::cin >> countNoHearing >> countNoSeeing;
    
    std::unordered_set<std::string> usNoHearingList;
    
    std::string temp;
    for(int i = 0; i < countNoHearing; ++i)
    {
        std::cin >> temp;
        usNoHearingList.insert(temp);
    }
    
    std::vector<std::string> NoHearingAndNoSeeingList;
    for(int i = 0; i < countNoSeeing; ++i)
    {
        std::cin >> temp;
        if(usNoHearingList.find(temp) != usNoHearingList.end())
        {
            NoHearingAndNoSeeingList.push_back(temp);
        }
    }
    
    std::cout << NoHearingAndNoSeeingList.size() << std::endl;
    std::sort(NoHearingAndNoSeeingList.begin(), NoHearingAndNoSeeingList.end());
    for(int i = 0; i < NoHearingAndNoSeeingList.size(); ++i)
    {
        std::cout << NoHearingAndNoSeeingList[i] << std::endl;
    }
}