
def digitize str
  if str =="**** ** ** ****"
    0
  elsif str =="  *  *  *  *  *"
    1
  elsif str =="***  *****  ***"
    2
  elsif str =="***  ****  ****"
    3
  elsif str =="* ** ****  *  *"
    4
  elsif str =="****  ***  ****"
    5
  elsif str =="****  **** ****"
    6  
  elsif str =="***  *  *  *  *"
    7
  elsif str =="**** ***** ****"
    8
  elsif str =="**** ****  ****"
    9
  else
    -1
  end
end


input = STDIN.readlines
(0...input.size-1).each {|i| input[i].delete!("\n")}
digits = (input[0].size+1) / 4


arr = []

(0...digits).each do |digit|
  str = ""
  (0...5).each do |row|
    str << input[row][4*digit,3]
  end
  d = digitize str
  if d == -1
    arr = []
    break
  end
  arr << d
end

if arr.empty?
  puts "BOOM!!"
elsif arr[-1] % 2 == 0 and arr.reduce(:+) % 3 == 0
  puts "BEER!!"
else
  puts "BOOM!!"
end