#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>    
using namespace std;
int n, m;
int dx[] = {0, 0, -1, +1};      //상하좌우
int dy[] = {-1, +1, 0, 0};

vector<vector <int>> maps;
vector<vector <bool>> isVisited;

bool check(int x, int y) {      // (x,y)가 maps 행렬 내에 존재 하는지 판별해주는 함수.
    if (x >= 0 && x < m && y >= 0 && y < n) return true;
    else return false;
}

int solution(vector<vector<int> > maps)     //BFS로 접근..
{
    int answer = 0;

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
               
            if (check(nx, ny) == true) {        //내부에 존재할 때..
                if (isVisited[ny][nx] == false && maps[ny][nx] == 1) {
                    maps[ny][nx] = maps[y][x] + 1;
                    isVisited[ny][nx] = true;
                    q.push(make_pair(nx, ny));
                }

            }
            
        }



    }

    if (isVisited[n - 1][m - 1] == true ) answer = maps[n - 1][m - 1];
    else answer = -1;

    return answer;
}


int main() {        //1이 통과 가능 .0이 벽.


    cin >> n >> m;

    maps.assign(n, vector<int>(m));
    isVisited.assign(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> maps[i][j];
        }
    }

    cout << solution(maps);

    return 0;
}
