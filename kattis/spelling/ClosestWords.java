/* Labb 2 i DD1352 Algoritmer, datastrukturer och komplexitet    */
/* Se labbanvisning under kurswebben https://www.kth.se/social/course/DD1352 */
/* Ursprunglig författare: Viggo Kann KTH viggo@nada.kth.se      */
import java.util.LinkedList;
import java.util.List;

public class ClosestWords {
  LinkedList<String> closestWords = null;
  private StringBuilder stringRepresentation;

  int closestDistance = -1;
  int[][] matrix = new int[41][41];

  int partDist(String w1, String w2, int l1, int l2,int offset){
    for(int i=1; i < l1+1; i++){
      for(int j=offset; j < l2+1; j++){
        int res = matrix[i-1][j-1];
        if(w1.charAt(i-1) != w2.charAt(j-1)){
          ++res;
        }
        int addLetter = matrix[i-1][j]+1;
        if(addLetter < res)
          res = addLetter;
        int deleteLetter = matrix[i][j-1]+1;
        if(deleteLetter < res)
          res = deleteLetter;
        matrix[i][j] = res;
      }
    }
    /*
    System.out.println("offset=" + offset + " s=" + w2);
    for(int i=0;i<l1+1;i++){
      for(int j=0;j<l2+1;j++)
        System.out.print(matrix[i][j] + " ");
      System.out.println();
    }
    */
    return matrix[l1][l2];
  }

  public ClosestWords(String w, List<String> wordList) {
    for(int i=0;i<41;i++){
      matrix[i][0] = i;
      matrix[0][i] = i;
    }
    String lastWord="";
    for (String s : wordList) {
      int l1 = w.length();
      int l2 = s.length();
      int offset=1;
      if( Math.abs(l1-l2) > closestDistance && closestDistance != -1)
        continue;
      int minLen = Math.min(s.length(), lastWord.length());
      for (int i=0; i<minLen; ++i) {
        if (s.charAt(i) != lastWord.charAt(i))
          break;
        ++offset;
      }
      int dist = partDist(w, s,w.length(),s.length(), offset);
      lastWord = s;
      // System.out.println("d(" + w + "," + s + ")=" + dist);
      if (dist < closestDistance || closestDistance == -1) {
        closestDistance = dist;
        stringRepresentation = new StringBuilder();
        stringRepresentation.append(" ").append(s);
      }
      else if (dist == closestDistance)
        stringRepresentation.append(" ").append(s);
    }
  }

  int getMinDistance() {
    return closestDistance;
  }

  String getClosestWords() {
    return stringRepresentation.toString();
  }
}
