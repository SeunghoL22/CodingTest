#include <iostream>
#include <vector>

using namespace std;

// 혹시 모를 뺄셈 실수가 있을수도 있으니, ULL이 아닌 LL로 간다
long long dp[1000001];

// DP 테이블 완성함수
void Precompute()
{
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    for(int n=4; n<=1000000; ++n)
    {
        dp[n] = (dp[n-1] + dp[n-2] + dp[n-3]) % 1000000009; 
    }

    return;
}

int main()
{

    ios::sync_with_stdio(0); cin.tie(0);

    Precompute();

    int T;
    cin >> T;

    while(T--)
    {
        int N;
        cin>>N;
        cout<<dp[N]<<'\n';
    }

    return 0;
}