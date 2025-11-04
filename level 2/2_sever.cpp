// https://school.programmers.co.kr/learn/courses/30/lessons/389479
// 서버 증설 횟수 

#include <string>
#include <vector>

using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    
    // 각 시간대(0-23시)에 현재 운영 중인 서버의 수를 저장하는 배열
    vector<int> running_servers(24, 0);
    
    // 0시부터 23시까지 순차적으로 확인
    for (int t = 0; t < 24; ++t) {
        // 1. 현재 시간 t에 필요한 서버의 수 계산
        // 문제의 설명에 따라 정수 나눗셈을 사용합니다.
        int required = players[t] / m;
        
        // 2. 현재 운영 중인 서버의 수 확인
        int available = running_servers[t];
        
        // 3. 필요한 서버보다 운영 중인 서버가 적으면 증설
        if (available < required) {
            int deficit = required - available; // 부족한 서버의 수
            
            // 4. 총 증설 횟수에 부족한 만큼 추가
            answer += deficit;
            
            // 5. 새로 증설된 서버가 k시간 동안 운영되도록 상태 업데이트
            for (int i = 0; i < k; ++i) {
                int future_hour = t + i;
                if (future_hour < 24) {
                    running_servers[future_hour] += deficit;
                } else {
                    // 24시간을 벗어나는 경우는 고려하지 않음
                    break;
                }
            }
        }
    }
    
    return answer;
}