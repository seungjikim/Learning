/*"OOXXOXXOOO"와 같은 OX퀴즈의 결과가 있다. O는 문제를 맞은 것이고, X는 문제를 틀린 것이다. 문제를 맞은 경우 그 문제의 점수는 그 문제까지 연속된 O의 개수가 된다. 예를 들어, 10번 문제의 점수는 3이 된다.

"OOXXOXXOOO"의 점수는 1+2+0+0+1+0+0+1+2+3 = 10점이다.

OX퀴즈의 결과가 주어졌을 때, 점수를 구하는 프로그램을 작성하시오
*/
import java.util.Scanner;

public class b8958 {
	public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	int N = sc.nextInt();
	String[] arrays = new String[80];
	int count = 0;
	int[] sum = new int[N];
	String text;
	
	for(int i = 0; i<N; i++) {
		text = sc.next();
		
		for(int j = 0; j<text.length(); j++) {
			
			arrays[j] =text.substring(j,j+1);
			
			if(j==0) {
				if(arrays[0].equals("O")) {
					++sum[i];
				}
				else {
					count = 0;
				}
			}
			else {
				
			   if(arrays[j].equals("O")&&arrays[j-1].equals("X")) {
				   count++;
				   ++sum[i];
			}
			   else if(arrays[j].equals(arrays[j-1])&&arrays[j].equals("O")) {
				   count++;
				   sum[i]+=count;
			}
			   else {
				count = 0;
			}
		}
	
	}	

}
	for(int j = 0; j<N; j++) {
		System.out.println(sum[j]);
	}
}
}
