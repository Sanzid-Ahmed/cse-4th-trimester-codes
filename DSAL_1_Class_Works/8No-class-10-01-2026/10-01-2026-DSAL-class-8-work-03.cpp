#include <iostream>
#include <vector>

using namespace std;


int main(){
    int V, E;
    cin >> V >> E;


    vector<int> Graph[V + 1];


    for(int i = 0; i < E; i++){
        int u, v;

        cin >> u >> v;
        Graph [u].push_back(v);
        Graph [v].push_back(u);
    }


    for(int i = 1; i <=V; i++){

        cout << i << " -> ";

        for(int v : Graph[i]){
            cout << v << " ";
        }

        cout << endl;
    }
}
