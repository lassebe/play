n = STDIN.gets.to_i


def encrypt str
  k = 1
  (k..100).each do |i|
    if i*i >= str.length
      k = i
      break
    end
  end

  matrix = []
  (0...k).each do |x|
    arr = []
    (0...k).each do |y|
      if (x*k)+y < str.length
        arr << str[(x*k)+y]
      else
        arr << "*"
      end
    end
    matrix << arr
  end
  
  matrix.transpose.map(&:reverse).each do |line|
    (0...k).each do |y|
      if line[y] != "*"
        print line[y]
      end
    end
  end
  puts
end

(0...n).each do |i|
  line = STDIN.gets.strip
  encrypt line
end
    
