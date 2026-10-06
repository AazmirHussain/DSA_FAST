#include <iostream>
using namespace std;
class Graph{
    int vertices;
    int** adjMatrix;
    int* visited;
    
    void DFSRecursive(int vertex){
        visited[vertex] = 1;
        cout << vertex << " ";
        
        for (int i = 0; i < vertices; i++){
            if (adjMatrix[vertex][i] == 1 && !visited[i]){DFSRecursive(i);}
        }
    }

public:
    Graph(int v){
        vertices = v;
        
        adjMatrix = new int*[vertices];
        for (int i = 0; i < vertices; i++){
            adjMatrix[i] = new int[vertices];
            for (int j = 0; j < vertices; j++){adjMatrix[i][j] = 0;}
        }
        
        visited = new int[vertices];
        resetVisited();
    }
    
    ~Graph(){
        for (int i = 0; i < vertices; i++){delete[] adjMatrix[i];}
        delete[] adjMatrix;
        delete[] visited;
    }
    
    void resetVisited(){
        for (int i = 0; i < vertices; i++){visited[i] = 0;}
    }
    
    void addEdge(int src, int dest){
        adjMatrix[src][dest] = 1;
        adjMatrix[dest][src] = 1;
    }
    
    void displayAdjacencyMatrix(){
        cout << "Adjacency Matrix:" << endl;
        cout << "  ";
        for (int i = 0; i < vertices; i++){cout << i << " ";}
        cout << endl;
        
        for (int i = 0; i < vertices; i++){
            cout << i << " ";
            for (int j = 0; j < vertices; j++){cout << adjMatrix[i][j] << " ";}
            cout << endl;
        }
        cout << endl;
    }
    
    void displayAdjacencyList(){
        cout << "Adjacency List:" << endl;
        for (int i = 0; i < vertices; i++){
            cout << i << " -> ";
            bool first = true;
            for (int j = 0; j < vertices; j++){
                if (adjMatrix[i][j] == 1){
                    if (!first){cout << ", ";}
                    cout << j;
                    first = false;
                }
            }
            cout << endl;
        }
        cout << endl;
    }
    
    void BFS(int startVertex){
        resetVisited();
        cout << "BFS Traversal: ";
        
        int queue[vertices];
        int front = 0, rear = 0;
        visited[startVertex] = 1;
        queue[rear++] = startVertex;
        
        while (front < rear){
            int current = queue[front++];
            cout << current << " ";
            
            for (int i = 0; i < vertices; i++){
                if (adjMatrix[current][i] == 1 && !visited[i]){
                    visited[i] = 1;
                    queue[rear++] = i;
                }
            }
        }
        cout << endl;
    }
    
    void DFS(int startVertex){
        resetVisited();
        cout << "DFS Traversal: ";
        DFSRecursive(startVertex);
        cout << endl;
    }
    
    void DFSIterative(int startVertex){
        resetVisited();
        cout << "DFS Iterative: ";
        
        int stack[vertices];
        int top = -1;
        stack[++top] = startVertex;
        
        while (top >= 0){
            int current = stack[top--];
            
            if (!visited[current]){
                visited[current] = 1;
                cout << current << " ";
                
                for (int i = vertices - 1; i >= 0; i--){
                    if (adjMatrix[current][i] == 1 && !visited[i]){stack[++top] = i;}
                }
            }
        }
        cout << endl;
    }
};

int main(){
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    
    cout << "=== GRAPH IMPLEMENTATION ===" << endl << endl;
    g.displayAdjacencyList();
    g.displayAdjacencyMatrix();
    
    cout << "=== GRAPH TRAVERSALS ===" << endl;
    g.BFS(0);
    g.DFS(0);
    g.DFSIterative(0);
    
    cout << endl << "=== BFS FROM ALL VERTICES ===" << endl;
    for (int i = 0; i < 5; i++){
        cout << "Start at " << i << ": ";
        g.BFS(i);
    }
    
    return 0;
}