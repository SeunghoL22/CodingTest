// https://school.programmers.co.kr/learn/courses/30/lessons/72410
// 2021 KAKAO BLIND RECRUITMENT 신규 아이디 추천


#include <string>
#include <vector>
#include <cctype>

using namespace std;

string solution(string new_id)
{
    // 1단계
    for (int i = 0; i < new_id.length(); ++i)
    {
        new_id[i] = tolower(new_id[i]);
    }

    // 2단계
    string temp2Id = "";
    for (char c : new_id)
    {
        if ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9') || (c > 'a' && c < 'z') || (c == '-') || (c == '_') || (c == '.'))
        {
            temp2Id += c;
        }
    }

    // 3단계 -> 연속점제거
    string temp3Id = "";
    for (char c : temp2Id)
    {
        if (c == '.' && !temp3Id.empty() && temp3Id.back() == '.')
            continue;
        else
        {
            temp3Id += c;
        }
    }

    // 4단계 -> 마지막 점제거
    if (!temp3Id.empty() && temp3Id.front() == '.')
        temp3Id.erase(0, 1);

    if (!temp3Id.empty() && temp3Id.back() == '.')
        temp3Id.pop_back();

    // 5단계
    if (temp3Id.empty())
        temp3Id += 'a';

    // 6단계
    string temp6Id;
    if (temp3Id.length() >= 16)
    {
        temp6Id = temp3Id.substr(0, 15);
        if (temp6Id.back() == '.')
            temp6Id.pop_back();
    }
    else
        temp6Id = temp3Id;

    // 7단계 (비어있지않은건 5단계에서 보장됨)
    if (temp6Id.length() <= 2)
    {
        char backStr = temp6Id.back();
        while (temp6Id.length() < 3)
        {
            temp6Id += backStr;
        }
    }

    return temp6Id;
}