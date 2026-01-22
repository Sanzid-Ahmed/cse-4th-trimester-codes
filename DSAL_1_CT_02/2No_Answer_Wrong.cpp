#include<iostream>
#include<vector>
#include <queue>
using namespace std;

int BFShelper(int S, int D, vector<int> Graph[], vector<int> &visited){
    queue<int> q;
    queue<int> q2;
    q.push(S);
    q2.push(D);
    visited[S] = 1;
    visited[D] = 1;

    int c = 0;
    while(!q.empty()){
        int curr = q.front();
        int curr2 = q2.front();
        q.pop();
        q2.pop();
        /*
        for(int i = 0; i < Graph[curr].size() || Graph[curr2].size(); i++){
            int flag = 0;
            if(!visited[i]){
                q.push(i);
                //parent[v] = curr;
                visited[i] = 1;
                flag = 1;
                //cout << "-1" << endl;

            }
            if(!visited[i]){
                q2.push(i);
                visited[i] = 1;
                flag = 1;
                //cout << "-1" << endl;
            }
            if(flag = 1){
                count++;
            }
        }
        */
        int flag = 0;
        for(int v: Graph[curr]){
            if(!visited[v]){
                q.push(v);
                //parent[v] = curr;
                visited[v] = 1;
                int flag = 1;
            }
        }
        for(int v: Graph[curr2]){
            if(!visited[v]){
                q2.push(v);
                //parent[v] = curr;
                visited[v] = 1;
                int flag = 1;
            }
        }
        if(flag = 1){
                c++;
        }
    }

    return c;
}



void BFS(vector<int> Graph[], int V){
    int S, D;
    cin >> S >> D;

    vector<int> parent(V, -1);
    vector<int> visited(V, 0);
    int result = BFShelper(S, D, Graph, visited);

    for(int i = 0; i < V; i++){
        if(!visited[i]){
            cout << "-1" << endl;
            return;
        }

    }

    cout<< result << endl;

}












int main(){

    int N, M;
    cin >> N >> M;

    vector<int> Graph[N + 1];

    for(int i = 0; i < M; i++){
        int u, v;
        cin >> u >> v;
        Graph[u].push_back(v);
        Graph[v].push_back(u);
    }

    //cout << "Hello" <<endl;

    BFS(Graph, N);


    return 0;
}

/*
6 6
1 2
1 3
1 6
2 3
2 4
5 6
2 6
*/
