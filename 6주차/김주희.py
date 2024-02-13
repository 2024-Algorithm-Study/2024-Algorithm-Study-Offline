from collections import deque

#상하좌우 이동 : [-1,0] [1,0] [0,-1] [0,1]
move_x = [-1, 1, 0, 0]
move_y = [0, 0, -1, 1]

#입력 : maps, 출력 : answer
def solution(maps):
    answer = 0
    n, m = len(maps), len(maps[0])
    
    # (0, 0) 을 첫 원소로 하는 queue를 생성
    movement_queue = deque([(0,0)])
    
    while movement_queue:
        x, y = movement_queue.popleft()
        
        # 상하좌우기 때문에 4로 진행
        for i in range(4):
            nx, ny = x+move_x[i], y+move_y[i]
            if (0 <= nx < n) and (0 <= ny < m) and maps[nx][ny] == 1:
                maps[nx][ny] += maps[x][y]
                movement_queue.append((nx, ny))
