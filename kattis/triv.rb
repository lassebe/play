l = STDIN.gets.to_i
d = STDIN.gets.to_i
x = STDIN.gets.to_i

min = l
(min..d).each do |m|
  if m.to_s.split("").map(&:to_i).reduce(:+) == x
    min = m
    break
  end
end

max = d
(l..d).to_a.reverse.each do |m|
  if m.to_s.split("").map(&:to_i).reduce(:+) == x
    max = m
    break
  end
end

puts min 
puts max 