# Asserts strings are of equal length 
def count_diff str_a, str_b
  count = 0
  (0..str_a.length).each do |i|
    count = count + 1 if str_a[i] != str_b[i]
  end
  count
end

line = STDIN.gets
count = 0
length = line.length
(0..length-3).step(3).each do |i|
  count = count + count_diff(line[i,3],"PER")
end

puts count

