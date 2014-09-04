//import java.util.ArrayList;
//import java.util.HashMap;

public class Clustering {

	
	/**
	 * @param args
	 */
	public static void main(String[] args) {	
		Kattio io = new Kattio(System.in, System.out);
		UnionFind uf;
		int nodes = io.getInt();
		//int bits = io.getInt();
		//HashMap<Integer[],ArrayList<Integer>> viableEdges = new HashMap<Integer[],ArrayList<Integer>>();
		//int node[] = new int[bits];
		//viableEdges[node] = Generate();
		uf = new UnionFind(nodes);
		
		long s=0;
		//int iter=0;
		while(uf.getNumComponents() > 4){
			//if(uf.find(es.get(iter).u) != uf.find(es.get(iter).v)){
				//io.print("union ");
				//io.println(uf.find(es.get(iter).u) + " "+ uf.find(es.get(iter).v) + " " + es.get(iter).c);
				//uf.unify(es.get(iter).u,es.get(iter).v);
							
			//}
			//iter++;
		}
		io.println(s);
		io.close();
	}

	
	public static char[] Xor(char[] a, char[] b){
        char[] c = new char[a.length];
        for (int i = 0; i < a.length; i++)
            if (a[i] == b[i])
                c[i] = '0';
            else
                c[i] = '1';
 
        return c;
    }
 
    public static void Generate(char[] original, char[] current, int position, int k){
        if (position == original.length){
            System.out.println((Xor(original, current)));
            return;
        }
 
        if (k > 0){
            current[position] = '1';
            Generate(original, current, position + 1, k - 1);
        }
 
        current[position] = '0';
        Generate(original, current, position + 1, k);
    }
	
}
