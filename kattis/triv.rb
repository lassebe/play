while true
  n = STDIN.gets.to_i
  break if n == 0
  first_list = []
  second_list = []
  hash = {}
  (0...n).each do |x|
    first_list << STDIN.gets.to_i
  end

  (0...n).each do |x|
    second_list << STDIN.gets.to_i
  end

  sorted_list = first_list.sort
  second_list.sort!
  sorted_list.each_with_index do |x,index|
    hash[x] = second_list[index]
  end


  res = []
  first_list.each do |x|
    res << hash[x]
  end

  puts res
  puts
end