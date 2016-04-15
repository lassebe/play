n = STDIN.gets.to_i

arr = STDIN.gets.strip.split(" ").map(&:to_i)

ans = []

arr.each do |a|
  (0...256).each do |n|
    if ((n<<1) ^ n) & 255 == a
      ans << n
      break
    end
  end
end

puts ans.join(" ")