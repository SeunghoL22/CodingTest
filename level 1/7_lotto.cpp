// https://school.programmers.co.kr/learn/courses/30/lessons/77484
// 2021 Dev-Matching: 웹 백엔드 개발자(상반기) 로또의 최고 순위와 최저 순위

#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;


/*
최소 등수 - win_nums과의 공통 원소의 갯수가 최소 등수이다
최대 등수 - 공통원소의 갯수에서 lottos의 0의 갯수(조커픽)의 갯수를 더해준 원소의 갯수가 최대 등수이다

-자료구조
map<원소 갯수, 등수> rank

-필요한 기능
1. win_nums에서 0의 갯수를 세는 기능
2. lottos와의 공통 원소의 갯수를 세는 기능
3. 최대 등수, 최소 등수 map에 조회해서 리턴하는 기능
*/
vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    map<int, int> rank = {{6,1}, {5,2}, {4,3}, {3,4}, {2, 5}, {1, 6}, {0, 6}};

    int cntZero = count(lottos.begin(), lottos.end(), 0);
    int cntEqual = 0;
    
    
    for(const int& n : lottos)
    {
        if (n == 0)
            continue;
            
        auto it = find(win_nums.begin(), win_nums.end(), n);
        if(it != win_nums.end())
            ++cntEqual;
    }

    answer.emplace_back(rank[cntEqual + cntZero]);
    answer.emplace_back(rank[cntEqual]);

    return answer;
}