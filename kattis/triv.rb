line = STDIN.gets.strip.split(" ")
outer = line[0].to_i
inner = line[1].to_i

cheese = outer - inner

puts "%.6f" % (100*(cheese**2*Math::PI) / (outer**2*Math::PI) )