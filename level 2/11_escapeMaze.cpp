// https://www.acmicpc.net/problem/17090
// 백준 미로 탈출하기

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

/* DFS + DP
자료구조 :
vector<string> board BOARD 정보
vector<vector<int>> dp 2차원 DP
*/

vector<string> board;
vector<vector<int>> dp;
map<char, pair<int,int>> p = {
    {'U', {-1, 0}},
    {'R', {0, 1}},
    {'D', {1, 0}},
    {'L', {0, -1}}
     };

int N;
int M;

int dfs(int r, int c)
{
    // 종료 조건
    /*
    탈출 시 1리턴
    -1가 아닌 곳을 만났으면 그 값을 그대로 return, 0이거나 1이거나 둘중하나일것임

    둘다 해당 되지않은 미방문일경우 일단 0으로 기록해두고(훗날 같은 cycle에서 만나게되면 false(0)로 return됨)
    진행한다
    */

    if(r < 0 || c < 0 || r >= N || c >= M) return 1;
    if(dp[r][c] != -1) return dp[r][c];

    dp[r][c] = 0;

    auto [dr, dc] = p[board[r][c]];
    dp[r][c] = dfs(r+dr, c+dc);

    return dp[r][c];
}

/*
board 사이즈를 resize로 N으로 맞추고
dp사이즈를 assign해서 생성자 새로호출
*/

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    

    if(!(cin>>N>>M)) return 0;

    board.resize(N);
    dp.assign(N,vector<int>(M, -1));

    for(int i=0; i<N; ++i)
    {
        cin>>board[i];
    }

    int cnt = 0;

    for(int r=0; r<N; ++r)
    {
        for(int c=0; c<M; ++c)
        {
            if(dfs(r,c) == 1)
                ++cnt;
        }
    }

    cout<<cnt<<endl;


    
}