// 2018 KAKAO BLIND RECRUITMENT [1차] 캐시
// https://school.programmers.co.kr/learn/courses/30/lessons/17680


#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

int solution(int cacheSize, vector<string> cities) {

    vector<string> cache;
    int time = 0;

    // 엣지 케이스 - cache 메모리 크기가 0
    if(cacheSize == 0)
        return 5*cities.size();

    for(string& city : cities)
    {   
        transform(city.begin(), city.end(), city.begin(), ::tolower);

        auto it = find(cache.begin(), cache.end(), city);
        

        // 캐시에서 찾음
        if (it != cache.end())
        {
            time +=1;
            
            cache.erase(it);
            cache.push_back(city);
        }
        else // 캐시에 추가, LRU 원소를 제거
        {
            cache.push_back(city);
            time +=5;

            if(cache.size() == cacheSize + 1) // 캐시가 꽉차있으면 LRU 제거
            {
                cache.erase(cache.begin());
            }
        
        }
    }

    return time;
}