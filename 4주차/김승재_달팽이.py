def solution(n):
    answer = []
    status = 0 # down:0, right:1, up:2
    floor = 0
    max = 0
    for i in range(1, n+1):
        max += i
        
    arr = [[] for i in range(n)]
    count = 1
    
    while count < max:
        for i in range(n):
            arr[floor].append(count)
            if status == 0:
                floor += 1
            elif status == 1:
                continue
            elif status == 2:
                floor -= 1
                
            count += 1
            
            if count == max:
                arr[floor].append(count)
                break
        n -= 1
        
        if status == 0:
            status = 1
        elif status == 1:
            status = 2
        elif status == 2:
            status = 0
    
    for i in arr:
        for j in i:
            answer.append(j)
        
    return answer