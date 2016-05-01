tests = STDIN.gets.to_i
(0...tests).each do |t|
  number_of_months = STDIN.gets.strip.split(" ")[1].to_i
  months = STDIN.gets.strip.split(" ").map(&:to_i)

  lucky_days = 0
  day_of_week = 0
  months.each_with_index do |month,index|
    (0...month).each do |day_of_month|
      lucky_days += 1 if day_of_week == 5 and day_of_month == 12
      day_of_week = (day_of_week + 1) % 7
    end
  end

  puts lucky_days
end