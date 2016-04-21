input = STDIN.gets.strip.split(" ").map(&:to_i)

n = input[0]
p = input[1]
q = input[2]


rounds = p+q


if (rounds/n) % 2 == 0
  puts "paul"
else
  puts "opponent"
end