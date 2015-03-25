import java.util.ArrayList;


public class Prim {
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {

		ArrayList<Integer> visited = new ArrayList<Integer>();
		ArrayList<Integer> unvisited = new ArrayList<Integer>();
		Kattio io = new Kattio(System.in, System.out);
		int nodes = io.getInt();
		int edges = io.getInt();
		HashGraph g = new HashGraph(nodes);
		for(int i=0; i < edges; i++){
			int n1 = io.getInt()-1;
			int n2 = io.getInt()-1;
			int c = io.getInt();
			g.addBi(n1,n2,c);
			unvisited.add(i);
		}
		long totalCost=0;
		int v=0;
		int w=0;
		int minimumCost=32767;
		visited.add(v);
		//unvisited.remove(v);
		while(visited.size() < nodes){
			int tempW=0;
			for(int i=0; i < visited.size();i++){
				int tempV=visited.get(i);
				VertexIterator it = g.neighbors(tempV);
				while(it.hasNext()){
					tempW = it.next();
					if(g.cost(tempV,tempW) < minimumCost && !visited.contains(tempW)){
						v=tempV;
						w=tempW;
						minimumCost = g.cost(v,w);
						
					}
				}
				//io.println("v=" + tempV + " w=" +tempW+" c=" + g.cost(tempV,tempW));
			}
			io.println("v=" + v + " w=" +w+" c=" + g.cost(v,w));
			totalCost+=g.cost(v, w);
			visited.add(w);
			//unvisited.remove(w);
			minimumCost=32767;
		}
		
		io.println(totalCost);
		
		io.close();
	}

}
