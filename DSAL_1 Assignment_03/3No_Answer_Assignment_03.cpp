#include <iostream>
#include <vector>
#include <queue>
using namespace std;




int bfsHelper(int src, vector<int> Graph[], vector<int> &visited){
    queue<int> q;
    q.push(src);
    visited[src] = 1;
    int last = src;

    while(!q.empty()){
        int curr = q.front();
        q.pop();
        last = curr;

        for(int v : Graph[curr]){
            if(!visited[v]){
                visited[v] = 1;
                //parent[v] = curr;
                q.push(v);
            }
        }
    }


    return last;
}



void bfs(vector<int> Graph[], int n){
    int src = 0;
    vector<int> visited(n, 0);
    //vector<int> parent(n, -1);

    int last = bfsHelper(src, Graph, visited);

    for(int i = 0; i < n; i++){
        if(!visited[i]){
            cout << "-1 -1" << endl;
            return;
        }
    }

    vector<int> visited2(n, 0);
    int last2 = bfsHelper(last, Graph, visited2);


    cout << last << " " << last2;
}



int main(){
    int n, m;
    cin>> n >> m;


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
