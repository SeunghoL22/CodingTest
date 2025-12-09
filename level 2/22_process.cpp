// 코딩테스트 연습 스택/큐 프로세스
// https://school.programmers.co.kr/learn/courses/30/lessons/42587


#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location)
{
    /*
    -자료구조
    queue<pair<중요도, 초기 location(Idx)>>
    priority_queue<중요도>
    */
    queue<pair<int, int>> q;
    priority_queue<int> pq;

    for (int i = 0; i < priorities.size(); ++i)
    {
        q.push({priorities[i], i});
        pq.push(priorities[i]);
    }

    int processCount = 0; // 프로세스 실행 순서

    while (!q.empty())
    {
        int theNum = pq.top();

        auto [prior, idx] = q.front();

        if (prior != theNum) // 그 중요도가 아니면 뒤로 보냄
        {
            q.pop();
            q.push({prior, idx});
        }
        else // 이번에 처리할 그 중요도를 찾음
        {
            q.pop();
            pq.pop();
            ++processCount;

            if (idx == location) // 처리할건데 만약 이게 우리가 찾던 녀석이라면 바로 return
            {
                return processCount;
            }
        }

        
    }

    return -1; // 정상적이라면 이 return문을 방문하지않음
}

#if 0 // while을 두개 쓰기 때문에 좀 아쉬움, found를 쓴다는 점은 마음에 들지만

int solution(vector<int> priorities, int location)
{
    int answer = 0;

    /*
    -자료구조
    queue<pair<중요도, 초기 location(Idx)>>
    priority_queue<중요도>
    */
    queue<pair<int, int>> q;
    priority_queue<int> pq;

    for (int i = 0; i < priorities.size(); ++i)
    {
        q.push({priorities[i], i});
        pq.push(priorities[i]);
    }

    int processCount = 1; // 프로세스 실행 순서

    while (!q.empty())
    {
        int theNum = pq.top();
        pq.pop();
        bool found = false;

        while (!found)
        {
            auto [prior, idx] = q.front();
            if (prior != theNum) // 그 중요도가 아니면 뒤로 보냄
            {
                q.pop();
                q.push({prior, idx});
            }
            else // 이번에 처리할 그 중요도를 찾음
            {
                q.pop();
                found = true;

                if (idx == location) // 처리할건데 만약 이게 우리가 찾던 녀석이라면 바로 return
                {
                    return processCount;
                }
            }
        }

        ++processCount; 
    }

    return -1; // 정상적이라면 이 return문을 방문하지않음
}

#endif