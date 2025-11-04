#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> info, int n, int m) {
    int numItems = info.size();
    
    const int MAX_A_TRACE = 120;
    
    const int INF = 1e9;
    
    vector<int> dp(MAX_A_TRACE + 1, INF);
    dp[0] = 0;
    
    // DP 테이블 채우기, A든 B든 일단 훔칠수있는 경우를 잡히는 경우를 고려하지않고 채운다.
    for(int i = 0; i<numItems; ++i)
    {
        int aCost = info[i][0];
        int bCost = info[i][1];
        
        for (int j = MAX_A_TRACE; j>=0; --j)
        {
            if(dp[j] == INF)
                continue;
            
            // A가 물건을 훔침
            if (j + aCost <= MAX_A_TRACE)
            {
                dp[j + aCost] = min(dp[j + aCost], dp[j]);
            }
            
            // B가 물건을 훔침
            dp[j] = dp[j] + bCost;
        }
        
    }
    
    
    // 결과 판단
    
    int minTrace = -1;
    
    for (int j=0; j<n; ++j) // A가 잡히는 경우 배제
    {
        if(dp[j] < m) // B가 잡히지 않는 경우를 찾는다
        {
            minTrace = j;
            break;
        }
    }
    
    return minTrace;
    
}