# a program to generate weighted (nodes & edges) undirected graphs 
# and also write these out in a format that is suitable for 
# different integer programming problems in the SCIP-solver

class Edge
  attr_accessor :to, :cost

  def initialize(to, cost)
    @to = to
    @cost = cost
  end
end

# probably a very non-Ruby class name
class UndirectedWeightedGraph 
  attr_accessor :n, :edges, :cost

  def initialize(n)
    @n = n
    @cost = Array.new(n)
    @edges = Hash.new
    (0...n).each do |v|
      @edges[v] = {}
    end
  end
  
  # returns true if there's an edge between u and v
  def has_edge(u, v)
    return true if @edges[u].has_key? v

    false
  end

  # adds a bidirectional edge between u and v with cost c
  def add_edge(u, v, c)
    return if u >= n or v >= n

    return if has_edge(u,v)

    @edges[u].merge!({v => c})
    @edges[v].merge!({u => c})
  end

  def update_edge(u, v, new_cost)
    return if u >= n or v >= n or new_cost < 0
    return if not has_edge(u,v)

  end

  def num_edges
    edges.values.each.map(&:size).reduce(:+)/2
  end

  def print_vertex_cover_ip
    puts "minimize"

    objective = ""
    # sum of all used vertex costs
    @cost.each_with_index do |cost_v,v|
      objective += "#{cost_v}x#{v}"
    end

    puts "subject to"

    # cover all edges
    (0...n).each do |u|
        puts "x#{u} + x#{} >= 1"
    end

    puts "binary"
    variables = ""
    (0...n).each do |v|
      print "x#{v} "
    end
    puts
  end
end

# todo: generate graph with random weights
def generate_graph_random_weights(n)

end


g = UndirectedWeightedGraph.new(4)
input = STDIN.readlines.map(&:strip)
input.each_with_index do |line,i|
  j = i + 1
  line.split(" ").map(&:to_i).each do |c|
    g.add_edge(i,j,c)
    j += 1
  end
end

p g.num_edges
#g.print_vertex_cover_ip
