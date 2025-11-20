// https://school.programmers.co.kr/learn/courses/30/lessons/340199
// [PCCE 기출문제] 9번 / 지폐 접기

#include <string>
#include <vector>
#include <algorithm>


using namespace std;

int solution(vector<int> wallet, vector<int> bill) {
    int answer =0;
    
    auto wPair = minmax(wallet[0], wallet[1]);
    int Sw = wPair.first;
    int Bw = wPair.second;
    auto bPair = minmax(bill[0], bill[1]);
    int Sb= bPair.first;
    int Bb= bPair.second;
    
    while(Sb > Sw || Bb > Bw)
    {
        if(bill[0] < bill[1])
        {
            bill[1] /= 2;
        }
        else
        {
            bill[0] /= 2;
        }
        auto p = minmax(bill[0], bill[1]);
        Sb=p.first;
        Bb=p.second;
        ++answer;
    }
    
    return answer;
}