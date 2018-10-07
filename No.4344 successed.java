import java.util.Scanner;

public class Upperclass {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		float sum = 0.0f;
		float avg = 0.0f;
		int higher = 0;
		
		for(int i=0; i<N; i++) { 
			//처음 입력받은 N만큼의 줄을 만든다.
			int C = sc.nextInt();
			int[] scores = new int[C];
			//각 줄 당 점수의 개수를 입력받는다.
			for(int j=0; j<C; j++) {
				
				scores[j]=sc.nextInt(); 
				//각 점수를 입력받는다.
				sum += scores[j];			
			}
			avg = sum/C;
			
			for(int k=0; k<C; k++) {
				if(scores[k]>avg) {
					higher++;
				}
			}
			String s = String.format("%.3f", (float)higher/C*100);
			System.out.println(s+"%");
	}

}
}
