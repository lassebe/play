lines = STDIN.readlines.map(&:strip)

lines.each do |line|
  name = []
  pulse = []
  line.split(" ").each do |word|
    w = word.to_f
    if w == 0.0 and word != "0.0"
      name << word
    else
      pulse << w
    end
  end
  average = (pulse.reduce(:+) / pulse.size)
  print '%.6f' % average
  puts " #{name.join(" ")}"
end