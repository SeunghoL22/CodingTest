// https://school.programmers.co.kr/learn/courses/30/lessons/150370
// 코딩테스트 연습 2023 KAKAO BLIND RECRUITMENT 개인정보 수집 유효기간

#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <sstream>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;

    // <약관, 보관기간>
    unordered_map<string, int> termMap;

    stringstream ss(today);
    char dot;
    int year, month, day;

    ss>>year>>dot>>month>>dot>>day;
    int todayTime = (year * 12 * 28) + (month * 28) + day;
    

    // term 자료구조 매핑
    for(const string& str : terms)
    {
        stringstream ss(str);
        string type;
        string duration;

        ss>>type>>duration;

        int typeDuration = stoi(duration) * 28;
        
        termMap[type] = typeDuration;
    }

    // 순회하며 판단
    for(int i=0; i<privacies.size(); ++i)
    {
        int oneBaseIndex = i+1;
        stringstream ss(privacies[i]);
        
        string date;
        string type;
        getline(ss, date, ' ');
        getline(ss, type, ' ');

        ss.clear();
        ss.str(date);
        
        char dot;
        int year, month, day;
        
        ss>>year>>dot>>month>>dot>>day;

        int time = ( year * 12 * 28) + (month* 28) + day;
        int typeDuration = termMap[type];
        
        // 아직 안지났으니 패스
        if (time + typeDuration > todayTime)
        {
            continue;
        }
        else
        {
            answer.emplace_back(oneBaseIndex);
        }

    }
    

    return answer;
}