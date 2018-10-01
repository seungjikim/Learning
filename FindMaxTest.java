class FindMaxTest {

  void from_numbers_findMax() throws Exception {
    int[] numbers = {9, 2, 4, 12, 5, 7, 9};
    mustBeTrue(FindMax.from(numbers) == 12);
  }

  void from_emptyArray_exception() throws Exception {
    int[] numbers = {};
    boolean exceptionCaused = false;
    
    try {
      FindMax.from(numbers);
    } catch (Exception e) {
      exceptionCaused = true;
    }
    
    mustBeTrue(exceptionCaused);
  }
  
  private void mustBeTrue(boolean condition) throws Exception {
    if (!condition) {
      throw new Exception("Something went wrong!");
    }
  }

  public static void main() {
    try {
      from_numbers_findMax();
      from_emptyArray_exception();
    } catch (Exception e) {
      System.out.println("Fail! " + e);
      return;
    }
    
    System.out.println("Pass!");
  }
}
