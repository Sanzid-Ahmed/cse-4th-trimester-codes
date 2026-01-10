#include <iostream>
using namespace std;


int main(){
    //First we need to take input the number of vertex and number of edge.
    int V, E;
    cin >> V >> E;
    cout << V << " "<<E << endl;


    //int Graph[V + 1][V + 1] = {0};
    int Graph[V + 1][V + 1];
    for(int i = 1; i <= V; i++){
        for(int j = 1; j <= V; j++){
            Graph[i][j] = 0;
        }
    }

    cout << endl;
    //Number of Edge represent the number of input pares.
    for(int i = 0 ; i < E; i++){
        int u, v;
        cin >> u >> v;
        Graph[u][v] = 1;
    }





    for(int i = 1; i <= V; i++){
        for(int j = 1; j <= V; j++){
            cout << Graph[i][j] << " ";
        }
        cout << endl;
    }



    cout << endl;

    for(int i = 1; i <= V; i++){
        for(int j = 1; j <= V; j++){
            if(Graph[i][j] == 1){
               cout << i << " " << j << endl;;
            }
        }
    }





    cout << endl;
    int Graph2[V + 1][V + 1];
    for(int i = 1; i <= V; i++){
        for(int j = 1; j <= V; j++){
            Graph2[i][j] = 0;
        }
    }


    cout << endl;
    for(int i = 0 ; i < E; i++){
        int u, v;
        cin >> u >> v;
        Graph2[u][v] = 1;
        Graph2[v][u] = 1;
    }


    cout << endl;
    for(int i = 1; i <= V; i++){
        for(int j = 1; j <= V; j++){
            cout << Graph2[i][j] << " ";
        }
        cout << endl;
    }

}



/*
1 2
1 5
1 4
5 4
3 4
3 2
*/
