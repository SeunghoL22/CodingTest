// https://school.programmers.co.kr/learn/courses/30/lessons/92341
// 주차 요금 계산

#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <sstream>
/*
올림 연산은 double로 캐스팅 후 ceil 함수 사용

자료구조 (분 단위로 환산)
1. 차량 누적 시간 map<차번호, 누적시간> totalTime  
2. 차량 입차 시간 map<차번호, 입차시간> entryTime

필요한 기능

[0,1 통합] - void PushEntry(const vector<string> &records)
0. records를 보고 entryTime에 기록하는 기능
1. records를 보고 차량의 누적시간을 계산해서 totalTime에 넣어주는 메서드

[main 메서드]
2.  totalTime에 기록된 누적시간을 보고 계산해서 answer 백터에 차례로 넣어준다.
(어차피 map을 순회하면서 넣는거라 차량번호 순서대로 기록됨)

*/

using namespace std;

//차량 누적 시간 map<차번호, 누적시간> totalTime  
map<string, int> totalTime;

//차량 입차 시간 map<차번호, 입차시간> entryTime
map<string, int> entryTime;


/* records를 보고 entryTime에 기록하는 기능
records를 보고 차량의 하루 전체 누적시간을 계산해서 totalTime에 넣어주는 메서드 */
void PushEntry(const vector<string> &records)
{
    
    for(string str : records)
    {
        string time;
        string car;
        string op;

        stringstream ss(str);
        ss >> time >> car >> op;

        //시간을 분 단위로 변경
        stringstream ss2(time);
        string hour; string min;

        getline(ss2, hour, ':');
        ss2 >> min;

        int minTime = stoi(hour)*60 + stoi(min);

        // OP에 맞게 처리를 다르게함
        if (op == "IN")
        {
            entryTime[car] = minTime;
        }
        else // OUT 인 경우, 시간 누적
        {
            totalTime[car] += (minTime - entryTime[car]);

            // 입차 기록과 매칭되면 삭제
            entryTime.erase(car);
        }
    }

    // if의 기능을 for문에서 대신하긴 함, 가독성을 위해서 남겨둔다
    if(!entryTime.empty())
    {
        // OUT 기록이 없는 경우 시간 누적
        for(const auto& [car, time] : entryTime)
        {
            int oneDay = (24*60) - 1;
            totalTime[car] += (oneDay - time);
        }

        entryTime.clear();
    }
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;

    int basicTime = fees[0];
    int basicFee = fees[1];
    int unitTime = fees[2];
    int unitFee = fees[3];

    // totalTime 완성
    PushEntry(records);

    // 메인 기능 위치
    // totalTime에 기록된 누적시간을 보고 계산해서 answer 백터에 차례로 넣어준다.
    for(const auto& [car, mins] : totalTime)
    {
        // 기본 시간 아래인 경우
        if (mins<=basicTime)
            answer.emplace_back(basicFee);
        else // 기본 시간 초과인 경우
        {
            int overTime = mins - basicTime;
            int additionalFee = ceil((double)overTime / unitTime) * unitFee;

            answer.emplace_back(basicFee + additionalFee);
        }

    }


    return answer;
}