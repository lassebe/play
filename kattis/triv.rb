tests = STDIN.gets.to_i

(0...tests).each do |test|
  turtles = STDIN.gets.split(" ").map(&:to_i)

  lower_bound = 0
  prev = turtles[0]
  (1...turtles.size).each do |turtle|
    if turtles[turtle] > 2*prev
      lower_bound = lower_bound + (turtles[turtle] - 2*prev)
    end

    prev = turtles[turtle]
  end

  puts lower_bound
end