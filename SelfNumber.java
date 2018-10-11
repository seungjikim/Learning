//미완성 
import java.util.Scanner;

public class Solution {
 Solution() {
  
 }
 
 void findOutSelfNumber(int x){
  
  int[] deadNum = new int[10000];
  for(int i=0; i<=10000/x; i++) {
   deadNum[i] = x*i;
  }  
 }
 public static void main(String args[]) {
  Scanner sc = new Scanner(System.in);
  int num = sc.nextInt();
  Solution finding = new Solution();
  
  int[] criteria = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,79,83,89,97};
  for(int j=0; j<24; j++) {
   finding.findOutSelfNumber(criteria[j]);
  }
  
  
 }

}
/*100까지의 소수를 구한다. 
2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,79,83,89,97, 
*/
