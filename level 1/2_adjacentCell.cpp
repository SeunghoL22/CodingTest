// 이웃한 칸
// https://school.programmers.co.kr/learn/courses/30/lessons/250125

#include <string>
#include <vector>

using namespace std;

/*
board와 좌표가 주어진다 (zero-based)
해당 좌표와 인접한 4방향 블럭중 같은 색상의 개수 세기

메서드 필요도 없다

board[h][w]의 색상을 저장
4방향 탐색
-> 같은 색상이면 ++answer;
-> 아닐 경우 continue;
*/

int dh[] = {0, 1, -1, 0};
int dw[] = {1, 0, 0, -1};


int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;

    string color = board[h][w];
    int size = (int)(board.size());

    for(int i=0; i<4; ++i)
    {
        int h2 =h+dh[i];
        int w2 =w+dw[i];

        if (h2 >= size || h2 < 0 || w2 >= size || w2 < 0 )
        {
            // 보드 바깥 영역을 나타내는 경우
            continue;
        }
        else
        {
            // 같은 색상일 경우 체크
            if(board[h2][w2] == color)
            {
                ++answer;
            }
        }
    }

    return answer;
}