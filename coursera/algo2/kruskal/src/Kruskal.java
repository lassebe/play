import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;


public class Kruskal {

	static Kattio io = new Kattio(System.in, System.out);
	static int edges;
	static UnionFind uf;
	

	/**
	 * @param args
	 */
	@SuppressWarnings("unchecked")
	public static void main(String[] args) {	
		@SuppressWarnings("rawtypes")
		class Edge implements Comparable{
			public int u;
			public int v;
			public int c;
			Edge(int u, int v, int c){
				this.u=u;
				this.v=v;
				this.c=c;
			}
			@Override
			public int compareTo(Object o){
				Edge e = (Edge) o;
				if(this.c > e.c){
					return 1;
				}else if(this.c < e.c){
					return -1;
				}
				
				return 0;
			}
		};
		
		edges = io.getInt();
		uf = new UnionFind(edges);
		edges = ((edges-1)*edges)/2;
		ArrayList<Edge> es = new ArrayList<Edge>();
		
		for(int i=0; i < edges; i++){
			int n1 = io.getInt()-1;
			int n2 = io.getInt()-1;
			int c = io.getInt();
			es.add(new Edge(n1,n2,c));
		}
		
		Collections.sort(es);
		long s=0;
		int iter=0;
		while(uf.getNumComponents() > 4){
			if(uf.find(es.get(iter).u) != uf.find(es.get(iter).v)){
				//io.print("union ");
				//io.println(uf.find(es.get(iter).u) + " "+ uf.find(es.get(iter).v) + " " + es.get(iter).c);
				uf.unify(es.get(iter).u,es.get(iter).v);
							
			}
			iter++;
		}
		boolean found=false;
		while(!found){
			if(uf.find(es.get(iter).u) != uf.find(es.get(iter).v)){
				s = es.get(iter).c;
				found = true;
			}
			iter++;
		}/*
		for(; iter < edges; iter++){
			io.println("U=" + es.get(iter).u + " V=" + es.get(iter).v + " C=" + es.get(iter).c);
		}*/
		io.println(s);
		io.close();
	}

	
}
