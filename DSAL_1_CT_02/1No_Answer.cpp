#include<iostream>
#include<vector>
#include <queue>
using namespace std;


BFShelper(int S, vector<int> Graph[], vector<int> &parent, vector<int> visited){
    queue<int> q;
    q.push(S);
    visited[S] = 1;

    while(!q.empty()){
        int curr = q.front();
        q.pop();

        for(int v: Graph[curr]){
            if(!visited[v]){
                q.push(v);
                parent[v] = curr;
                visited[v] = 1;
            }
        }
    }
}


void BFS(vector<int> Graph[], int F, int V){
    int S, D;
    cin >> S >> D;

    vector<int> parent(V, -1);
    vector<int> visited(V, 0);

    BFShelper(S, Graph, parent, visited);


    int curr = D;
    int valid = F;
    while(curr != -1){
        valid--;
        curr = parent[curr];
    }

    if(valid < 0){
        cout << "no" << endl;
    }
    else{
        cout << "Yes" << endl;
    }
}



int main(){

    int N, M, F;
    cin >> N >> M >> F;

    vector<int> Graph[N + 1];

    for(int i = 0; i < M; i++){
        int u, v;
        cin >> u >> v;
        Graph[u].push_back(v);
        Graph[v].push_back(u);
    }

    //cout << "Hello" <<endl;

    BFS(Graph, F, N);


    return 0;
}


/*
6 5 9
2 3
4 5
1 2
5 6
3 4
1 4
*/
