input = STDIN.gets.split(" ")

h = input[0].to_i

root = 2**(h+1)-1
if input.size == 1
  puts root
  exit(0)
end


line = input[1]

i = 1
line.chars.each do |c|
  if c == "L"
    i = i * 2
  else
    i = i * 2 + 1
  end
end


puts root-(i-1)