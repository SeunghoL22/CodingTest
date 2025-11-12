// 2020 KAKAO BLIND RECRUITMENT 문자열 압축
// https://school.programmers.co.kr/learn/courses/30/lessons/60057


#include <string>
#include <vector>

using namespace std;

int solution(string s) 
{
    int n = s.length();
    int minLength = n;
    
    // 엣지 케이스 처리
    
    // 완전탐색으로 압축 길이 탐색 (단 n/2 까지만 탐색해서 최적화)
    for (int unitSize = 1; unitSize<= n/2; ++unitSize)
    {
        int i =0;
        string compressed; // 압축된 문자열
        
        
        // 첫번째 while 문으로 압축 문자열을 정하고 count(반복횟수)를 센다 (i로 문자열 인덱스 관리)
        while(i<n)
        {
            string current = s.substr(i, unitSize);
            int count = 1;
            i+= unitSize; // 압축 문자열만큼 인덱스 증가
            
            // 내부 while에서 이미 정해진 문자열로 압축
            // 하나의 idxChecker를 공유한다, 끝에 도달하면 압축탐색 종료
            while(i<n)
            {
                string next = s.substr(i, unitSize);

                if(next == current)
                {
                    ++count;
                    i+= unitSize;
                }
                else // 압축 불가 문자열이면 인덱스 증가시키지 않고 다른 압축문자열을 탐색하러간다
                {
                    break;
                }
            }
    
            // count 횟수
            if(count > 1)
            {
                compressed += to_string(count);
            }
            compressed += current;
        }
        
        minLength = min(minLength, (int)compressed.length());
        
        

    }

    return minLength;
}