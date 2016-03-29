tests = STDIN.gets.to_i

(0...tests).each do |t|
  votes = []
  candidates = STDIN.gets.to_i

  (0...candidates).each do |c|
    votes << STDIN.gets.to_i
  end

  temp = votes.sort{ |x,y| y <=> x }
  if temp[0] == temp[1]
    puts "no winner"
    next
  end
  
  max_votes = votes[0]
  winner = 0
  total = votes.reduce(:+)
  votes.each_with_index do |vote,index|
    if vote > max_votes
      max_votes = vote
      winner = index
    end
  end

  if max_votes > total / 2
    puts "majority winner #{winner+1}"
  else
    puts "minority winner #{winner+1}"
  end
      
end