// https://school.programmers.co.kr/learn/courses/30/lessons/340211
// [PCCP 기출문제] 3번 / 충돌위험 찾기


#include <string>
#include <vector>
#include <map>      // 딕셔너리처럼 사용하기 위해 map 헤더를 포함합니다.
#include <utility>  // 좌표를 나타내는 pair를 사용하기 위해 utility 헤더를 포함합니다.
#include <algorithm>// max 함수를 사용하기 위해 algorithm 헤더를 포함합니다.

using namespace std;

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    int answer = 0;

    // --- 1단계: 정보 정리하기 (포인트 번호를 좌표로 쉽게 변환) ---
    // 포인트 번호(key)에 좌표(value)를 매핑하는 map을 생성합니다.
    map<int, pair<int, int>> point_coords;
    for (int i = 0; i < points.size(); ++i) {
        point_coords[i + 1] = {points[i][0], points[i][1]};
    }

    // --- 2단계: 각 로봇의 전체 이동 경로 미리 계산하기 ---
    vector<vector<pair<int, int>>> all_robot_paths;
    int max_time = 0;

    for (const auto& robot_route : routes) {
        // 한 로봇의 전체 경로를 저장할 벡터
        vector<pair<int, int>> full_path;
        
        // 첫 시작 위치를 경로에 추가
        int start_point_num = robot_route[0];
        pair<int, int> current_pos = point_coords[start_point_num];
        full_path.push_back(current_pos);

        // 경로의 두 번째 포인트부터 순회하며 경로 조각들을 이어 붙임
        for (int i = 0; i < robot_route.size() - 1; ++i) {
            pair<int, int> start_point = point_coords[robot_route[i]];
            pair<int, int> end_point = point_coords[robot_route[i+1]];
            
            current_pos = start_point;

            // 세로(r) 이동 먼저 (first가 r 좌표)
            while (current_pos.first != end_point.first) {
                if (current_pos.first < end_point.first) {
                    current_pos.first++;
                } else {
                    current_pos.first--;
                }
                full_path.push_back(current_pos);
            }

            // 가로(c) 이동 나중 (second가 c 좌표)
            while (current_pos.second != end_point.second) {
                if (current_pos.second < end_point.second) {
                    current_pos.second++;
                } else {
                    current_pos.second--;
                }
                full_path.push_back(current_pos);
            }
        }
        
        all_robot_paths.push_back(full_path);
        
        // 시뮬레이션 종료 시간을 정하기 위해 가장 긴 경로의 길이를 기록
        // C++에서는 size()가 unsigned 타입이므로 int로 형변환 해주는 것이 안전합니다.
        max_time = max(max_time, (int)full_path.size());
    }

    // --- 3단계: 시간에 따라 시뮬레이션하며 충돌 감지하기 ---
    // 0초부터 마지막 로봇이 운행을 마칠 때까지 시간을 1초씩 증가
    for (int t = 0; t < max_time; ++t) {
        // 해당 시간에 각 좌표에 몇 대의 로봇이 있는지 저장할 map
        map<pair<int, int>, int> location_counts;
        
        for (const auto& robot_path : all_robot_paths) {
            // 현재 시간 t가 로봇의 전체 경로 길이보다 짧다면, 아직 운행 중
            if (t < robot_path.size()) {
                // 해당 위치의 로봇 수를 1 증가시킴
                location_counts[robot_path[t]]++;
            }
        }
        
        // map을 순회하며 2대 이상 모인 곳(충돌 위험)이 몇 군데인지 확인
        for (const auto& pair : location_counts) {
            if (pair.second > 1) { // pair.second는 해당 좌표의 로봇 수
                answer++;
            }
        }
    }
    
    return answer;
}