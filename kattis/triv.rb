input = STDIN.gets.strip.split(" ").map(&:to_i)

c = input.first
n = input.last

consistent = true
on_train = 0
(0...n).each do |i|
  station = STDIN.gets.strip.split(" ").map(&:to_i)
  left = station[0]
  enter = station[1]
  wait = station[2]
  
  if on_train - left < 0 
    consistent = false
    break
  end
  
  on_train -= left
  
  if on_train + enter > c
    consistent = false
    break
  end
  
  on_train += enter

  if wait > 0 and on_train < c
    consistent = false
    break
  end
end

if consistent and on_train == 0
  puts "possible"
else
  puts "impossible"
end