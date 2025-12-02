#include <string>
#include <vector>
#include <map>

using namespace std;

/*



*/

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    map<char, int> type;
    
    for(int i=0; i<survey.size(); ++i)
    {
        int sc = choices[i];
        if (sc == 4)
            continue;
        else if (sc > 4) // 뒷 부분
        {
            int score = sc-4;
            type[survey[i][1]] += score;
        }
        else if (sc < 4) // 앞 부분
        {
            int score = 4-sc;
            type[survey[i][0]] += score;
        }
    }

    if (type['R']>=type['T'])
        answer+='R';
    else answer+='T';

    if (type['C']>=type['F'])
        answer+='C';
    else answer+='F';

    if (type['J']>=type['M'])
        answer+='J';
    else answer+='M';

    if (type['A']>=type['N'])
        answer+='A';
    else answer+='N';

    return answer;

}