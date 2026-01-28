#include <iostream>
#include <vector>
#include <queue>
using namespace std;


void BFShelper(int src, vector<int> Graph[], vector<int> &parent, vector<int> &visited, int n){
    queue<int> q;
    q.push(1);
    visited[1] = 1;


    while(!q.empty()){
        int curr = q.front();
        //cout << curr << endl;
        q.pop();

        for(int v: Graph[curr]){
            if(visited[v] == 0){
                q.push(v);
                //cout << v << endl;
                visited[v] = 1;
                parent[v] = curr;
            }

        }
    }

}



void BFS(vector<int> Graph[], int n){
    int src = 1;
    vector<int> parent(n + 1, -1);
    vector<int> visited(n + 1, 0);


    BFShelper(src, Graph, parent, visited, n);

    for(int i = 1; i <= n; i++){

        if(visited[i] == 0){
            cout << "-1" <<endl;
            return;
        }
    }

    int curr = n;
    int c = 0;
    while(curr != 1){
        c++;
        curr = parent[curr];

    }

    cout << c <<  endl;
}




int main(){
    int n, m;
    cin >> n >> m;

    vector<int> Graph[n + 1];

    for(int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        Graph[u].push_back(v);
        Graph[v].push_back(u);
    }


    BFS(Graph, n);



    return 0;
}



/*
4 3
1 2
2 3
3 4
*/
