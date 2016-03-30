dogs = STDIN.gets.split(" ").map(&:to_i)
dog_a = []
dog_b = []
(0...200).each do |i|
  (0...dogs[0]).each do
    dog_a << true
  end
  (0...dogs[1]).each do 
    dog_a << false
  end
  
  (0...dogs[2]).each do
    dog_b << true
  end
  (0...dogs[3]).each do 
    dog_b << false
  end

end

arrival = STDIN.gets.split(" ").map(&:to_i)

arrival.each do |arr|
  if dog_a[arr-1] and dog_b[arr-1]
    puts "both"
  elsif dog_a[arr-1] or dog_b[arr-1]
    puts "one"
  else
    puts "none"
  end
      
end