// https://school.programmers.co.kr/learn/courses/30/lessons/389480
// 완전범죄

function solution(info, n, m) {
    const numItems = info.length;
    const MAX_A_TRACE = 120;
    const INF = Infinity;
    
    // DP 테이블 초기화
    let dp = new Array(MAX_A_TRACE + 1).fill(INF);
    
    
    // 시작점
    dp[0] = 0;
    
    for (const item of info)
        {
            const aCost = item[0];
            const bCost = item[1];
            
            
            for (let j=MAX_A_TRACE; j>=0; j--)
                {
                    if(dp[j] === INF)
                        {
                            continue;
                        }
                    
                    
                    // A가 훔친경우
                    if(j + aCost <= MAX_A_TRACE)
                        {
                            dp[j+aCost] = Math.min(dp[j+aCost], dp[j]);
                        }
                    
                    // B가 훔친경우도 고려
                    dp[j] = dp[j] + bCost;
                }
        }
    
    // 이제 찾아내기
    for (let j=0; j<n; j++)
        {
            if(dp[j]<m)
                {
                    return j;
                }
        }
    
    // n다 돌아도 없으면
    return -1;
    
}