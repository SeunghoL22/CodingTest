#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    
    sort(citations.begin(), citations.end(), greater<int>());
    // 1 2 3
    // 6 5 3 1 0
    for(int i=0; i<citations.size(); ++i)
    {
        if( citations[i] >= i+1 )
        {
            answer = i+1;
        }
    }
    
    
    return answer;
}