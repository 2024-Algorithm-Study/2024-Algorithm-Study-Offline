from collections import deque

def bfs(maps, x, y, row, column):
    deq = deque()
    deq.append([x, y])
    # 상 하 좌 우
    dr = [-1, 1, 0, 0]
    dc = [0, 0, -1, 1]

    maps[0][0] = 1
    
    while len(deq) > 0:           
        a, b = deq.popleft()

        # 목적지 도달했을때 출력
        if a==(row-1) and b==(column-1):
            return maps[a][b]

        for i in range(4):
            mr = a + dr[i]
            mc = b + dc[i]
            # 현재위치에서 갈수있는 경우들 큐에넣고 카운트해주기
            if (0<=mr<row) and (0<=mc<column) and (maps[mr][mc]==0):
                maps[mr][mc] = maps[a][b] + 1
                deq.append([mr, mc])
        
    # 모든 경우를 다 돌아봤는데 도달하지 못한 경우
    return -1


def solution(maps):
    
    # 카운트를 위한 작업
    for i in range(len(maps)):
        for j in range(len(maps[0])):
            if maps[i][j] == 0:
                maps[i][j] = 1
            elif maps[i][j] == 1:
                maps[i][j] = 0
    
    return bfs(maps, 0, 0, len(maps), len(maps[0]))


print(solution([[1,0,1,1,1],[1,0,1,0,1],[1,0,1,1,1],[1,1,1,0,1],[0,0,0,0,1]]))
    

