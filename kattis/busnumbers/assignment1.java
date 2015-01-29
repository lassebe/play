import java.util.Scanner;
import java.util.Arrays;
public class assignment1 {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int numberOfBuses = sc.nextInt();
		int [] bus = new int[numberOfBuses];
		int i=0;
		while( i < numberOfBuses){
			bus[i++] = sc.nextInt();
		}
		Arrays.sort(bus);
		StringBuilder sb = new StringBuilder();
	
		for(int j=1; j < bus.length; j++){
			if(j+1 < bus.length && (bus[j-1]+1 ==  bus[j] || bus[j-1] == Integer.MAX_VALUE) && bus[j+1] == bus[j]+1){
				bus[j]=Integer.MAX_VALUE;
			}
		}
		for(int j=0; j < bus.length; j++){
			if(j+1 < bus.length && bus[j+1] == Integer.MAX_VALUE){
				sb.append(bus[j]);
				sb.append("-");
				while(j < bus.length && bus[++j] == Integer.MAX_VALUE);
			}
			sb.append(bus[j] + " ");
			
		}

		sb.deleteCharAt(sb.length()-1);
		
		System.out.println(sb);
		
	}

}
