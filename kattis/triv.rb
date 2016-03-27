lines = STDIN.readlines.map(&:strip)
lines.each do |l|
  numbers = l.split(" ")
  num, den = numbers[0].to_i,numbers[1].to_i
  break if num == 0 and den == 0

  if num < den
    puts "0 #{num} / #{den}"
  else
    puts "#{num/den} #{num%den} / #{den}"
  end
end