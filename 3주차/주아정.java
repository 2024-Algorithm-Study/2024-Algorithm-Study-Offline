import java.util.Queue;
import java.util.LinkedList;

class Solution {
    public int solution(int bridge_length, int weight, int[] truck_weights) {
        Queue<Integer> queue = new LinkedList<>();
        int truck, truck_count;
        int count=0;
        
        // 한 번에 건널 수 있는 트럭 큐에 넣기
        for (int i=0; i<truck_weights.length; i++) {
            truck = truck_weights[i];
            truck_count = 1;
            
            while (true) {
                if (i != truck_weights.length-1 && truck + truck_weights[i+1] <= weight && truck_count +1 <= bridge_length) {
                    truck += truck_weights[i+1];
                    truck_count++;
                    i++;
                } else {
                    queue.offer(bridge_length + (truck_count !=1 ? truck_count : 0));
                    break;
                }
            }
        }
        
        for (int i=0; i<queue.size(); i++) {
            if (queue.size() == 1) {
                count = bridge_length + 1;
                break;
            } else {
                count += queue.poll();
            }
        }
    }
}
