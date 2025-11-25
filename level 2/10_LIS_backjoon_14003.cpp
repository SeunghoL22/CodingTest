// 가장 긴 증가하는 부분 수열 5
// https://www.acmicpc.net/problem/14003
// 플래티넘 5

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{   
    // scanf 싱크 해제
    ios::sync_with_stdio(0); cin.tie(0);

    // 미입력 버그 예외 처리
    int N;
    if(!(cin>>N)) return 0;


    vector<int> A(N);  // 원본 보존 벡터
    vector<int> lis;// lis 족보 벡터
    vector<int> indexLog(N); // idx 백트래킹 백터, 몇번째 돌로써 기능했는지를 기록해둠, 백트래킹시 계단식 내림차로 찾아나간다
    int idx = 0; // 뒤에 추가할때만 올라가는 idx를 따로 관리

    // LIS 배열 완성 O(NlogN)
    for(int i=0; i<N; ++i)
    {
        // 원본 벡터 입력
        cin >> A[i];

        // 아무것도 없거나, 더 큰 수가 들어왔다면 뒤에 추가
        if(lis.empty() || lis.back() < A[i])
        {
            lis.emplace_back(A[i]);
            indexLog[i] = idx;
            ++idx; 
        }

        else // 작거나 같은 수가 들어왔다면, num이상의 숫자가 처음으로 나오는 곳을 찾는다
        {
            auto it = lower_bound(lis.begin(), lis.end(), A[i]);
            *it = A[i];

            // index 로그 기록
            indexLog[i] = it-lis.begin(); // 방금 끼워넣은 A[i]의 idx를 기록해둔다
        }
    }

    int size = lis.size();
    int backTrackingIdx = size-1;

    vector<int> backTrack(size);

    // LIS 배열 백 트래킹
    for(int i=N-1; i>=0; --i)
    {   
        // 종료조건
        if (backTrackingIdx < 0)
            break;


        // 백트래킹 Idx와 일치할 때만 배열에 추가한다
        if(backTrackingIdx == indexLog[i])
        {
            backTrack[backTrackingIdx] = A[i];
            --backTrackingIdx; // 계단식 감소
        }
    }

    cout<< size << endl;
    for(int i=0; i<size; ++i)
    {   
        // 마지막엔 줄바꿈임
        if (i == size -1)
            cout<<backTrack[i]<<endl;
        else 
            cout<< backTrack[i] <<" ";
    }

}