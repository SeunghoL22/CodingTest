// https://school.programmers.co.kr/learn/courses/30/lessons/81301
// 2021 카카오 채용연계형 인턴십 숫자 문자열과 영단어


#include <string>
#include <vector>

using namespace std;



int solution(string s) {
    int answer = 0;
    
    vector<string> number = {"zero", "one", "two", "three", "four", "five",
                             "six", "seven", "eight","nine"};
    
        for(int i = 0; i<=9; ++i)
        {
            while(s.find(number[i])!=string::npos)
            {
                int idx = s.find(number[i]);
                int len = number[i].length();
                s.replace(idx, len, to_string(i));
            }
        }
    
    
    answer = stoi(s);
        
    
    
    return answer;
}