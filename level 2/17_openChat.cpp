#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <queue>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    unordered_map<string, string> nickname;

    //pair<uID, Enter or Leave>
    queue<pair<string,string>> order;


    // 전처리 단계
    for(string r : record)
    {
        stringstream ss(r);
        string segment;
        vector<string> tokens;

        while(getline(ss, segment, ' '))
        {
            tokens.push_back(segment);
        }

        // Enter
        if(tokens[0] == "Enter")
        {
            nickname[tokens[1]] = tokens[2];
            order.push({tokens[1], "Enter"});
        }
        // Leave
        else if(tokens[0] == "Leave")
        {
            order.push({tokens[1], "Leave"});
        }
        // Change
        else
        {
            nickname[tokens[1]] = tokens[2];
        }
    }

    // 출력 단계, Order Queue에서 꺼내면서 맵에 저장된 최신닉네임 사용
    while(!order.empty())
    {
        auto [uID, cmd] = order.front();
        order.pop();

        // Enter
        if(cmd == "Enter")
        {
            string str = nickname[uID] + "님이 들어왔습니다.";
            answer.push_back(str);
        }
        // Leave
        else
        {
            string str = nickname[uID] + "님이 나갔습니다.";
            answer.push_back(str);
        }
    }

    return answer;

    


}