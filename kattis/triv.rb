n = STDIN.gets.to_i

building = Hash.new(false)

(0...n).each do |i|
  line = STDIN.gets.strip.split(" ")
  entry = false
  entry = true if line[0] == "entry"

  name = line.last
  if entry
    if building.has_key? name
      puts "#{name} entered (ANOMALY)"
    else
      puts "#{name} entered"
      building[name] = true
    end
  else
    if building.has_key? name
      puts "#{name} exited"
      building.delete name
    else
      puts "#{name} exited (ANOMALY)"
    end 
  end
end