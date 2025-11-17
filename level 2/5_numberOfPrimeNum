/// https://school.programmers.co.kr/learn/courses/30/lessons/92335?language=cpp
// k진수에서 소수 개수 구하기 2022 KAKAO BLIND RECRUITMENT


#include <string>
#include <sstream>
#include <algorithm>

using namespace std;


string ConvertN(int n, const int& k)
{
    string sNum;

    // 엣지 케이스 처리, n이 0인 경우
    if (n==0) return "0";

    while(n != 0)
    {
        // mod 연산 후 나머지를 string에 추가
         sNum += (char)((n%k) + '0');

        // 몫을 갖고 계속해서 연산
        // n이 0이 될때까지 계속
        n /= k;
    }

    // std::reverse(begin, end)를 통해서 뒤집고 리턴
    reverse(sNum.begin(), sNum.end());

    return sNum;
    
}

bool IsPrime(const unsigned long long &num)
{
    // 엣지 케이스 처리, 0과 1는 소수가 아님
    if (num <= 1) return false;

    if (num == 2) return true;

    // 2를 제외한 모든 짝수는 소수가 아님
    if (num % 2 == 0) return false;

    for(unsigned long long i=3; i*i<= num; i+=2)
    {
        if(num % i == 0) return false;
    } 
        return true;
}

// 문자열 n을 k진수로 만들어서 파싱
int solution(int n, int k) {

    int answer = 0;

    // k진수로 변환 완료
    string sNum = ConvertN(n,k);

    // 문자열을 스트림에 넣음
    stringstream ss(sNum);

    // 0을 기준으로 문자열 파싱해서 stoull해서 isPrime
    string tent;
    while(getline(ss,tent,'0'))
    {
        // "00"이 연속으로 나올 경우 빈 문자열이 파싱됨
        if(tent.empty()) continue;
        else
        {
            // 파싱된 숫자가 소수인지 판별
            if(IsPrime(stoull(tent)))
                ++answer;
        }
    }
    return answer;
}