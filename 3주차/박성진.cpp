#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>	
using namespace std;
#include <queue>

int solution(int bridge_length, int weight, vector<int> truck_weights) { 
	// 트럭 하나가 다리는 지나는 데에 bridge_length만큼 소요. weight는 최대 하중. vector는 트럭 무게 배열..
	int answer = 0;			//answer은 다리는 건너는 데에 소요되는 총 시간

	int truck_num = truck_weights.size();
	
	int sum = 0; // sum은 다리위에 올라가 있는 트럭의 무게 합
	
	queue <int> q;
	for (int i = 0; i < truck_num; i++)
		q.push(truck_weights[i]);

	while (!q.empty()) {
		int curr_truck_weight = q.front();
		
		sum += curr_truck_weight;
		if (sum <= weight) {			//최대 하중 초과하지 않으면..
			q.pop();

		}
		else {
			sum -= curr_truck_weight;
		}

	}







	return answer;
}

int main(void) {

	int n, w, L;				//n은 트럭의 개수, w는 다리의 길이, L은 다리의 최대하중
	cin >> n >> w >> L;

	vector <int> vector(n);

	cout << solution(w, L, vector);			


		return 0;
}