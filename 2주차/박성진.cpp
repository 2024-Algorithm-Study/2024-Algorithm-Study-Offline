#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int func(string word, int len, int scale, int indx) { //몇번 반복하는지 알려주는 함수
	int cnt = 1;
	string init_tmp;
	init_tmp = word.substr(0,  scale);

	for (int i = indx; i < len; i+= scale) { //indx위치부터 탐색.
		string tmp = word.substr(i,  scale);
		if (init_tmp == tmp) cnt++;  // 단위를 몇번 반복하는지
		else break;
	}

	return cnt;

}

int main(void) {

	string word;
	cin >> word;

	string tmp_arr={};
	string tmp_word;

	int len = word.size();  //입력값의 길이

	int min = len;

	for (int scale = 1; scale <= len; scale++) { //scale :  단위 길이 
		//단위길이를 늘려가며 검사

		int init_indx = 0;
		

		for (int indx = init_indx; indx < len; ) { //scale만큼씩 indx값 증가..
			int cnt = func(word, len, scale , indx);

			if (cnt > 1) {
				tmp_word = to_string(cnt)+ word.substr(indx,  scale);
				tmp_arr += tmp_word;
			}
			else if (cnt == 1) { 
				tmp_word = word.substr(indx,  scale);
				tmp_arr += tmp_word;
			}

			 indx += cnt * scale;
		
		}
		int tmp_len = tmp_arr.size();
		if (min > tmp_len) min = tmp_len;
		tmp_arr.erase();
	}


	cout << min;

	return 0;
}