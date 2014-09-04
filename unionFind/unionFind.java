
public class UnionFind {
	private int elements[];
	private int componentSize[];
	int components;
	
	/**
	 * Creates a new UnionFind-instance.
	 * Each element is initially its own component of size 1.
	 * O(n)
	 */
	UnionFind(int n){
		components = n;
		elements = new int [n];
		componentSize = new int [n];
		for(int i=0; i < n; i++){
			elements[i]=i;
			componentSize[i] = 1;
		}
	}
	
	
	int getNumComponents(){
		return components;
	}
	/*
	 * Returns the "name" of the component that x belongs to.
	 * O(1)
	 */
	int find(int x){
	  if(x >= 0 && x < elements.length){
	    return elements[x];
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
	    components--;
	    if(componentSize[x] >= componentSize[y]){
	    	int smallGroup = find(y);
	    	int largeGroup = find(x);
	        for(int i=0; i < elements.length; i++){
	            if(elements[i] == smallGroup){
	                elements[i] = find(x);
	                componentSize[i] += 1;
	            }else if(elements[i] == largeGroup){
	                componentSize[i] += 1;
	            }
	        }
	    }else{
	    	int smallGroup = find(x);
	    	int largeGroup = find(y);
	        for(int i=0; i < elements.length; i++){
	            if(elements[i] == smallGroup){
	                elements[i] = largeGroup;
	                componentSize[i] += 1;
	            }else if(elements[i] == largeGroup){
	                componentSize[i] += 1;
	            }
	        }
	    }
	}
}
