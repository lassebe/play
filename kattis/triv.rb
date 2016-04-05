n = STDIN.gets.to_i

actual_minutes = 0
sl_seconds = 0

(0...n).each do |i|

  line = STDIN.gets.strip.split(" ").map(&:to_i)
  actual_minutes = actual_minutes + line[0]
  sl_seconds = sl_seconds + line[1]

end

average_sl_minutes = sl_seconds.to_f / (actual_minutes.to_f*60)

if average_sl_minutes <= 1.0
  puts "measurement error"
else
  puts average_sl_minutes
end