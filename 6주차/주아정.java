import java.util.Arrays;

class Solution {
    static int answer = 0;
    static int count = 0;

    // 아래, 오른쪽, 위, 왼쪽
    static int[] dx = {1,0,-1,0};
    static int[] dy = {0,1,0,-1};

    static boolean[][] visited;

    public int solution(int[][] maps) {
        boolean[][] visited = new boolean[101][101];

        for (boolean[] booleans : visited) {
            Arrays.fill(booleans, false);
        }

        dfs(maps, visited, 1, 1);
        System.out.println(answer);
    }

    public static void dfs(int[][] maps, boolean[][] visited, int x, int y) {
        // 방문 처리, count++, (5, 5)일 경우 result = count
        System.out.println(visited[x][y]);
        visited[x][y] = true;
        count++;
        if (x == 5 & y == 5) answer = count;

        // 상하좌우 돌면서 재귀함수 호출 (1 && !visited && 범위를 벗어나지 않는 경우)
        for (int i = 0; i < 4; i++) {
            if (maps[dx[i] + x][dy[i] + y] != -1 && visited[dx[i] + x][dy[i]+y] && maps[x][y]==1)
                dfs(maps, visited, dx[i] + x, dy[i] + y);
        }
    }
}

