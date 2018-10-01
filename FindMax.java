class FindMax {
  
  static int from(int[] numbers) {
    if (numbers == null || numbers.length == 0) {
      throws new Exception("Given array 'numbers' is invalid. It must not be null or empty.");
    }
    
    int max = numbers[0];
    for (int i = 1; i < numbers.length; ++i) {
      if (max < numbers[i]) {
        max = numbers[i];
      }
    }
    return max;
  }
}
