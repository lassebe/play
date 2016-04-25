line = STDIN.gets.strip.split(" ").map(&:to_i)
a = line.first
b = line.last

prng = Random.new
alphabet = ("a"..."z").to_a

size = 15
essay = []
(0...b).each do |w|
  word = []
  (0...size).each do |letter|
    word << alphabet[prng.rand(25)]
  end
  essay << word.join("")
end

puts essay.join(" ")