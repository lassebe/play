customers = Hash.new(0)


input = STDIN.readlines.map(&:strip)
day = 1
input.each_with_index do |line,index|
  next if line == "OPEN"
  

  if line == "CLOSE"
    puts "Day #{day}"
    customers.keys.sort.each do |key|
      bill = (customers[key]*0.10)
      puts "#{key} $#{'%.2f' % bill}"
    end
    unless index == input.size - 1
      puts  
    end

    day = day + 1
    customers = Hash.new(0)
    next
  end

  data = line.split(" ")
  customers[data[1]] = data[2].to_i - customers[data[1]]
end