// https://school.programmers.co.kr/learn/courses/30/lessons/86052
// 월간 코드 챌린지 시즌3 빛의 경로 사이클


#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

bool visited[500][500][4];

// 상 우 하 좌, 시계방향
int dr[] = {-1, 0, 1, 0};
int dc[] = { 0, 1, 0,-1};


vector<int> solution(vector<string> grid) {

    memset(visited, false, sizeof(visited));

    vector<int> answer;

    int rSize = grid.size();
    int cSize = grid[0].length();
    
    /*
    미 방문한곳이면 gird를 체크해서 방향에맞게 따라가며 cnt를 체크해본다
    언제까지 ? visited == true인곳이 나올때까지
    찾으면 ? cnt를 answer에 추가

    answer배열을 오름차순 배열하는 것은 마지막에 sort로 해결
    */

    // 도넛형 cycle, 완전탐색 while 사용
    for(int r=0; r<rSize; ++r)
    {
        for(int c=0; c<cSize; ++c)
        {   
            for(int dir =0; dir<4; ++dir)
            {       
                // 이미 방문한 곳
                if(visited[r][c][dir] == true)
                    continue;

                // 현재 사이클에서만 사용할 임시 방향 변수
                int cr, cc, cdir;
                cr= r;
                cc= c;
                cdir = dir;

                // 새로 방문한 곳, cycle 탐색 시작
                int cnt = 0;

                // 재방문일 경우 입구컷
                while(visited[cr][cc][cdir] == false)
                {   
                    // 방문도장
                    visited[cr][cc][cdir] = true;
                    ++cnt;

                    // lane의 방향에 따라 dir 수정
                    char SLR = grid[cr][cc];
                    if(SLR == 'L') cdir = (cdir + 3)%4;
                    if(SLR == 'R') cdir = (cdir + 1)%4;

                    // 방향을 수정했으니 이제 직진이라고 생각하고 처리하면 된다
                    cr=(cr + dr[cdir] + rSize)%rSize;
                    cc=(cc + dc[cdir] + cSize)%cSize;

                }

                answer.emplace_back(cnt);

            }
        }
    }

    sort(answer.begin(), answer.end());

    return answer;
}