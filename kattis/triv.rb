line = STDIN.readlines.map(&:strip)

line.each do |l|
  break if l == "0 0 0"
  arr = l.split(" ").map(&:to_f)
  radius = arr[0]
  square_area = (2*radius)**2

  puts "#{radius*radius*Math::PI} #{(arr[2]/arr[1])*square_area}"

end
