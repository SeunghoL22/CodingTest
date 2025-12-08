// https://school.programmers.co.kr/learn/courses/30/lessons/12951
// 연습문제 JadenCase 문자열 만들기

#include <string>
#include <vector>
#include <cctype>

using namespace std;

string solution(string s) {
    string answer = "";

    /*
    어떤 기준으로 단어의 시작인지를 구분할것인가 ?
    1. 아예 첫번째인지 s[0] (엣지케이스로 처리)
    2. 앞이 ' '공백이면서 && 자기자신 char은 소문자 알파벳일것
    

    */

    
    // 엣지 케이스 처리
    answer+=toupper(s[0]);

    char lastChar = s[0];
    
    for(int idx=1; idx<s.length(); ++idx)
    {
        if (lastChar ==' ')
        {
            answer+=toupper(s[idx]);
        }
        else
        {
            answer+=tolower(s[idx]);
        }

        // 마지막 문자 갱신
        lastChar = s[idx];

    }

    return answer;
}