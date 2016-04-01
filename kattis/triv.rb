input = STDIN.readlines.map(&:strip)
p input
input.each do |line|
  radius = line.split(" ")[0].to_f
  x = line.split(" ")[1].to_f
  y = line.split(" ")[2].to_f
  if Math.sqrt((x-radius)**2 + (y-radius)**2) <= radius
    puts "miss"
    next
  end

  
end