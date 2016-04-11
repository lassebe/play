while true
  line = STDIN.gets.strip
  break if line == "0"

  line = line.split(" ").map(&:to_f)

  x = line[0]
  y = line[1]
  x2 = line[2]
  y2 = line[3]
  p = line[4]

  puts sprintf('%.10f', ((x-x2).abs**p + (y-y2).abs**p)**(1/p))

end