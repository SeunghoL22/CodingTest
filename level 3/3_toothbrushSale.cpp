// 2021 Dev-Matching: 웹 백엔드 개발자(상반기) 다단계 칫솔 판매
// https://school.programmers.co.kr/learn/courses/30/lessons/77486


#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

/*
자료구조
- unordered_map<자녀, 부모> parent
- unordered_map<조직원, 인덱스 int> indexMap

*/

vector<int> solution(vector<string> enroll, vector<string> referral,
    vector<string> seller, vector<int> amount) {

    unordered_map<string, string> parent;
    unordered_map<string, int> indexMap;
    vector<int> answer(enroll.size(), 0);
    


    // 인덱스 맵, parent 맵 매핑
    for(int i=0; i<enroll.size(); ++i)
    {
        indexMap[enroll[i]] = i;
        parent[enroll[i]] = referral[i];
    }
        


    for(int i=0; i<amount.size(); ++i)
    {
        string who = seller[i];
        int currentMoney = amount[i] * 100;

        while(who != "-" && currentMoney > 0 )
        {
            int give = currentMoney / 10;
            answer[indexMap[who]] += currentMoney - give;

            currentMoney = give; // 돈 갱신
            who = parent[who]; // 부모 갱신
        }
        if (who == "-")
        {
            int give = currentMoney / 10;
            answer[indexMap[who]] += currentMoney - give;
        }
    }
    
    return answer;
}