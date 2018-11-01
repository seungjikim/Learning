import java.util.Scanner;
//한수란, 123 321 135와 같이 각 자리수값들이 등차수열을 이루는 수를 말한다.
public class Main {
	int findingHansoo(int N) {
		
		int i = 0;
		int count = 0;
		float[] array = new float[3];
		if (N<100) {
			count++;
		}
		else { 
			while(N>0) {
			array[i] = N%10;
			N/=10;
			i++;
		}
		if(array[1] == (array[0]+array[2])/2) {
			count++;
			}
		}
		return count;
			
		}
	
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int number = sc.nextInt();
		Main screeningHanSoo = new Main();
		int sum = 0;
    
		for(int i = 1; i<=number; i++) {
			sum+= screeningHanSoo.findingHansoo(i);
		}
		System.out.println(sum);
		sc.close();
	}

}
