// 2019 카카오 개발자 겨울 인턴십 징검다리 건너기
// https://school.programmers.co.kr/learn/courses/30/lessons/64062

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool CanCross(int peopleCount, const vector<int>& stones, int k)
{
    int skipCount = 0;

    for (int stone : stones)
    {
        if(stone < peopleCount)
        {
            ++skipCount;
            if (skipCount >= k)
                return false;
        }
 
        else // 연속으로 밟지못하는 돌의 갯수를 skipCOunt로 세는 것이기 때문에 밟을 수 있는 돌이 나오면 다시 초기화
        {
            skipCount = 0;
        }
            
    } 

    return true;

}

int solution(vector<int> stones, int k) {
    int answer = 0;

    int low = 1;
    int high = *max_element(stones.begin(), stones.end());
    while(low <= high)
    {
        int mid = (low + high) / 2;

        // 가능하면 low를 더 높여본다
        if (CanCross(mid, stones, k))
        {
            answer = mid; // 미리 answer 갱신
            low = mid + 1; // 이미 된다는걸 검증했기 때문에 mid는 포함하지않는다

        }
        else // 불가능일시 high를 낮춘다
            high = mid -1;
    }


    
    return answer;
}