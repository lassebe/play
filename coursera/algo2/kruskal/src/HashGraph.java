
import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;
import java.util.NoSuchElementException;


/**
 * A graph with a fixed number of vertices implemented using adjacency maps.
 * Space complexity is &Theta;(n + m) where n is the number of vertices and m
 * the number of edges.
 * 
 * @author Lasse Berglund
 * @version [Date]
 */
public class HashGraph implements Graph {
	/**
	 * The map edges[v] contains the key-value pair (w, c) if there is an edge
	 * from v to w; c is the cost assigned to this edge. The maps may be null
	 * and are allocated only when needed.
	 */
	private final Map<Integer, Integer>[] edges;
	private final static int INITIAL_MAP_SIZE = 4;

	/** Number of edges in the graph. */
	private int numEdges;

	/**
	 * Constructs a HashGraph with n vertices and no edges. Time complexity:
	 * O(n)
	 * 
	 * @throws IllegalArgumentException
	 *             if n < 0
	 */
	public HashGraph(int n) {
		if (n < 0)
			throw new IllegalArgumentException("n = " + n);

		// The array will contain only Map<Integer, Integer> instances created
		// in addEdge(). This is sufficient to ensure type safety.
		@SuppressWarnings("unchecked")
		Map<Integer, Integer>[] a = new HashMap[n];
		edges = a;
	}


	/**
	 * Add an edge without checking parameters.
	 */
	private void addEdge(int from, int to, int cost) {
		if (edges[from] == null)
			edges[from] = new HashMap<Integer, Integer>(INITIAL_MAP_SIZE);
		if (edges[from].put(to, cost) == null)
			numEdges++;
	}

	/**
	 * {@inheritDoc Graph} Time complexity: O(1).
	 */
	@Override
	public int numVertices() {
		return edges.length;
	}

	/**
	 * {@inheritDoc Graph} Time complexity: O(1).
	 */
	@Override
	public int numEdges() {
		return numEdges;
	}

	/**
	 * {@inheritDoc Graph} Time complexity: O(1).
	 */
	@Override
	public int degree(int v) throws IllegalArgumentException {
		checkVertexParameter(v);
		
		if(edges[v] == null)
			return 0;
		
		return edges[v].size();
	}

	/**
	 * {@inheritDoc Graph} Time complexity: O(1).
	 */
	@Override
	public VertexIterator neighbors(int v) {
		checkVertexParameter(v);

		return new NeighborIterator(v);
	}
	
	private class NeighborIterator implements VertexIterator {

		Iterator<Integer> it;

		NeighborIterator(int v) {
			if(edges[v] == null){
				it = null;
			}else{
				it = edges[v].keySet().iterator();

			}
			
		}


		@Override
		public boolean hasNext() {
			if(it == null)
				return false;

			return it.hasNext();

		}

		@Override
		public int next() {
			if(this.hasNext()){
				return it.next();
			}else{
			throw new NoSuchElementException(
					"This iterator has no more elements.");
			}
		}
	}



	/**
	 * {@inheritDoc Graph} 
	 * (Worst case) Time complexity: O(n) where n is the number of vertices in G.
	 */
	@Override
	public boolean hasEdge(int v, int w) {
		checkVertexParameters(v, w);
	
		if(edges[v] == null)
			return false;

		return edges[v].containsKey(w);

	}



	/**
	 * {@inheritDoc Graph}
	 * (Worst case) Time complexity: O(n) where n is the number of vertices in G.
	 */
	@Override
	public int cost(int v, int w) throws IllegalArgumentException {
		checkVertexParameters(v, w);
		
		if(!hasEdge(v,w))
			return NO_COST;
		
		
		return edges[v].get(w);
	}


	/**
	 * {@inheritDoc Graph}
	 */
	@Override
	public void add(int from, int to) {
		checkVertexParameters(from, to);
		
		addEdge(from, to, NO_COST);
	}


	/**
	 * {@inheritDoc Graph}
	 */
	@Override
	public void add(int from, int to, int c) {
		checkVertexParameters(from, to);
		
		addEdge(from, to, c);
	}


	/**
	 * {@inheritDoc Graph}
	 */
	@Override
	public void addBi(int v, int w) {
		checkVertexParameters(v, w);

		addEdge(v, w, NO_COST);
		if (v == w)
			return;
		addEdge(w, v, NO_COST);
	}


	/**
	 * {@inheritDoc Graph}
	 */
	@Override
	public void addBi(int v, int w, int c) {
		checkVertexParameters(v, w);

		addEdge(v, w, c);
		if (v == w)
			return;
		addEdge(w, v, c);
	}


	/**
	 * {@inheritDoc Graph}
	 */
	@Override
	public void remove(int from, int to) {
		checkVertexParameters(from, to);
		
		if(!hasEdge(from, to))
			return;
		
		edges[from].remove(to);
		numEdges--;
		
	}


	/**
	 * {@inheritDoc Graph}
	 */
	@Override
	public void removeBi(int v, int w) {
		remove(v, w);
		remove(w, v);
	}


	/**
	 * {@inheritDoc Graph}
	 * (Worst case) Time complexity: O(n^2)
	 */
	@Override
	public String toString() {
		
		StringBuilder sb = new StringBuilder();
		sb.append("{");
		
		for(int i=0; i < edges.length; i++){
			for (VertexIterator it = neighbors(i); it.hasNext(); ){
				int j = it.next();
				int cost = edges[i].get(j);
				switch (cost) {
				case NO_COST:
					sb.append("(" + i + "," + j + "), ");
					break;
				default:
					sb.append("(" + i + "," + j + "," + cost + "), ");
				}

			}

			
		}
		
		if (numEdges > 0)
			sb.setLength(sb.length() - 2); // Remove trailing ", "
		sb.append("}");
		return sb.toString();
		
	}
	

	/**
	 * {@inheritDoc Graph}
	 */
	private void checkVertexParameter(int v) {
		if (v < 0 || v >= edges.length)
			throw new IllegalArgumentException("Out of range: v = " + v + ".");
	}


	/**
	 * {@inheritDoc Graph}
	 */
	private void checkVertexParameters(int v, int w) {
		if (v < 0 || v >= edges.length || w < 0 || w >= edges.length)
			throw new IllegalArgumentException("Out of range: v = " + v
					+ ", w = " + w + ".");
	}
}