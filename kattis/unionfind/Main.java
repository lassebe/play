public class Main {
  public static void main(String[] args) {
    Kattio io = new Kattio(System.in,System.out);
    int n = io.getInt();
    int lines = io.getInt();
    UnionFind uf = new UnionFind(n);

    for (int i=0; i < lines ; ++i ) {
      String s = io.getWord();
      int a = io.getInt();
      int b = io.getInt();
      if(s.equals("?")){
        if(uf.find(a) ==uf.find(b))
          io.println("yes");
        else
          io.println("no");
      }else{
        uf.unify(a,b);
      }
    }
    io.close();
  }
}