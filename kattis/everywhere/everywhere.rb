test = STDIN.gets.to_i

(0...test).each do |t|
  cities = STDIN.gets.to_i
  names = []
  (0...cities).each do |c|
    names << STDIN.gets
  end
  names.uniq!
  puts names.size
end 