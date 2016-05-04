dom_points = Hash.new(0)

dom_points["A"] = 11
dom_points["K"] = 4
dom_points["Q"] = 3
dom_points["J"] = 20
dom_points["T"] = 10
dom_points["9"] = 14

normal_points = Hash.new(0)

normal_points["A"] = 11
normal_points["K"] = 4
normal_points["Q"] = 3
normal_points["J"] = 2
normal_points["T"] = 10

line = STDIN.gets.strip.split(" ")
hands = line[0].to_i
dominant = line[1]

points = 0
(0...4*hands).each do |c|
  card = STDIN.gets.strip
  if card[1] == dominant
    points += dom_points[card[0]]
  else
    points += normal_points[card[0]]
  end
end

puts points