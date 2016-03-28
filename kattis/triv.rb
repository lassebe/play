while true
  arr = STDIN.gets.split(" ")
  break if arr[0] == "0"

  rot = arr[0].to_i
  line = arr[1]
  alphabet = "A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z,_,.".split(",")

  line.reverse!
  out = ""
  line.chars do |c|
    index = alphabet.find_index c
    out << alphabet[(index+rot) % alphabet.size]
  end

  puts out

end