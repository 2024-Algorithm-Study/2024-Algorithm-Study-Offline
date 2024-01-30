#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>	
using namespace std;

int n;
vector <vector <int>>v(n, vector <int>(n, 0));		// n x n 행렬 모두 0으로 초기화

int solution(int n) {
	

	int num = 1;
	//외곽에서 직각삼각형 모양 하나씩 벗기며 안쪽으로 진행
	
	//맨 왼쪽 세로줄 채우기

	//맨 아랫줄 오른쪽으로 가며 채우기

	//대각선 위 채우기

	//위 과정을 재귀적으로

}

int main(void) {

	cin >> n;

	cout << solution(n);


	return 0;
}