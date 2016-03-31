def insertion_sort arr
  steps = 0
  sorted = [arr[0]]
  (1...arr.size).each do |i|
    #p sorted
    sorted.each_with_index do |el,index|
      next if arr[i] >= el

      steps = steps + (sorted.size-index)
      sorted.insert(index,arr[i])
      break
    end
    sorted = sorted.push(arr[i]) if sorted.size != i+1
    #p sorted
   # puts steps
  end
  steps
end


tests = STDIN.gets.to_i

(0...tests).each do |t|
  line = STDIN.gets.split(" ").map(&:to_i)[1..-1]
#  p line
  puts "#{t+1} #{insertion_sort line}"
end