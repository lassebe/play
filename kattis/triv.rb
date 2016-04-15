lines = STDIN.readlines.map(&:strip)
MAX_EARTH = 365
MAX_MARS = 687

lines.each_with_index do |line,index|
  
  line = line.split(" ").map(&:to_i)
  
  earth = line[0]
  mars = line[1]
  count = 0
  while earth != 0 or mars != 0
    earth = (earth + 1) % MAX_EARTH
    mars = (mars + 1)  % MAX_MARS
    count = count + 1
  end
  
  puts "Case #{index+1}: #{count}"
end