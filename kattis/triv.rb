lines = STDIN.readlines.map(&:strip)

unique_names = Hash.new(0)

lines.each do |line|
  first_name = line.split(" ").first
  last_name = line.split(" ").last
  unique_names[first_name] += 1
end

lines.sort! do |name_a,name_b|
  name_a = name_a.split(" ")
  name_b = name_b.split(" ")
  if name_a.last == name_b.last 
    name_a.first <=> name_b.first 
  else
    name_a.last <=> name_b.last
  end
end

lines.each do |line|
  if unique_names[line.split(" ").first] > 1
    puts line
  else
    puts line.split(" ").first
  end
end