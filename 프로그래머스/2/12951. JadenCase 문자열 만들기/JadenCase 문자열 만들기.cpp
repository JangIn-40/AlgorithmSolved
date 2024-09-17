#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    
    bool isFirst = true;
    for(char& ch : s)
    {
       if(ch == ' ')
       {
           isFirst = true;
       }
       else
       {
           if(isFirst)
           {
               ch = toupper(ch);
               isFirst = false;
           }
           else
           {
               ch = tolower(ch);
           }
       }
    }
    
    answer = s;
    return answer;
}