// https://school.programmers.co.kr/learn/courses/30/lessons/42586
// 코딩테스트 연습 스택/큐 기능개발



#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    vector<int> day;

    for(int i=0; i<progresses.size(); ++i)
    {
        day.emplace_back(ceil((double)(100 - progresses[i]) / speeds[i]));
    }

    // 순회하며 묶음 생성
    int count = 1;
    int longDay = day[0];
    for (int i=1; i<day.size(); ++i)
    {   
        // 같거나 더 짧을 경우 -> longDay 유지, count증가
        if(day[i] <= longDay)
        {
            ++count;
        }

        // 더 긴게 나와버렸을 경우 -> longDay 갱신
        else
        {
            longDay = day[i];
            answer.push_back(count);

            // count를 다시 1로 초기화하고 시작한다
            count =1;
        }
    }

    answer.push_back(count); // 마지막 인덱스는 count를 따로 추가해줘야한다

    return answer;
}