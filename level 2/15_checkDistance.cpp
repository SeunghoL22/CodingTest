// 2021 카카오 채용연계형 인턴십 거리두기 확인하기
// https://school.programmers.co.kr/learn/courses/30/lessons/81302

#include <string>
#include <vector>
#include <queue>

using namespace std;

/*
Board를 순회하며 P를 만날때마다 BFS 시작

-BFS 시작조건
1. P를 만났을 때 이미 bfsResult가 0이면 전부 break, continue하고 나간다.
2. bfsResult가 -1이거나 1이면 끝까지 진행한다, 도중에 0으로 바뀌지않는 이상 끝까지 탐색하게된다.

-BFS 종료조건
1. dist가 2초과일 때 큐 push 생략
2. 또 다른 P를 만났을 때, 바로 return 0

-BFS 추가조건
1. X는 벽으로 인지한다. 큐 push 생략
*/

// 시계열 상 우 하 좌
int dr[] = {-1, 0, 1, 0};
int dc[] = { 0, 1, 0,-1};

int Bfs(const vector<string> &board, int r, int c)
{
    queue<pair<int,int>> q;
    vector<vector<bool>> visited(5, vector<bool>(5, false));
    vector<vector<int>> dist(5, vector<int>(5, -1)); // -1은 미방문

    visited[r][c] = true;
    dist[r][c] = 0;

    q.push({r,c});

    while(!q.empty())
    {
        auto [r,c] = q.front();
        q.pop();

        for(int dir =0; dir<4; ++dir)
        {
            // 탐색할 좌표 계산
            int cr = r+dr[dir];
            int cc = c+dc[dir];

            // 탐색 패스 조건
            if (cr < 0 || cc < 0 || cr >= 5 || cc >= 5) continue; // 보드밖 조건
            if (board[cr][cc] == 'X') continue; // 벽 조건
            if (visited[cr][cc] == true) continue; // 방문 조건

            dist[cr][cc] = dist[r][c] +1;
            if (dist[cr][cc] > 2) continue; // 거리 조건

            if(board[cr][cc] == 'P') return 0; // 탐색 완전 종료조건

            visited[cr][cc] = true;
            q.push({cr,cc});
        }
    }

    return 1;
}

vector<int> solution(vector<vector<string>> places)
{
    vector<int> answer;

    for (const vector<string> &room : places) // 룸 결정
    {
        int bfsResult = -1; // -1은 해당 room의 미결정 상태를 나타낸다

        for (int r = 0; r < 5; ++r) // 룸 내 row
        {
                for (int c = 0; c < 5; ++c)
                {
                    const char &ch = room[r][c];
                    if (ch == 'P' && bfsResult != 0)
                    {
                        bfsResult = Bfs(room, r, c);
                    }

                    if (bfsResult == 0) break;
                }

            if(bfsResult == 0) break;
        }

        if(bfsResult == 0)
            answer.emplace_back(0);
        else // -1인 경우도 있을것임, P가 한개도 없을 경우
            answer.emplace_back(1);
    }

    return answer;
}