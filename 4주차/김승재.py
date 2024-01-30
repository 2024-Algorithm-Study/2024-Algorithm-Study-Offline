from itertools import product

def solution(word):
    answer = 0
    vocab = ['A', 'E', 'I', 'O', 'U']
    every = [] # 단어의 모든 경우의수를 담을 리스트
    
    # 1자리부터 5자리 : 총 5번
    for i in range(1, 6):
        # 중복 순열 메소드 : product
        possible = list(product(vocab, repeat = i))
        # 문자열로 처리 후 every에 담는 과정
        for j in possible:
            push = ""
            for k in j:
                push += k
            every.append(push)
    # 내장 함수 sort()로 사전 정렬
    every.sort()
    
    for index, wd in enumerate(every):
        if wd == word:
            return index+1