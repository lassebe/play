
dict = Hash.new("eh")
input = STDIN.readlines.map(&:strip)

words = input[0,input.find_index("")]
translate = input[input.find_index("")+1,input.length]

words.each do |word|
  word = word.split(" ")
  dict[word[1]] = word[0]
end


translate.each do |trans|
  puts dict[trans]
end
