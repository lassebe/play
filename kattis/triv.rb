n = STDIN.gets.to_i
arr = STDIN.gets.strip.split(" ").map(&:to_i)
counts = Hash.new(0)
arr.each {|e| counts[e] += 1 }
counts = counts.select {|k,v| v == 1 }

if not counts.keys.empty?
    puts arr.find_index(counts.keys.sort[-1])+1
else
    puts "none"
end