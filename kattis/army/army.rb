tests = STDIN.gets.to_i

(0...tests).each do |i|
  vask = STDIN.gets
  line = STDIN.gets.split(" ").map(&:to_i)

  godzilla = STDIN.gets.split(" ").map(&:to_i).sort
  mecha = STDIN.gets.split(" ").map(&:to_i).sort

  while not godzilla.empty? and not mecha.empty?
    if godzilla.first < mecha.first
      godzilla.shift
    else 
      mecha.shift
    end
  end

  if godzilla.empty?
    puts "MechaGodzilla"
  else
    puts "Godzilla"
  end
end