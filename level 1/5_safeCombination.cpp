// 넷마블 네오 채용연계형 인턴십 2026

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N; // 목표 회전수 합

    // DP 테이블 초기화 (0번 인덱스는 계산 편의상 1로 설정하거나 로직에 따라 처리)
    // N이 클 수 있으니 long long 사용 혹은 모듈러 연산 필수
    vector<long long> dp(N + 1, 0);
    long long MOD = 1000000007;

    dp[0] = 1; // 아무것도 안 돌린 상태(초기 상태)를 1가지로 봄

    for (int i = 1; i <= N; i++) {
        // 1칸부터 9칸 전의 경우의 수를 모두 더함
        for (int j = 1; j <= 9; j++) {
            if (i - j >= 0) {
                dp[i] = (dp[i] + dp[i - j]) % MOD;
            }
        }
    }

    cout << dp[N] << endl;

    return 0;
}