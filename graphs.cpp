#include <iostream>
using namespace std;

#define MAXVERTEXS 50
#define TRUE 1
#define FALSE 0

struct edge
{
    int adj;
    int weight;
};

class WeightedGraph 
{
private:
    edge matrix[MAXVERTEXS][MAXVERTEXS];
    int numVertices;

public:
    WeightedGraph(int n) 
    {
        numVertices = n;
        for (int i = 0; i < numVertices; i++) {
            for (int j = 0; j < numVertices; j++) 
            {
                matrix[i][j].adj = FALSE;
                matrix[i][j].weight = 0;
            }
        }
    }

    void addEdge(int from, int to, int weight) 
    {
        if (from < numVertices && to < numVertices) 
        {
            matrix[from][to].adj = TRUE;
            matrix[from][to].weight = weight;
        }
    }

    void removeEdge(int from, int to) 
    {
        if (from < numVertices && to < numVertices) 
        {
            matrix[from][to].adj = FALSE;
            matrix[from][to].weight = 0;
        }
    }

    bool isAdjacent(int from, int to) 
    {
        if (from < numVertices && to < numVertices) 
        {
            return (matrix[from][to].adj == TRUE);
        }
        return false;
    }

    int getWeight(int from, int to) 
    {
        if (isAdjacent(from, to)) 
        {
            return matrix[from][to].weight;
        }
        return 0;
    }

    void display() 
    {
        cout << "  ";
        for (int i = 0; i < numVertices; i++) 
        {
            cout << i << " ";
        }
        cout << endl;

        for (int i = 0; i < numVertices; i++) 
        {
            cout << i << " ";
            for (int j = 0; j < numVertices; j++) 
            {
                if (matrix[i][j].adj == TRUE) 
                {
                    cout << matrix[i][j].weight << " ";
                } else 
                {
                    cout << "0 ";
                }
            }
            cout << endl;
        }
    }
};

int main() 
{
    cout << "Graph created with 4 vertices.\n\n";

    WeightedGraph g(4);

    cout << "Adding weighted edges:\n";
    cout << "0->1 (weight 5)\n"; g.addEdge(0, 1, 5);
    cout << "0->2 (weight 3)\n"; g.addEdge(0, 2, 3);
    cout << "1->2 (weight 2)\n"; g.addEdge(1, 2, 2);
    cout << "1->3 (weight 4)\n"; g.addEdge(1, 3, 4);
    cout << "2->3 (weight 1)\n\n"; g.addEdge(2, 3, 1);

    cout << "Adjacency Matrix (with weights):\n";
    g.display();
    cout << "\n";

 
    cout << "Checking adjacency:\n";
    
    cout << "0->1: ";
    if (g.isAdjacent(0, 1)) cout << "Yes, weight = " << g.getWeight(0, 1) << "\n"; else cout << "No\n";
    
    cout << "1->0: ";
    if (g.isAdjacent(1, 0)) cout << "Yes, weight = " << g.getWeight(1, 0) << "\n"; else cout << "No\n";
    
    cout << "2->3: ";
    if (g.isAdjacent(2, 3)) cout << "Yes, weight = " << g.getWeight(2, 3) << "\n"; else cout << "No\n";
    
    cout << "\nRemoving edge 1->2\n";
    g.removeEdge(1, 2);
    
    cout << "After removal:\n";
    g.display();

    return 0;
}