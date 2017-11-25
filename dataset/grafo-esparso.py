from random import randint

# quantidade de nós/vertices do grafo 
quantity_node = 10000
# peso mínimo de uma aresta
min_range_weight = 0
# peso máximo de uma aresta
max_range_weight = 10

# criando arquivo
f = open("grafo-esparso-10000.txt","w+")

# escrevendo a quantidade de vertices
f.write("%d\n" % quantity_node)

# no inicial
x = 0

# gerando um grafo 'simples'
while x < (quantity_node-1):
	range_weight = randint(min_range_weight, max_range_weight)
	y = x + 1
	f.write("%d %d %d\n" % (x,y,range_weight))
	print ("Vertices: (%d,%d,%d) " % (x,y,range_weight))
	x = x + 1
		
f.close() 
