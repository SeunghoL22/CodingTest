// https://school.programmers.co.kr/learn/courses/30/lessons/150367
// 표현 가능한 이진트리

#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// 재귀적으로 이진트리가 유효한지 검사하는 함수
// binary_str: 포화 이진트리 형태로 만들어진 이진수 문자열
// start, end: 현재 검사할 서브트리의 시작과 끝 인덱스
bool is_valid_tree(const string& binary_str, int start, int end) {
    // 기저 사례: 노드가 하나인 경우 항상 유효함
    if (start == end) {
        return true;
    }

    // 현재 서브트리의 루트 노드 인덱스 (중앙값)
    int mid = start + (end - start) / 2;

    // 현재 루트 노드가 '0'(더미 노드)인 경우,
    // 그 자식 노드들도 모두 '0'이어야 함.
    // 만약 자식 서브트리에 '1'이 하나라도 있으면 유효하지 않은 트리임.
    if (binary_str[mid] == '0') {
        for (int i = start; i <= end; ++i) {
            if (i == mid) continue; // 자기 자신은 제외
            if (binary_str[i] == '1') {
                return false; // 더미 노드 아래에 실제 노드가 있으므로 무효
            }
        }
    }

    // 왼쪽 서브트리와 오른쪽 서브트리에 대해 재귀적으로 검사
    // 두 서브트리가 모두 유효해야 현재 트리도 유효함
    return is_valid_tree(binary_str, start, mid - 1) && is_valid_tree(binary_str, mid + 1, end);
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;

    for (long long num : numbers) {
        // 1. 숫자를 이진수 문자열로 변환
        string binary_str = "";
        long long temp_num = num;
        if (temp_num == 0) {
            binary_str = "0";
        } else {
            while (temp_num > 0) {
                binary_str += to_string(temp_num % 2);
                temp_num /= 2;
            }
            reverse(binary_str.begin(), binary_str.end());
        }

        // 2. 포화 이진트리 형태로 만들기 (길이를 2^h - 1 꼴로 맞추기)
        int len = binary_str.length();
        int full_tree_len = 1;
        while (full_tree_len < len) {
            full_tree_len = (full_tree_len + 1) * 2 - 1;
        }

        // 부족한 길이만큼 왼쪽에 '0'을 추가
        int padding_size = full_tree_len - len;
        string padded_binary_str = string(padding_size, '0') + binary_str;

        // 3. 이진트리 유효성 검사
        if (is_valid_tree(padded_binary_str, 0, padded_binary_str.length() - 1)) {
            answer.push_back(1);
        } else {
            answer.push_back(0);
        }
    }

    return answer;
}