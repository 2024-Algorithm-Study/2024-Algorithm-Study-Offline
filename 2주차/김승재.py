def solution(s):
    best = len(s)
    
    for i in range(1, len(s)//2 + 1):
        summarized = ""
        repeat = "" # 짜른 이전 문자열
        count = 1 # 몇회 반복 됬는지 세는 변수
        
        for j in range(0, len(s), i):
            # 반복된 경우
            if repeat == s[j:j+i]:
                count += 1
            # 반복되지 않았는데 count가 2 이상인 경우
            elif (count != 1) and (repeat != s[j:j+i]):
                summarized += str(count) + repeat
                repeat = s[j:j+i]
                count = 1
            # 반복 안되고 count가 1인 경우
            elif (count == 1) and (repeat != s[j:j+i]):
                summarized += repeat
                repeat = s[j:j+i]
                count = 1

        if s[len(s)-i :] == repeat:
            summarized += str(count+1) + repeat
        elif s[len(s)-i :] != repeat:
                summarized += repeat

        if len(summarized) < best:
            best = len(summarized)
        
    return best

print(solution('aabbaccc'))