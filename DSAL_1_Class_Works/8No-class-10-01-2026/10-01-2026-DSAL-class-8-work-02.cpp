#include <iostream>
#include <vector>

using namespace std;


int main(){
    vector<int> a;


    a.push_back(10);
    a.push_back(20);
    a.push_back(30);


    for(int i = 0; i < a.size(); i++){
        cout << a[i] << endl;
    }

    cout << endl;
    for(int x : a){
        cout << x << endl;
    }
}
