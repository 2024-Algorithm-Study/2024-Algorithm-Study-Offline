import java.io.*;
import java.util.Vector;

public class P_문자열압축 {

    // 접근
    // 1. 하나씩 압축
    // 2. 최대 자를 수 있는 문자열 수 구하기 -> 약수로 압축
    // 3. 가장 짧은 길이 return

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String st = br.readLine();
        Vector<Integer> div = new Vector<Integer>(); // 약수
        int length = st.length();
        int result = st.length();

        // 자를 수 있는 최대 수의 약수 구하기
        for (int i=1; i<length; i++) {
            if (length/i == 0) {
                div.add(i);
            }
        }

        // 가장 짧은 길이 찾기
        // 1->2>3>6
        for (int i=0; i<div.size(); i++) {
            Vector<String> v = new Vector<String>();

            // 문자열 나누기
            int split = 0; // 문자열 나누기 (시작)
            for (int j=0; j<st.length()/div.get(i)-1; j++) {
                v.add(st.substring(split, split + div.get(i)));
                split += div.get(i);
            }
            
            // 중복 제거
        }
    }
}
