input = STDIN.gets.split(" ").map(&:to_i)

n = input[0]
b = input[1]
max = 0
(0..b).each do |i|
  max = max + 2**i
end

if n <= max 
  puts "yes"
else
  puts "no"
end