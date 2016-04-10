lines = STDIN.readlines.map(&:strip)

lines.each do |line|
  arr = line.split(" ").map(&:to_i)
  (0...arr.size).each do |i|
    copy =  line.split(" ").map(&:to_i)
    copy.delete_at(i)
    if arr[i] == copy.reduce(:+)
      puts arr[i]
      break
    end
  end
end