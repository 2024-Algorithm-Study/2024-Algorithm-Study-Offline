def joystick(length, name):
    result = 0
    alphabet = ['A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T',U',V','W','X','Y','Z']
    
    if length == 3:
        names = ["AAA"]
    if length == 4:
        names = ["AAAA"]   
    
    for i in range(0, length, 1):
        for j in range(0, len(alphabet), 1):
            if alphabet[j] != name[i]:
                result += 1

        names[i] = name[i]
    
    return result


def solution(name):
    answer = 0
    length = len(name)   
    input_name = name
    
    if length == 3:
        answer = joystick(3,input_name)
    
    if length == 4:
        answer = joystick(4,input_name)

    return answer
