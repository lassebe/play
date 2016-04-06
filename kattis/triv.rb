def is_permuted(arr) 
  arr.sort!
  permuted = true
  diff = arr[1] - arr[0]
  (2...arr.size).each do |i|
    if arr[i] - arr[i-1] != diff
      permuted = false
      break
    end
  end

  if permuted
    puts "permuted arithmetic"
  else
    puts "non-arithmetic"
  end
end


n = STDIN.gets.to_i



(0...n).each do |t|
  arr = STDIN.gets.strip.split(" ").map(&:to_i)[1..-1]

  arithmetic = true

  diff = arr[1] - arr[0]
  (2...arr.size).each do |i|
    if arr[i] - arr[i-1] != diff
      arithmetic = false
      is_permuted(arr)
      break
    end
  end
  if arithmetic
    puts "arithmetic"
  end
end