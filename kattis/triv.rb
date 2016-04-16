while true
  room = STDIN.gets.strip.split(" ").map(&:to_i)
  break if room == [0,0]
  dirs = STDIN.gets.to_i
  x,actual_x = 0,0
  y,actual_y = 0,0
  
  (0...dirs).each do |d|
    walk = STDIN.gets.strip.split(" ")

    length = walk.last.to_i

    case walk.first
    when "r"
      x += length
      actual_x = (actual_x + length) < room.first ? (actual_x + length) : room.first-1
    when "l"
      x -= length
      actual_x = (actual_x - length) >= 0 ? (actual_x - length) : 0
    when "d"
      y -= length
      actual_y = (actual_y - length) >= 0 ? (actual_y - length) : 0
    when "u"
      y += length
      actual_y = (actual_y + length) < room.last ? (actual_y + length) : room.last-1
    else
      puts "wat"
    end
  end

  puts "Robot thinks #{x} #{y}"
  puts "Actually at #{actual_x} #{actual_y}"
  puts
end