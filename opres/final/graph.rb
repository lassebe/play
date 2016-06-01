# a program to generate complete weighted undirected graphs 
# and also write these out in a format that is suitable for 
# a TSP-problem formulated as an integer programming problem
# in the SCIP-solver


# probably a very non-Ruby class name
class CompleteUndirectedWeightedGraph 
  attr_accessor :n, :edges

  def initialize(n)
    @n = n
    @edges = Array.new(n) { |vertex| vertex = Array.new(n) { |cost| cost = 0  } }
  end

  def update_edge(u, v, new_cost)
    return if u >= n or v >= n or new_cost < 0
    
    @edges[u][v] = new_cost
  end

  def print_integer_program
    puts "minimize"
    # objective function
    (0...n).each do |i|
      (0...n).each do |j|
        next if i == j
        puts "#{@edges[i][j]}*x#{i}#{j}"
      end
    end
    puts "subject to"
    # constraints


    puts "binary"
    # variables
  end
end

# todo: generate graph with random weights
def generate_graph_random_weights(n)

end


g = CompleteUndirectedWeightedGraph.new(5)
g.update_edge(2,3,48)
p g.edges
g.print_integer_program



# Turns out, none of this makes any sense for a complete graph,
# Using Hash instead of Array is just wasteful when all nodes are 
# connected to all others.

#class Edge
#  attr_accessor :to, :cost
#
#  def initialize(to, cost)
#    @to = to
#    @cost = cost
#  end
#end

#  # returns true if there's an edge between u and v
#  def has_edge(u, v)
#    return true if edges[u].find { |edge| edge.to == v }
#
#    false
#  end
#
#  # adds a bidirectional edge between u and v with cost c
#  def add_edge(u, v, c)
#    return if u >= n or v >= n
#
#    return if has_edge(u,v)
#
#    @edges[u] << Edge.new(v,c)
#    @edges[v] << Edge.new(u,c)
#  end