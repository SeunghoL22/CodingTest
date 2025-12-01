// https://school.programmers.co.kr/learn/courses/30/lessons/77485
// 2021 Dev-Matching: 웹 백엔드 개발자(상반기) 행렬 테두리 회전하기


#include <string>
#include <vector>
#include <iostream>
#include <queue> 
#include <algorithm>

using namespace std;

/*
-2차원 벡터에 실제로 번호를 저장해야함, 그래야 여러번 회전가능
vector<vector<int>> board

필요한 기능
1. 실제로 행렬 벡터를 회전시키는 기능(1칸) -> 회전에 사용된 숫자를 벡터에 넣는다 -> sort한뒤 첫번째 원소를 return


*/

// 시계열 (우 하 좌 상)
int dr[] = {0, 1, 0,-1};
int dc[] = {1, 0,-1, 0};

int Rotate(vector<vector<int>> &board, pair<int, int> pos1, pair<int, int> pos2)
{
    queue<int> rotatingNum;
    vector<int> findMin;


    int leftB = pos1.second;
    int rightB = pos2.second;
    int upB = pos1.first;
    int downB = pos2.first;

    int length = rightB - leftB + 1;
    int height = downB - upB + 1;

    /*
    1. 총 길이 구하기
    2. 첫번째항을 먼저 넣어두고,
    모든 숫자 수집해서 벡터에 넣기(length-1 -> height-1 순으로 탐색, 어차피 길이 딱 맞게 설계했다. 종료조건 없다

    3. 같은 방식으로 한번 더 순회하면서, 이번엔 다시 넣어준다. 
    */

    // 첫째항
    int firstNum = board[pos1.first][pos1.second];
    rotatingNum.push(firstNum);
    findMin.emplace_back(firstNum);

    // 윗 1줄
    for(int i=1; i<=length-1; ++i)
    {  
        rotatingNum.push(board[pos1.first][pos1.second+i]);
        findMin.emplace_back(board[pos1.first][pos1.second+i]);
    }
    // 세로 2줄
    for(int i=1; i<=height-1; ++i)
    {
        rotatingNum.push(board[pos1.first+i][pos2.second]);
        findMin.emplace_back(board[pos1.first+i][pos2.second]);
    }
    // 아래 3줄
    for(int i=1; i<=length-1; ++i)
    {
        rotatingNum.push(board[pos2.first][pos2.second-i]);
        findMin.emplace_back(board[pos2.first][pos2.second-i]);
    }
    // 세로 2줄 (마지막 항 제외)
    for(int i=1; i<height-1; ++i)
    {
        rotatingNum.push(board[pos2.first-i][pos1.second]);
        findMin.emplace_back(board[pos2.first-i][pos1.second]);
    }


    // 다시 넣어주는 단계
    // 윗 1줄
    for(int i=1; i<=length-1; ++i)
    {  
        board[pos1.first][pos1.second+i] = rotatingNum.front();
        rotatingNum.pop();
    }
    // 세로 2줄
    for(int i=1; i<=height-1; ++i)
    {
        board[pos1.first+i][pos2.second] = rotatingNum.front();
        rotatingNum.pop();
    }
    // 아래 3줄
    for(int i=1; i<=length-1; ++i)
    {
        board[pos2.first][pos2.second-i] = rotatingNum.front();
        rotatingNum.pop();
    }
    // 세로 2줄 (마지막 항 포함)
    for(int i=1; i<=height-1; ++i)
    {
        board[pos2.first-i][pos1.second] = rotatingNum.front();
        rotatingNum.pop();
    }
    
    sort(findMin.begin(), findMin.end(), less<int>());

    return findMin[0];
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;

    vector<vector<int>> board(rows, vector<int>(columns));

    int num = 1;
    for(int r=0; r<rows; ++r)
    {
        for(int c=0; c<columns; ++c)
        {
            board[r][c] = num;
            ++num;
        }
    }

    if(num  != rows * columns + 1)
        cout << "숫자 할당 에러" <<endl;

    for(const auto& q : queries)
    {
        answer.emplace_back(Rotate(board, {q[0]-1, q[1]-1}, {q[2]-1, q[3]-1}));
    }

    return answer;
}