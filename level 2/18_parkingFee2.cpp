#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <sstream>

/*
map<차량번호, 입차시각> entryTime
map<차량번호, 총 주차 시간> totalTime 
-> 출차입력이 들어올때 총 주차시간을 계산해주고, entryTime에서 지워준다


기능 - 
1. 주차요금 계산 기능 5000 + ( (출차시간 - 입차시간) 단위시간  * 단위요금)
fees[0] - 기본시간
fees[1] - 기본요금
fees[2] - 단위시간
fees[3] - 단위요금

2. 차량별 입차시각

*/
using namespace std;

map<string, int> entryTime;
map<string, int> totalTime;

void PushEntry(const vector<string> &records)
{   
    int endTime = 1439; // 23:59
     
    // 하나의 커맨드에 대한 반복문
    for(string r : records)
    {
        stringstream ss(r);
        string segment;
        vector<string> tokens;
        while(getline(ss, segment, ' '))
        {
            tokens.push_back(segment);
        }

        string timeStr = tokens[0];
        int time = stoi(timeStr.substr(0,2))*60 + stoi(timeStr.substr(3,2));

        string carNum = tokens[1];
        string cmd = tokens[2];

        // IN
        if (cmd == "IN")
        {
            entryTime[carNum] = time;
        }

        // OUT
        if(cmd == "OUT")
        {
            totalTime[carNum] += time - entryTime[carNum];
            entryTime.erase(carNum);
        }
    }

    // 모든 order를 처리했는데도 남아있는 entry는 23:59 출차처리
    for(auto& [carNum, time]: entryTime)
    {
        totalTime[carNum] += endTime - time;
    }
    
    entryTime.clear() // 음 이미 다 처리했는데 굳이 clear까지 해줘야하나 싶긴함.
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;

    // 총 주차시간 totalTime을 완성해주는 메서드 호출
    PushEntry(records);

    for(const auto& [carNum, total] : totalTime)
    {   

        // 기본요금만 내는 경우
        if(total <= fees[0])
        {
            answer.push_back(fees[1]);
            continue;
        }


        // 기본시간 초과인 경우
        if(total > fees[0])
        {
            int fee = fees[1] + ceil((total) /fees[2]) * fees[3];
            answer.push_back(fee);
        }
        
    }


    return answer;
}