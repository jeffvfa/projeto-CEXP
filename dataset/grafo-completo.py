from random import randint

# quantidade de nós/vertices do grafo 
quantity_node = 10000
# peso mínimo de uma aresta
min_range_weight = 0
# peso máximo de uma aresta
max_range_weight = 10

# criando arquivo
f= open("grafo-completo-10000.txt","w+")

# escrevendo a quantidade de vertices
f.write("%d\n" % quantity_node)

# gerando um grafo completo
for x in range(0, quantity_node):
	print("Nó: %d\n" % (x))
	for y in range((x+1), quantity_node):
		range_weight = randint(min_range_weight, max_range_weight)
		f.write("%d %d %d\n" % (x,y,range_weight))
		# print ("Vertice: (%d,%d,%d) " % (x,y,range_weight))

f.close() 
