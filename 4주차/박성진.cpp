#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>	
using namespace std;

string target_word;
//char vowel[5] = { 'A', 'E', 'I', 'O', 'U' };
string vowel = "AEIOU";
int cnt = 0;

void solution(string word) {			//재귀적으로 풀어야함..
	
	if (word.size() >=5) return;
	
	if (target_word == word) {		//target 찾았으면 return
		return;
	}


	for (int i = 0; i < 5; i++) {
				//기존 word + vowel[i]... ex) AA + A = AAA, AAEO + E = AAEOE, AAEA + A = AAEAA....
		solution(word + vowel[i]);	//새로운 word가 함수에 들어감. DFS..
		cnt++;
	}

}


int main(void) {

	cin >> target_word;
	
	solution("");
	cout << cnt;


	return 0;
}