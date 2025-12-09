// https://school.programmers.co.kr/learn/courses/30/lessons/12906
// 같은 숫자는 싫어 . 스택 큐

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;

    unique_copy(arr.begin(), arr.end(), back_inserter(answer));

    return answer;
}