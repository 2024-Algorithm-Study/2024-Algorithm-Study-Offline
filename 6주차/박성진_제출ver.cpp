#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>    
using namespace std;

int dx[] = { 0, 0, -1, +1 };      //상하좌우
int dy[] = { -1, +1, 0, 0 };

int solution(vector<vector<int> > maps)     //BFS로 접근..
{
    int answer = 0;
    int n = maps.size();
    int m = maps[0].size();
    vector< vector<bool>> isVisited(n, vector<bool>(m, false));

    queue <pair <int, int>> q;
    q.push(make_pair(0, 0));        // 초기 좌표 (0,0) 삽입
    isVisited[0][0] = true;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        if (y == n - 1 && x == m - 1) break;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < m && ny >= 0 && ny < n) {        //내부에 존재할 때..
                if (isVisited[ny][nx] == false && maps[ny][nx] == 1) {
                    maps[ny][nx] = maps[y][x] + 1;
                    isVisited[ny][nx] = true;
                    q.push(make_pair(nx, ny));
                }

            }

        }



    }

    if (isVisited[n - 1][m - 1] == true) answer = maps[n - 1][m - 1];
    else answer = -1;

    return answer;
}
