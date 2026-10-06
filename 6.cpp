#include <iostream>
using namespace std;

class DijkstraAlgorithm{
    const int INF = 999999;
    int vertices;
    int** graph;
    
    int minDistance(int dist[], bool visited[]){
        int min = INF;
        int min_index = -1;
        
        for (int v = 0; v < vertices; v++){
            if (!visited[v] && dist[v] <= min){
                min = dist[v];
                min_index = v;
            }
        }
        return min_index;
    }
    
    void printPath(int parent[], int target, char nodes[]){
        if (parent[target] == -1){
            cout << nodes[target];
            return;
        }
        printPath(parent, parent[target], nodes);
        cout << " -> " << nodes[target];
    }

public:
    DijkstraAlgorithm(){
        vertices = 6;
        
        graph = new int*[vertices];
        for (int i = 0; i < vertices; i++){
            graph[i] = new int[vertices];
            for (int j = 0; j < vertices; j++){graph[i][j] = INF;}
            graph[i][i] = 0;
        }

        graph[0][1] = 4;
        graph[0][3] = 8;
        graph[1][0] = 4;
        graph[1][2] = 9;
        graph[1][3] = 8;
        graph[2][1] = 9;
        graph[2][4] = 6;
        graph[2][5] = 14;
        graph[3][0] = 8;
        graph[3][1] = 8;
        graph[3][4] = 3;
        graph[3][5] = 3;
        graph[4][2] = 6;
        graph[4][3] = 3;
        graph[4][5] = 3;
        graph[5][2] = 14;
        graph[5][3] = 3;
        graph[5][4] = 3;
    }
    
    ~DijkstraAlgorithm(){
        for (int i = 0; i < vertices; i++){delete[] graph[i];}
        delete[] graph;
    }
    
    void findShortestPath(char source_char, char target_char){
        char nodes[] = {'A', 'B', 'C', 'D', 'E', 'F'};
        int source = -1, target = -1;
        
        for (int i = 0; i < vertices; i++){
            if (nodes[i] == source_char){source = i;}
            if (nodes[i] == target_char){target = i;}
        }
        
        if (source == -1 || target == -1){
            cout << "Invalid nodes!" << endl;
            return;
        }
        
        int dist[vertices];
        bool visited[vertices];
        int parent[vertices];

        for (int i = 0; i < vertices; i++){
            dist[i] = INF;
            visited[i] = false;
            parent[i] = -1;
        }
        
        dist[source] = 0;
        cout << "Dijkstra's Algorithm Steps:" << endl;
        cout << "Starting from node: " << source_char << endl;
        cout << "Looking for node: " << target_char << endl;
        cout << endl << endl;
        
        for (int count = 0; count < vertices - 1; count++){
            int u = minDistance(dist, visited);
            if (u == -1){break;}
            visited[u] = true;
            
            cout << "Step " << (count + 1) << ": Selected node " << nodes[u] << 
            " (distance: " << dist[u] << ")" << endl;
            
            for (int v = 0; v < vertices; v++){
                if (!visited[v] && graph[u][v] != INF && dist[u] != INF &&
                    dist[u] + graph[u][v] < dist[v]){
                    int old_dist = dist[v];
                    dist[v] = dist[u] + graph[u][v];
                    parent[v] = u;
                    cout << "  -> Updated " << nodes[v] << ": " << old_dist << " -> " 
                    << dist[v] << " (via " << nodes[u] << ")" << endl;
                }
            }
            cout << endl << endl;
            if (u == target){break;}
        }
        
        cout << "\n=== FINAL RESULTS ===" << endl;
        if (dist[target] == INF){
            cout << "No path exists from " << source_char << " to " << target_char << endl;} 
        else{
            cout << "Shortest path from " << source_char << " to " << target_char << ":" << endl;
            cout << "Path: ";
            printPath(parent, target, nodes);
            cout << endl;
            cout << "Total distance: " << dist[target] << endl;
        }
        
        cout << "\nAll distances from node " << source_char << ":" << endl;
        for (int i = 0; i < vertices; i++){
            cout << "To " << nodes[i] << ": ";
            if (dist[i] == INF) {cout << "Unreachable";} 
            else {cout << dist[i];}
            cout << endl;
        }
    }
    
    void displayGraph(){
        char nodes[] = {'A', 'B', 'C', 'D', 'E', 'F'};
        
        cout << "Graph Adjacency Matrix:" << endl;
        cout << "-------------" << endl;
        cout << "    A    B    C    D    E    F" << endl;
        
        for (int i = 0; i < vertices; i++){
            cout << nodes[i] << "   ";

            for (int j = 0; j < vertices; j++){
                if (graph[i][j] == INF) {cout << "INF  ";} 
                else{
                    if (graph[i][j] < 10){cout << " ";}
                    cout << graph[i][j] << "   ";
                }
            }
            cout << endl;
        }
        cout << endl;
        
        cout << "Graph Connections:" << endl;
        cout << endl;
        for (int i = 0; i < vertices; i++){
            cout << nodes[i] << " -> ";
            bool first = true;

            for (int j = 0; j < vertices; j++){
                if (i != j && graph[i][j] != INF){
                    if (!first){cout << ", ";}
                    cout << nodes[j] << "(" << graph[i][j] << ")";
                    first = false;
                }
            }
            cout << endl;
        }
        cout << endl;
    }
};

int main(){
    DijkstraAlgorithm dijkstra;
    
    cout << " DIJKSTRA'S ALGORITHM" << endl;
    cout << "Finding shortest path from B to E" << endl << endl;
    
    dijkstra.displayGraph();
    dijkstra.findShortestPath('B', 'E');
    
    cout << "\nADDITIONAL TEST" << endl;
    dijkstra.findShortestPath('B', 'F');
    
    return 0;
}