// https://school.programmers.co.kr/learn/courses/30/lessons/92344
// 2022 KAKAO BLIND RECRUITMENT 파괴되지 않은 건물


#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;

    int N = board.size();
    int M = board[0].size();

    // Temp
    vector<vector<int>> tempBoard = vector<vector<int>>(N+1, vector<int>(M+1, 0));

    for(const vector<int>& turn : skill)
    {
        int type = turn[0];
        int degree = turn[5];

        // flag 세우기
        int r1 = turn[1];
        int c1 = turn[2];

        // 두번 째 좌표는 +1 보정한다
        int r2 = turn[3] + 1;
        int c2 = turn[4] + 1;

        // 공/수 결정
        if (type != 2)
            degree *= -1;

        // IMOS method 적용
        tempBoard[r1][c1] += degree;
        tempBoard[r2][c2] += degree;
        tempBoard[r1][c2] -= degree;
        tempBoard[r2][c1] -= degree;
    }
    
    // 계산 시작

    // row 방향
    for(int r=0; r<N+1; ++r)
    {
        for(int c=1; c<M+1; ++c)
        {
            tempBoard[r][c] += tempBoard[r][c-1];
        }
    }

    // col 방향
    for(int c=0; c<M+1; ++c)
    {
        for(int r=1; r<N+1; ++r)
        {
            tempBoard[r][c] += tempBoard[r-1][c];
        }
    }

    // temp완성, 이제 원본 board와 합치며 체력 계산
    for(int r=0; r<N; ++r)
    {
        for(int c=0; c<M; ++c)
        {
            if(board[r][c] + tempBoard[r][c] > 0)
                ++answer;
        }
    }

    return answer;
}