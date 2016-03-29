line = STDIN.gets.strip.chars.map(&:to_i)

zoom = line.size

xmin = 0
ymin = 0


line.each_with_index do |key,index|
  diff = 2 **(zoom-1-index)
  if key == 1
    xmin = xmin + diff
  elsif key == 2
    ymin = ymin + diff
  elsif key == 3
    xmin = xmin + diff
    ymin = ymin + diff
  end
end

print "#{zoom} #{xmin} #{ymin}" 
