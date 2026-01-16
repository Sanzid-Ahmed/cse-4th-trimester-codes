#include <iostream>
#include <vector>
#include <queue>
using namespace std;



void bfsHelper(int src, vector<int> Graph[], vector<int> &visited){
    queue<int> q;
    q.push(src);
    visited[src] = 1;
    //int count = 0;

    while(!q.empty()){
        int curr = q.front();
        q.pop();


        for(int v: Graph[curr]){
            if(!visited[v]){
                visited[v] = 1;
                q.push(v);
                //count++;
                }

        }
    }

    //cout << count << endl;
}




void bfs(vector<int> Graph[], int n){
    vector<int> visited(n, 0);
    int k;
    cin >> k;
    bfsHelper(k, Graph, visited);

    for(int i = 0; i < n; i++){
        if(!visited[i]){
            cout << "-1" << endl;
            return;
        }
    }

    cout << n - 1 << endl;
}



int main(){
    int n, m;
    cin >> n >> m;
    vector<int> Graph[n + 1];

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        Graph[u].push_back(v);
        Graph[v].push_back(u);
    }

    bfs(Graph, n);

    return 0;
}
