
public class UnionFind {
	private int elements[];
	private int rank[];
	int components;
	
	/**
	 * Creates a new UnionFind-instance.
	 * Each element is initially its own component of size 1.
	 * O(n)
	 */
	UnionFind(int n){
		components = n;
		elements = new int [n];
		rank = new int[n];
		for(int i=0; i < n; i++){
			elements[i]=i;
			rank[i] = 0;
		}
	}
	
	
	int getNumComponents(){
		return components;
	}
	/*
	 * Returns the "name" of the component that x belongs to.
	 * Now with actual path compression.
	 * O(1)
	 */
	int find(int x){
	  if(x >= 0 && x < elements.length){
		  int root = x;   
	    while( root != elements[root]){
	      root = elements[root];
	    }
	    while(x != root){
	      int newx = elements[x];
	      elements[x] = root;
	      x = newx;
	    }
	    return root;
	  }
	  //Something went wrong
	  return -1;
	}
	
	/*
	* Returns the size of a UnionFind, defined as the number of distinct elements.
	* O(1)
	*/
	int size(){
	    return elements.length;
	}

	
	/*
	* Merges the components containing x and y respectively.
	* If x and y are already in the same component, do nothing.
	* If x and y are part of different components, the larger grows to contain the smaller one.
	* O(n) where n is the number of elements in the UnionFind-structure.
	*/
	void unify(int x, int y){
	    if( x < 0 || x >= elements.length || y < 0 || y >= elements.length){
	        //Throw exception?
	        return;
	    }
	    int xRoot=find(x);
	    int yRoot=find(y);
	    if(xRoot == yRoot){
	    	return;
	    }
	    components--;
	    if(rank[xRoot] < rank[yRoot]){
	    	elements[xRoot] = yRoot;
	    }else if(rank[xRoot] > rank[yRoot]){
	    	elements[yRoot] = xRoot;
	    }else{
	    	elements[yRoot] = xRoot;
	    	rank[xRoot] += 1;
	    }
	}
}
