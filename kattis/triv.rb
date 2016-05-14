lines = STDIN.readlines.map(&:strip)

lines.each do |line|
  char_count = Hash.new(0)
  
  n = line.size
  # factorial
  anagrams = (1..n).reduce(:*) || 1

  line.chars.each do |c|
    char_count[c] += 1
  end

  char_count.keys.each do |key|
    # divide by the factorial of the amount of times a letter occurs
    anagrams /= ((1..char_count[key]).reduce(:*) || 1) if char_count != 1
  end
  
  puts anagrams
end