lines = STDIN.readlines.map(&:strip)

regex = /.*problem.*/

lines.each do |line|
  line.downcase!
  if line.match(regex)
    puts "yes"
  else
    puts "no"
  end
end