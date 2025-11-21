// https://school.programmers.co.kr/learn/courses/30/lessons/250121
// [PCCE 기출문제] 10번 / 데이터 분석


#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;

    map<string, int> columnIdx =
    {{"code", 0}, {"date", 1}, {"maximum", 2}, {"remain", 3}};

    int extIdx = columnIdx[ext];
    int sortIdx = columnIdx[sort_by];


    /*
    data에서 값 뽑기
    뽑는 기준
    ext가 val_ext보다 작은 데이터 수집    
    */
    for (auto& row : data)
    {
        if (row[extIdx] < val_ext)
        {
            answer.emplace_back(move(row));
        }
    }

    
    /*
    answer를 sortIdx를 기준으로 삼아서 sorting한다 
    */
   sort(answer.begin(), answer.end(), [sortIdx](const vector<int> &a, const vector<int> &b)
   { return a[sortIdx] < b[sortIdx]; } );


    return answer;
}