ws = STDIN.readlines.map(&:strip)
words = []
ws.each do |w|
  w.split(" ").each do |v|
    words << v
  end
end

compound = {}
words.each do |w1|
  words.each do |w2|
    next if w1 == w2
    compound[w1+w2] = 1
  end
end

compound.keys.sort.each do |c|
  puts c
end
