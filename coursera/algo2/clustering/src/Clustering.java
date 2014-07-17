import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;

public class Clustering {

	
	/**
	 * @param args
	 */
	@SuppressWarnings("unchecked")
	public static void main(String[] args) {	
		Kattio io = new Kattio(System.in, System.out);
		UnionFind uf;
		int nodes = io.getInt();
		int bits = io.getInt();
		HashMap<Integer[],ArrayList<Integer>> hm = new HashMap<Integer[],ArrayList<Integer>>();
		uf = new UnionFind(nodes);
		
		long s=0;
		int iter=0;
		while(uf.getNumComponents() > 4){
			//if(uf.find(es.get(iter).u) != uf.find(es.get(iter).v)){
				//io.print("union ");
				//io.println(uf.find(es.get(iter).u) + " "+ uf.find(es.get(iter).v) + " " + es.get(iter).c);
				//uf.unify(es.get(iter).u,es.get(iter).v);
							
			//}
			iter++;
		}
		boolean found=false;
		/*
		while(!found){
			if(uf.find(es.get(iter).u) != uf.find(es.get(iter).v)){
				s = es.get(iter).c;
				found = true;
			}
			iter++;
		}*/
		io.println(s);
		io.close();
	}

	
}
