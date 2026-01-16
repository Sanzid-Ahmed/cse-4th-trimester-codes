#include <iostream>
#include <vector>
#include <queue>

using namespace std;




void bfs(vector<int> Graph[], int V, int src, int parent[], int depth[]){
    int vis[V + 1] = {0};
    queue<int> q;


    vis[src] = 1;
    parent[src] = -1;

    q.push(src);
    depth[src] = 0;



    //queue function-> 1 .empty() fuction.
    while(q.empty() == false){
        //queue function-> 2 .front() fuction.
        int u = q.front();
        //queue function-> 3 .pop() fuction.
        q.pop();
        cout << u << " ";
        for(int v : Graph[u]){
            if(vis[v] == 0){
                vis[v] = 1;
                q.push(v);
                parent[v] = u;
                depth[v] = depth[u] + 1;
            }
        }
    }
    cout << endl;

}





int main(){
    int V, E;
    cin >> V >> E;


    vector<int> Graph[V + 1];
    int parent[V];
    int depth[V];


    for(int i = 0; i < E; i++){
        int u, v;

        cin >> u >> v;
        Graph [u].push_back(v);
        Graph [v].push_back(u);
    }





    bfs(Graph, V, 0, parent, depth);

    for(int i = 0; i < V; i++){
        cout << i << "-> " << parent[i]<< ", " << depth[i] <<   endl;
    }

    ///Find the sorted path from 0 to 4

        cout << depth[4]<< endl;

        int dest = 4, src = 0;
        cout << dest << " ";
        vector<int> path;
        path.push_back(dest);
        while(dest != src){
            dest = parent[dest];
            cout << dest << " ";
            path.push_back(dest);
        }

        cout << endl;

        for(int i = path.size() - 1; i >= 0; i--){
            cout << path[i] << " ";
        }





    /*
    for(int i = 1; i <=V; i++){

        cout << i << " -> ";

        for(int v : Graph[i]){
            cout << v << " ";
        }

        cout << endl;
    }
    */
}




/*
9 11
0 6
3 6
5 6
5 4
5 2
5 1
4 2
1 2
1 7
2 8
7 8

*/
