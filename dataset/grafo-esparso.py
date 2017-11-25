from random import randint

# quantidade de nós/vertices do grafo 
quantity_node = 100
# peso mínimo de uma aresta
min_range_weight = 0
# peso máximo de uma aresta
max_range_weight = 10

# criando arquivo
f = open("graph-esparso.txt","w+")

# escrevendo a quantidade de vertices
f.write("%d\n" % quantity_node)

# no inicial
x = 0

# gerando um grafo 'simples'
while x < (quantity_node-1):
	range_weight = randint(min_range_weight, max_range_weight)
	y = x + 1
	f.write("%d,%d,%d\n" % (x,y,range_weight))
	print ("valor da variavel (%d,%d,%d) " % (x,y,range_weight))
	x = x + 1
		
f.close() 
