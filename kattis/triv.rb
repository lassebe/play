line = STDIN.gets.strip

hash = Hash.new(0)

line.chars do |c|

  hash[c] = (hash[c] + 1) % 2
end

uneven = 0

hash.each do |key,val|
  if val == 1
    uneven = uneven + 1
  end
end

if uneven >= 1
  puts uneven-1
else
  puts 0
end