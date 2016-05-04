import java.util.Random;

/**
 * 
 * @author Lasse Berglund
 *
 * A binary search tree, a data structure storing values of a generic type.
 * The values are stored in the tree are sorted.
 * The tree consists of nodes with two pointers to two other nodes, 
 * which in turn have pointers of their own.
 * 
 */

public class BinTree<T extends Comparable<T>>{
	protected static class Node<T> implements Comparable<T> {
		public Node<T> left;
		public Node<T> right;
		public T value;
		final int priority;
		Random r;
		
		public Node(T value){
			this.value = value;
			r=new Random();
			priority = (int) r.nextInt();
		}
		
        @SuppressWarnings("unchecked")
		@Override
        public int compareTo(Object o) {
        	if(!(o instanceof Node<?>))
    			throw new ClassCastException("o is not an instance of Node");
    		Node<T> n = (Node<T>) o;
    		
    		int result = ((Comparable<T>) value).compareTo(n.value);
    		return result;
        }
       
	}
	protected Node<T> Root;
	protected int size;
	
	
	/**
	 * Creates a new BinTree, with a root containing value. 
	 */
	public BinTree(T value){
		Root = new Node<T>(value);
		size = 1;
	}
	
	/**
	 * Creates an empty BinTree.
	 * T(n) = O(1)
	 */
	public BinTree(){
		Root = null;
		size = 0;
	}
	

	

	
	/**
	 * Inserts a new element in the BinTree. 
	 * Can't be an element that is already in the BinTree.
	 * @param value The element to be added
	 * @return True if value was successfully added otherwise False
	 * T(n) = O(n) Worst case
	 * T(n) = log(n) if tree is balanced
	 */
	public boolean insert(T value){
		Node<T> nod = new Node<T>(value);
		Node<T> iterator = Root;

		while( iterator != null ){
			if(nod.value.compareTo(iterator.value) == 0 ){
				System.out.println("Element already in BinTree");
				return false;
			}
				
			if( nod.compareTo(iterator) < 0 ){
				if(iterator.left == null){
					iterator.left = nod;
					size++;
					return true;
				}
				iterator = iterator.left;
				//System.out.println("New value smaller than node");
			}else{
				if(iterator.right == null){
					iterator.right = nod;
					size++;
					return true;
				}
				iterator = iterator.right;
				//System.out.println("New value bigger than node");
			}
		}
		
		//BinTree is empty, root gets the value T
		System.out.println("Tree is empty, root gets the value " + nod.value);
		Root = nod;
		size++;
		return true;
	}
	
	/**
	 * Finds an element in the BinTree. 
	 * @return True if value was successfully found otherwise False
	 * T(n) = O(n) Worst case
	 * T(n) = log(n) if tree is balanced
	 */
	public boolean find(T value){
		Node<T> nod = new Node<T>(value);
		
		Node<T> iterator = Root;
		while( iterator != null ){
			/*
			 * Do NOT use nod.value == iterator.value
			 * Breaks for data types such as double.
			 */
			if(nod.value.compareTo(iterator.value) == 0  ){
				System.out.println("Element found in BinTree");
				return true;
			}
				
			if( nod.compareTo(iterator) < 0 ){
				//System.out.println(" Value smaller than node");
				if(iterator.left == null){
					return false;
				}
				iterator = iterator.left;
			}else{
				//System.out.println(" Value bigger than node");
				if(iterator.right == null){
					return false;
				}
				iterator = iterator.right;
			}
		}
		
		//BinTree is empty
		System.out.println("Tree is empty");
		return false;
	}

	/**
	 * Returns the number of elements in the BinTree.
	 * T(n) = O(1)
	 */
	public int size(){
		return size;
	}
	
	/**
	 * Returns the depth of the tree.
	 * Which is the maximum depth for a node in the tree.
	 */
	public int depth(){
		return depth(Root);
	}
	
	/**
	 * Returns the number of leaves in the tree.
	 */
	public int leaves(){
		return leaves(Root);
	}
	
	/**
	 * Returns an ordered string representation of the tree.
	 */
	public String toString(){
		return toString(Root);
	}
	
	
	/**
	 * Internal method, returns the depth of the tree.
	 * That is the maximum depth for a node in the tree.
	 * T(n) = O(n)
	 */
	private int depth(Node<T> nod){
		if(nod == null)
			return 0;

		int leftDepth = depth(nod.left);
		int rightDepth = depth(nod.right);	
				
		if(leftDepth > rightDepth){
			return (leftDepth+1);
		}else{
			return (rightDepth+1);
		}
			
	}
	
	/**
	 * Internal method for getting the number of leaves in the tree.
	 * 
	 * T(n) = O(n)
	 */
	private int leaves(Node<T> nod){
		if(nod == null)
			return 0;
		if(isLeaf(nod))
			return 1;
		
		int count=leaves(nod.left);
		count+=leaves(nod.right);
		
		
		return count;
	}
	
	/**
	 * Internal method for returning an ordered string representation of the tree.
	 * 
	 * T(n) = O(n)
	 */
	private String toString(Node<T> nod){
		if(nod == null)
			return "";
		StringBuilder s = new StringBuilder();
		
		
		s.append(toString(nod.left));

		s.append(nod.value.toString());
		
		s.append(toString(nod.right));
		
		
		return s.toString();
	}

