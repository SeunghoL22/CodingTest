// 2021 KAKAO BLIND RECRUITMENT 메뉴 리뉴얼
// https://school.programmers.co.kr/learn/courses/30/lessons/72411


#include <string>
#include <vector>
#include <map>
#include <algorithm>

/*
사전 순으로 해당 조합이 몇번 주문됐는지 확인하는 map
map<string, int> combi

핵심, 그럼 나온 알파벳으로 가능한 모든 조합을 다 검사해봐야하나 ?
->그건 아니다, 두 번 이상 나온 알파벳이어야한다.

애초에 특정 주문에서 나올 수 있는 조합을 종류를 어떻게 셀거지 ?
->특정 주문에서 나올수 있는 모든 경우를 세는게 맞다.(순서는 무관)

DFS로 특정 string에서 나올 수 있는 모든 가짓수 조사
조합중인 상태를 parameter에 담아서 보내주는게 void dfs의 핵심
*/

using namespace std;

map<string, int> combi;
map<int, int> maxCount; // 조합 길이별 maxCount 저장

// n개를 뽑아 조합하는 경우를 모두 map에 등록, 조합중인 상태를 parameter에 담아서 보내주는게 void dfs의 핵심
void dfs(const string& origin, int n, int idx, string made)
{   
    // 종료 조건
    if (made.length() == n)
    {
        combi[made] +=1;
        maxCount[n] = max(maxCount[n], combi[made]);
        return;
    }

    for(int i = idx; i<origin.length(); ++i)
    {
        dfs(origin, n, i+1, made + origin[i]);
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;

    // orders 문자열 오름차순 배열
    for(auto& order:orders)
    {
        sort(order.begin(), order.end(), less<char>());
    }


    // map에 등록
    for(int c=0; c<course.size(); ++c)
    {
        for(int i=0; i<orders.size(); ++i)
        {
            // 애초에 만들 수 없는 코스 길이일 경우에는 불필요한 dfs방지
            if(orders[i].length() < course[c])
                continue;

            dfs(orders[i], course[c],0, "");
        }
    }
    
    for(const auto& [k, count] : combi)
    {
        int len = k.length();
        if(count >= 2 && count == maxCount[len]) // 가장 많이 주문된 횟수에 맞는 것만 answer에 추가
        {
            answer.emplace_back(k);
        }

    }

    return answer;
}