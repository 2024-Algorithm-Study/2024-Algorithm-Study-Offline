def solution(name):
    left, right, up, down = 0, 0, 0, 0
    index = 0
    count = 0
    
    for i in range(len(name)):
        # name[index]가 'A'인 경우
        if name[index] == 'A':
            if count == len(name):
                continue
            elif index == 0:
                if name[index+1] == 'A':
                    left += 1
                else :
                    right += 1
            else:
                if index < 0:
                    left += 1
                    index -= 1
                    continue
                else:
                    right += 1
                    index += 1
                    continue

        # name[index]가 'A'가 아닌 경우
        else:
            if ord(name[index]) - ord('A') < 13:
                up += ord(name[index]) - ord('A')
            elif ord(name[index]) - ord('A') > 13:
                down += 26 - (ord(name[index]) - ord('A'))
            else:
                up += 13
                
        if name[index : len(name) - count] == 'A' * (len(name) - count):
            return up + down + left + right
        elif index > 0 or (index == 0 and name[-1] == 'A'):
            index += 1
            right += 1
        elif index < 0 or (index == 0 and name[1] == 'A'):
            index -= 1
            left += 1

        count += 1
            
            
    return up + down + left + right

print(solution('JAZ'))