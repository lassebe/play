tests = STDIN.gets.to_i

(0...tests).each do |t|
  line_a = STDIN.gets.strip
  line_b = STDIN.gets.strip
  puts line_a
  puts line_b

  (0...line_a.size).each do |i|
    if line_a[i] != line_b[i]
      print "*"
    else
      print "."
    end
  end
  puts
  puts
end