	/**
	 * Internal method for checking if a particular node in the tree is a leaf.
	 * Returns true if both the left & right subtree are empty.
	 * T(n) = O(1)
	 */
	private boolean isLeaf(Node<T> nod){
		if(nod.right == null && nod.left == null)
			return true;
		
		return false;
	}
	

	/**
	 * Returns the Root of the tree.
	 * T(n) = O(1)
	 */
	public Node<T> getRoot(){
		return Root;
	}





	/**
     * Unit test. Run with "java -ea BinTree".   
	 */
	public static void main(String[] args) {
		BinTree t = new BinTree();
//		System.out.println(t.printPrio(t.getRoot()));
//		System.out.println("Depth " + t.depth());
//		System.out.println("Leaf " + t.leaves());
//		System.out.println("Elements " + t.toString());
		
		t.insert(4);
		System.out.println();
		System.out.println("Insertion 4");
		System.out.println("Root: " + t.getRoot().value);
		System.out.println("Depth " + t.depth());
		System.out.println("Size " + t.size());
		System.out.println("Leaf " + t.leaves());
		System.out.println("Elements " + t.toString());
		System.out.println(t.getRoot());
		//System.out.println(t.toString());
		
		t.insert(2);	
		System.out.println();
		System.out.println("Insertion 2");
		System.out.println("Root: " + t.getRoot().value);	
		System.out.println("Depth " + t.depth());
		System.out.println("Size " + t.size());
		System.out.println("Leaf " + t.leaves());
		System.out.println("Elements " + t.toString());
		System.out.println(t.getRoot());
		//System.out.println(t.toString());
		
		t.insert(6);
		System.out.println();
		System.out.println("Insertion 6");
		System.out.println("Root: " + t.getRoot().value);
		System.out.println("Depth " + t.depth());
		System.out.println("Size " + t.size());
		System.out.println("Leaf " + t.leaves());
		System.out.println("Elements " + t.toString());
		System.out.println(t.getRoot());
		//System.out.println(t.toString());
		
		t.insert(8);
		System.out.println();
		System.out.println("Insertion 8 ");
		System.out.println("Root: " + t.getRoot().value);
		System.out.println("Depth " + t.depth());
		System.out.println("Size " + t.size());
		System.out.println("Leaf " + t.leaves());
		System.out.println("Elements " + t.toString());	
		System.out.println(t.getRoot());
		//System.out.println(t.toString());
		
		t.insert(7);
		System.out.println();
		System.out.println("Insertion 7");
		System.out.println("Root: " + t.getRoot().value);
		System.out.println("Depth " + t.depth());
		System.out.println("Size " + t.size());
		System.out.println("Leaf " + t.leaves());
		System.out.println("Elements " + t.toString());
		System.out.println(t.getRoot());
		//System.out.println(t.toString());
		
		t.insert(45);
		System.out.println();
		System.out.println("Insertion 45");
		System.out.println("Root: " + t.getRoot().value);
		System.out.println("Depth " + t.depth());
		System.out.println("Size " + t.size());
		System.out.println("Leaf " + t.leaves());
		System.out.println("Elements " + t.toString());
		System.out.println(t.getRoot());
		
		t.insert(3);
		System.out.println();
		System.out.println("Insertion 3");
		System.out.println("Root: " + t.getRoot().value);
		System.out.println("Depth " + t.depth());
		System.out.println("Size " + t.size());
		System.out.println("Leaf " + t.leaves());
		System.out.println("Elements " + t.toString());
		System.out.println(t.getRoot());

		
	}


}

//BinTree<Integer> t1 = new BinTree<Integer>(5);
//assert t1.size() == 1;
//assert t1.insert(5) == false;
//assert t1.insert(7) == true;
//assert t1.size() == 2;
//
//assert t1.find(1) == false;
//assert t1.find(5) == true;
//assert t1.find(7) == true;
//
//t1.insert(3);
//t1.insert(7);
//t1.insert(2);
//t1.insert(4);
//t1.insert(6);
//t1.insert(8);
//System.out.println( t1.depth());
//System.out.println( t1.size());	
//System.out.println(t1.leaves());
//System.out.println(t1.toString());
//
//
//BinTree<Integer> t2 = new BinTree<Integer>();
//t2.find(3);
//t2.insert(3);
//t2.insert(7);
//t2.insert(3);
//t2.insert(7);
//t2.find(3);
//t2.find(7);



/*
public boolean find(T value, Node<T> rot){
	if(rot == null)
		return false;
				
	if(value == rot.value)
		return true;
	
	if((value.compareTo(rot.value) < 0)){
		return find(value, rot.left);
	}else{
		return find(value, rot.right);
	}
		
	
}

/**
* Adds a new element to the BinTree.
* This is done recursively.
* @param nod The new element
* @param rot The root of the BinTree
* @return
*//*
public Node<T> insert(Node<T> nod, Node<T> rot){
	if(rot == null)
		return nod;
	
	if(nod.value == rot.value ){
		System.out.println("Element already in BinTree");
	}else if(nod.compareTo(rot) < 0){
		rot.left = insert(nod, rot.left);
	}else{
		rot.right= insert(nod, rot.right);
	}
	
	return rot;
}*/
