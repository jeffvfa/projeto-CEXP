// C++ program for Kruskal's algorithm to find Minimum
// Spanning Tree of a given connected, undirected and
// weighted graph
#include <bits/stdc++.h>
#include <time.h>
using namespace std;

// Creating shortcut for an integer pair
typedef pair<int, int> iPair;

// Structure to represe nt a graph
struct Graph
{
	int V, E;
	vector< pair<int, iPair> > edges;

	// Constructor
	Graph(int V, int E)
	{
		this->V = V;
		this->E = E;
	}

	// Utility function to add an edge
	void addEdge(int u, int v, int w)
	{
		edges.push_back({w, {u, v}});
	}

	// Function to find MST using Kruskal's
	// MST algorithm
	int kruskalMST();
};

// To represent Disjoint Sets
struct DisjointSets
{
	int *parent, *rnk;
	int n;

	// Constructor.
	DisjointSets(int n)
	{
		// Allocate memory
		this->n = n;
		parent = new int[n+1];
		rnk = new int[n+1];

		// Initially, all vertices are in
		// different sets and have rank 0.
		for (int i = 0; i <= n; i++)
		{
			rnk[i] = 0;

			//every element is parent of itself
			parent[i] = i;
		}
	}

	// Find the parent of a node 'u'
	// Path Compression
	int find(int u)
	{
		/* Make the parent of the nodes in the path
		from u--> parent[u] point to parent[u] */
		if (u != parent[u])
			parent[u] = find(parent[u]);
		return parent[u];
	}

	// Union by rank
	void merge(int x, int y)
	{
		x = find(x), y = find(y);

		/* Make tree with smaller height
		a subtree of the other tree */
		if (rnk[x] > rnk[y])
			parent[y] = x;
		else // If rnk[x] <= rnk[y]
			parent[x] = y;

		if (rnk[x] == rnk[y])
			rnk[y]++;
	}
};

/* Functions returns weight of the MST*/

int Graph::kruskalMST()
{
	int mst_wt = 0; // Initialize result

	// Sort edges in increasing order on basis of cost
	sort(edges.begin(), edges.end());

	// Create disjoint sets
	DisjointSets ds(V);

	// Iterate through all sorted edges
	vector< pair<int, iPair> >::iterator it;
	for (it=edges.begin(); it!=edges.end(); it++)
	{
		int u = it->second.first;
		int v = it->second.second;

		int set_u = ds.find(u);
		int set_v = ds.find(v);

		// Check if the selected edge is creating
		// a cycle or not (Cycle is created if u
		// and v belong to same set)
		if (set_u != set_v)
		{
			// Current edge will be in the MST
			// so print it
			cout << u << " - " << v << endl;

			// Update MST weight
			mst_wt += it->first;

			// Merge two sets
			ds.merge(set_u, set_v);
		}
	}

	return mst_wt;
}

int countlines(char *filename){
  // count the number of lines in the file called filename                                    
  FILE *fp = fopen(filename,"r");
  int ch=0;
  int lines=0;

  if (fp == NULL);
  return 0;

  lines++;
  while ((ch = fgetc(fp)) != EOF)
    {
      if (ch == '\n')
    lines++;
    }
  fclose(fp);
  return lines;
}

// Driver program to test above functions
int main(){
	FILE *file_input;
	file_input = fopen("input.txt","r");
	char a[999],b[999],c[999],v[999];
	int ch=0;
	int lines=0;

	if (file_input == NULL){
		return 0;
	}
	fscanf(file_input, "%s\n", v);
	lines++;
	while ((ch = fgetc(file_input)) != EOF){
		if (ch == '\n'){
			lines++;
		}
	}
	fclose(file_input);

	printf("%d %d\n",atoi(v),lines);
	Graph g(atoi(v), lines);
	file_input = fopen("input.txt","r");
	if(file_input){
		fscanf(file_input, "%s\n", v);
	    printf("%s\n",v);
		while ((fscanf(file_input, "%s %s %s\n", a,b,c))!=EOF){
	        printf("%s %s %s\n",a,b,c);
	        g.addEdge(atoi(a),atoi(b),atoi(c));
		}	
	}
	fclose(file_input);


	/* Let us create above shown weighted
	and unidrected graph */
	int V = 9, E = 14;

	// making above shown graph

	clock_t tStart = clock();
	cout << "Edges of MST are \n";
	int mst_wt = g.kruskalMST();
	cout << "\nWeight of MST is " << mst_wt << "\n";
	printf("Time taken: %fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
	return 0;
}