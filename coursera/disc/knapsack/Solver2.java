import java.io.*;
import java.util.List;
import java.lang.Math;
import java.util.ArrayList;

/**
 * The class <code>Solver</code> is an implementation of a greedy algorithm to solve the knapsack problem.
 *
 */
public class Solver2 {
    
    /**
     * The main class
     */
    public static void main(String[] args) {
        try {
            solve(args);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    
  /**
   * Read the instance, solve it, and print the solution in the standard output
   */
  public static void solve(String[] args) throws IOException {
    String fileName = null;
    
    // get the temp file name
    for(String arg : args){
        if(arg.startsWith("-file=")){
            fileName = arg.substring(6);
        } 
    }
    if(fileName == null)
        return;
    
    // read the lines out of the file
    List<String> lines = new ArrayList<String>();

    BufferedReader input =  new BufferedReader(new FileReader(fileName));
    try {
        String line = null;
        while (( line = input.readLine()) != null){
            lines.add(line);
        }
    }
    finally {
        input.close();
    }
    
    
    // parse the data in the file
    String[] firstLine = lines.get(0).split("\\s+");
    int n = Integer.parseInt(firstLine[0]);
    int capacity = Integer.parseInt(firstLine[1]);

    int[] values = new int[n];
    int[] weights = new int[n];

    for(int i=1; i < n+1; i++){
      String line = lines.get(i);
      String[] parts = line.split("\\s+");

      values[i-1] = Integer.parseInt(parts[0]);
      weights[i-1] = Integer.parseInt(parts[1]);
    }

    // a trivial greedy algorithm for filling the knapsack
    // it takes n in-order until the knapsack is full
    int value = 0;
    int weight = 0;
    int[] taken = new int[n];

    int[][] table = new int[n+1][capacity+1];

    // table[0,j] = 0
    for(int i=1; i <= n; ++i){
      for(int j=0; j <= capacity; ++j){
        if(weights[i-1] <= j){
          table[i][j] = Math.max(table[i-1][j],table[i-1][j-weights[i-1]] + values[i-1]);
        }else{
          table[i][j] = table[i-1][j];
        }
      }
    }

    int j = capacity;
    for(int i=n; i > 0; --i){
      if(table[i][j] == 0)
        break;

      if(table[i][j] == table[i-1][j]){
        //do nothing
      }else{
        j -= weights[i-1];
        taken[i-1] = 1;
        value += values[i-1];
      }
      
    }
            
    // prepare the solution in the specified output format
    System.out.println(value+" 1");
    for(int i=0; i < n; i++){
      System.out.print(taken[i]+" ");
    }
    System.out.println("");        
  }

}