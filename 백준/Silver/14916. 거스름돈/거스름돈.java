import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        int coinFive = n / 5;
        int remain = n - 5 * coinFive;

        while(remain % 2 != 0 && coinFive > 0){
            coinFive--;
            remain += 5;
        }

        if (remain % 2 != 0) {
            bw.write(String.valueOf(-1));
        }
        else{
            int coinTwo = remain / 2;
            int result = coinFive + coinTwo;

            bw.write(String.valueOf(result));
        }
        bw.flush();
        bw.close();
    }
}