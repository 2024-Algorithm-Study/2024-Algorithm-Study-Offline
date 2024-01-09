#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;


int main(void) {
	char name[20];
	cin >> name;

	int len = strlen(name);

	int sum = 0;
	for (int i = 0; i < len; i++) {
		char tmp1 = 'A', tmp2 = 'Z';
		int cnt = 0;
		if (name[i] >= 'A' && name[i] <= 'N') {
			while (1) {
				if (tmp1 == name[i]) break;
				tmp1++;
				cnt++;
			}
		}
		else {
			cnt++;
			while (1) {
				if (tmp2 == name[i]) break;
				tmp2--;
				cnt++;
			}

		}

		sum += cnt;
	}


	

	cout << sum;

	return 0;
}