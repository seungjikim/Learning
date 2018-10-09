/* 숫자가 1부터 10000까지 돌게 해야함.

셀프 넘버를 만드는 과정을 거쳐서 나온 숫자를 제외한 모든 1-10000까지의 숫자 리턴.
 */
import java.util.Arrays;
public class SelfNumber {
	SelfNumber(){
		
	}
	public int findOutSelfNumber(int x) {
		int sum = 0;
		int length= (int)(Math.log(x)+1);
		for(int i=1; i<length; i++) {
			sum += x/Math.pow(10, i);
		}
		sum += x%10;
		
		return sum+x;

	}
	public static void main(String args[]) {
		
		int[] array = new int[10000];
		
		SelfNumber finder = new SelfNumber();
		for(int k=1; k<10000; k++) {
			int num = k;
		    int thisIsSelfNumber = finder.findOutSelfNumber(num);
		    array[k] = thisIsSelfNumber;
		 
	}
		for(int j=1; j<10000; j++) {
			
		int index = Arrays.binarySearch(array, j);
		if (index < 0) {
			System.out.println(j);
		}
		}
		
	}
}
