#include <iostream>
#include <vector>
#include <queue>
using namespace std;


void bfsHelper(int src, vector<int> Graph[], vector<int> &visited){
    visited[src] = 1;
    queue<int> q;
    q.push(src);


    while(!q.empty()){
        int curr = q.front();
        q.pop();

        for(int v: Graph[curr]){
            if(!visited[v]){
                ///forget to give this one.
                visited[v] = 1;
                q.push(v);
            }
        }
    }
}



void bfs(vector<int> Graph[], int V){
    vector<int> visited(V, 0);
    int src;
    cin >> src;

    bfsHelper(src, Graph, visited);


    int count = 1;
    for(int i = 0; i < V; i++){
        if(!visited[i]){
            count++;
            bfsHelper(i, Graph, visited);
        }
    }

    cout << count << endl;
}



int main(){
    int V, E;
    cin >> V >> E;

    vector<int> Graph[V + 1];

    for(int i = 0; i < E; i++){
        int u, v;
        cin >> u >> v;

        Graph[u].push_back(v);
        Graph[v].push_back(u);
    }


    bfs(Graph, V);
}
