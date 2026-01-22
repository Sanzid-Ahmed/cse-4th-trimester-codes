#include <iostream>
#include <vector>
#include <queue>
using namespace std;




void BFShelper(int a, int b, vector<int> Graph[], vector<int> &visited, vector<int> &depth){
    queue<int> q;
    queue<int> q2;
    q.push(a);
    q2.push(b);

    visited[a] = 1;
    visited[b] = 1;


    while(!q.empty() || !q2.empty()){
        if(!q.empty()){
            int curr = q.front();
            q.pop();

            for(int v : Graph[curr]){
                if(visited[v] == 0){
                    q.push(v);
                    visited[v] = 1;
                    depth[v] = depth[curr] + 1;
                }
            }
        }
        if(!q2.empty()){
            int curr = q2.front();
            q2.pop();

            for(int v : Graph[curr]){
                if(visited[v] == 0){
                    q2.push(v);
                    visited[v] = 1;
                    depth[v] = depth[curr] + 1;
                }
            }
        }


    }
}

/*
1 = run
!1 = not run

q.empty() = true
!q.empty() = !true -> false

false || false = false
*/


void BFS(vector<int> Graph[], int V){
    int a, b;
    cin >> a >> b;

    vector<int> visited(V + 1, 0);
    vector<int> depth(V + 1, 0);

    BFShelper(a, b, Graph, visited, depth);

    int time = 0;
    for(int i = 1; i <= V; i++){
        if(!visited[i]){
            cout << "-1";
            return;
        }
        if(depth[i] > time){
            time = depth[i];
        }
    }

    cout << time << endl;
}

int main(){
    int V, E;
    cin >> V >> E;

    vector<int> Graph[V + 1];
    for(int i = 1; i <= E; i++){
        int from, to;
        cin >> from >> to;
        Graph[from].push_back(to);
        Graph[to].push_back(from);
    }

    BFS(Graph, V);

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
