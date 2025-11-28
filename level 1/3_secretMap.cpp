// https://school.programmers.co.kr/learn/courses/30/lessons/17681
// 2018 KAKAO BLIND RECRUITMENT[1차] 비밀지도
// 비트 연산


#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;

    for(int i=0; i<n; ++i)
    {
        // 비트 연산한 결과를 담는다
        int target = arr1[i] | arr2[i];
        string str = "";

        // 비트 연산 결과를 판별한다
        for(int j = n-1; j>=0; --j)
        {   
            // 검증 비트가 1이면
            if(target>>j & 1) str+='#';
            else str+=' ';
        }

        answer.emplace_back(str);
    }


    return answer;
}