import java.util.Arrays;
import java.util.Scanner;
 
public class Main {
	public static void main(String[] args) {
    
		Scanner scanner = new Scanner(System.in);
        
		int N = scanner.nextInt();
		int[] arr = new int[N];
        
		for (int i = 0; i < N; i++) {
			arr[i] = scanner.nextInt();
		}
        
		scanner.close();
		Arrays.sort(arr);
		System.out.print(arr[0] + " " + arr[N - 1]);
	}
}