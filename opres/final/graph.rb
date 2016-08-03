# a program to generate weighted (nodes & edges) undirected graphs 
# and also write these out in a format that is suitable for 
# different integer programming problems in the SCIP-solver

class CompleteBipartiteGraph
  attr_accessor :n, :edges, :facility

  def initialize(n)
    prng = Random.new
    @n = n
    @edges = []
    @facility = []
    (0...n/2).each do |u|
      @facility << prng.rand(1..100) 
      @edges << Array.new(n/2)
    end
  end

  def add_edge(u,v,c)
    return if u >= n/2 or v < n/2

    @edges[u][v % (n/2)] = c
  end

  def num_edges
    n*(n/2)
  end

end


def print_lp_form(g)
  puts "minimize"

  objective = " "

  (0...g.n/2).each do |u| 
    (g.n/2...g.n).each do |v|
      objective <<" #{g.edges[u][v% (g.n/2)]}x_#{u}_#{v} +"
    end
  end
  g.facility.each_with_index do |f,i|
    objective << " #{f}y_#{i} +"
  end
  puts objective[0..-2]

  puts "subject to"

  (0...g.n/2).each do |u| 
    constraint = ""
    (g.n/2...g.n).each do |v|
      constraint << "x_#{u}_#{v} +"
    end
    puts constraint[0..-2] + " >= 1"
  end


  (0...g.n/2).each do |u| 
    (g.n/2...g.n).each do |v|
      puts "y_#{u} - x_#{u}_#{v} >= 0"
    end
  end

  puts "binary"

  (0...g.n/2).each do |u| 
    (g.n/2...g.n).each do |v|
      puts "x_#{u}_#{v}"
    end
  end
  (0...g.n/2).each do |u| 
    puts "y_#{u}"
  end


end

def generate_complete_bipartite_graph(n)
  if not n%2==0
    puts "bipartite graph needs an even number of nodes"
    return nil
  end


  generator = Random.new
  g = CompleteBipartiteGraph.new(n)

  (0...n/2).each do |u|
    (n/2...n).each do |v|
      cost = generator.rand(1..100)
      g.add_edge(u,v,cost)
    end
  end
  g
end



n = 10
g = generate_complete_bipartite_graph(n)


print_lp_form(g)

