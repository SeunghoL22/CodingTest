// https://school.programmers.co.kr/learn/courses/30/lessons/150366
// 표 병합

#include <string>
#include <vector>
#include <utility>
#include <sstream>
#include <algorithm>

using namespace std;

vector<vector<pair<int, int>>> parent(51, vector<pair<int, int>>(51));
vector<vector<string>> cellValue(51, vector<string>(51));
vector<vector<int>> cellRank(51, vector<int>(51, 0));

pair<int, int> findRoot(int r, int c) {
    if (parent[r][c] != make_pair(r, c)) {
        parent[r][c] = findRoot(parent[r][c].first, parent[r][c].second);
    }
    return parent[r][c];
}

void unionSets(int r1, int c1, int r2, int c2) {
    auto root1 = findRoot(r1, c1);
    auto root2 = findRoot(r2, c2);
    if (root1 == root2) return;

    int rank1 = cellRank[root1.first][root1.second];
    int rank2 = cellRank[root2.first][root2.second];

    if (rank1 < rank2) {
        swap(root1, root2);
    }

    parent[root2.first][root2.second] = root1;
    cellValue[root2.first][root2.second] = "";
    if (rank1 == rank2) {
        cellRank[root1.first][root1.second]++;
    }
}

vector<string> solution(vector<string> commands) {
    vector<string> answer;

    for (int i = 1; i <= 50; i++) {
        for (int j = 1; j <= 50; j++) {
            parent[i][j] = {i, j};
        }
    }

    for (auto& cmd : commands) {
        stringstream ss(cmd);
        vector<string> tokens;
        string token;
        while (ss >> token) {
            tokens.push_back(token);
        }

        if (tokens[0] == "UPDATE") {
            if (tokens.size() == 4) {
                int r = stoi(tokens[1]);
                int c = stoi(tokens[2]);
                string val = tokens[3];
                auto root = findRoot(r, c);
                cellValue[root.first][root.second] = val;
            } else {
                string val1 = tokens[1];
                string val2 = tokens[2];
                for (int i = 1; i <= 50; i++) {
                    for (int j = 1; j <= 50; j++) {
                        auto root = findRoot(i, j);
                        if (root.first == i && root.second == j && cellValue[i][j] == val1) {
                            cellValue[i][j] = val2;
                        }
                    }
                }
            }
        } else if (tokens[0] == "MERGE") {
            int r1 = stoi(tokens[1]);
            int c1 = stoi(tokens[2]);
            int r2 = stoi(tokens[3]);
            int c2 = stoi(tokens[4]);
            if (r1 == r2 && c1 == c2) continue;
            auto root1 = findRoot(r1, c1);
            auto root2 = findRoot(r2, c2);
            if (root1 == root2) continue;
            string val1 = cellValue[root1.first][root1.second];
            string val2 = cellValue[root2.first][root2.second];
            string newVal = "";
            if (!val1.empty() && !val2.empty()) {
                newVal = val1;
            } else if (!val1.empty()) {
                newVal = val1;
            } else if (!val2.empty()) {
                newVal = val2;
            }
            unionSets(r1, c1, r2, c2);
            auto newRoot = findRoot(r1, c1);
            cellValue[newRoot.first][newRoot.second] = newVal;
        } else if (tokens[0] == "UNMERGE") {
            int r = stoi(tokens[1]);
            int c = stoi(tokens[2]);
            auto root = findRoot(r, c);
            string val = cellValue[root.first][root.second];
            for (int i = 1; i <= 50; i++) {
                for (int j = 1; j <= 50; j++) {
                    if (findRoot(i, j) == root) {
                        parent[i][j] = {i, j};
                        cellValue[i][j] = "";
                        cellRank[i][j] = 0;
                    }
                }
            }
            cellValue[r][c] = val;
        } else if (tokens[0] == "PRINT") {
            int r = stoi(tokens[1]);
            int c = stoi(tokens[2]);
            auto root = findRoot(r, c);
            string val = cellValue[root.first][root.second];
            if (val.empty()) {
                answer.push_back("EMPTY");
            } else {
                answer.push_back(val);
            }
        }
    }

    return answer;
}