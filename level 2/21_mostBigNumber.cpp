// https://school.programmers.co.kr/learn/courses/30/lessons/42746
// 가장 큰 수

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> strNum;

    for(const int& n : numbers)
    {
        strNum.push_back(to_string(n));
    }

    sort(strNum.begin(), strNum.end(), [](const string& a, const string& b){
        return a + b > b + a;
    });
    
    for(const string& str : strNum)
    {
        answer+=str;
    }

    if (answer[0] == '0')
        return "0";

    return answer;
}