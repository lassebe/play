tests = STDIN.gets.to_i


(0...tests).each do |t|
  hash = {}
  sounds = STDIN.gets.strip.split(" ")
  line = STDIN.gets.strip
  while line != "what does the fox say?"
    line = line.split(" ")
    animal = line[0]
    goes = line[2]
    hash[goes] = animal
    line = STDIN.gets.strip
  end

  fox = ""
  sounds.each do |sound|
    fox << (sound + " ") if not hash.has_key? sound
  end
  puts fox
end