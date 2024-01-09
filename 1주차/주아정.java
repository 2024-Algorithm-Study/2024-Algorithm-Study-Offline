import java.io.*;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

// int 배열 만들기
// 만약 값이 N보다 크다면
// 뒤로 보내기
// 뒤에서 몇 번 이동하는지 체크

class Solution {
    public int solution(String name) {
        String[] alphabet = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};
        
        List<String> alphaList = Arrays.asList(alphabet);
        
        int answer = 0; // 이동 수
        StringTokenizer st = new StringTokenizer(name);
        String alpha;
        
        while(st.hasMoreTokens()) {
            alpha = st.nextToken();
            
            // N보다 앞에 있는 알파벳이면
            if (alphaList.indexOf(alpha) < 13) {
                answer += alphaList.indexOf(alpha);
            }
            // N보다 뒤에 있는 알파벳이면
            else {
                // 알파벳 리스트 길이에서 인덱스만큼의 길이 빼기
                answer += alphaList.size() - alphaList.indexOf(alpha);
            }
            
            // length - 1이 A인 경우
            if ((name.length - 1).equals('A'))
                alpha = st.nextToken();
            // 다음 알파벳으로 이동 (마지막이 아니면)
            if (st.hasMoreToken)
                alpha += 1;
        }
        return answer;
    }
}
