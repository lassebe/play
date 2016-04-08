n = STDIN.gets.to_i
line = STDIN.gets.strip
adrian = []
bruno = []
goran = []
while true 
  adrian << "A" 
  break if adrian.size == n
  adrian << "B"
  break if adrian.size == n
  adrian << "C"
  break if adrian.size == n
end
while true 
  bruno << "B" 
  break if bruno.size == n
  bruno << "A"
  break if bruno.size == n
  bruno << "B"
  break if bruno.size == n
  bruno << "C"
  break if bruno.size == n
end

while true 
  goran << "C" 
  break if goran.size == n
  goran << "C" 
  break if goran.size == n
  goran << "A"
  break if goran.size == n
  goran << "A"
  break if goran.size == n
  goran << "B"
  break if goran.size == n
  goran << "B"
  break if goran.size == n
end
adrian = adrian.join("")
bruno = bruno.join("")
goran = goran.join("")

scores = {"Adrian" => 0, "Bruno" => 0, "Goran" => 0}
(0...n).each do |i|
  scores["Adrian"] = scores["Adrian"] + 1 if adrian[i] == line[i]
  scores["Bruno"] = scores["Bruno"] + 1 if bruno[i] == line[i]
  scores["Goran"] = scores["Goran"] + 1 if goran[i] == line[i]
end

max = scores.values.sort[-1]
puts max
scores.keys.sort.each do |key|
  puts key if scores[key] == max
end
