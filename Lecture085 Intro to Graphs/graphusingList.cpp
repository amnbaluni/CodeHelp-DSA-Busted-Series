// Online C++ compiler to run C++ program online
#include <iostream>
#include<unordered_map>
#include<list>
using namespace std;

class Graph{
    public:
    unordered_map<int, list<int>> adj;
    void addEdge(int  u, int v, bool direction){
        //0->undirected
        //1->directed
        //create an edge from u to v
        adj[u].push_back(v);
        
        if(direction==0){
            adj[v].push_back(u);
        }
    }
    void printList(){
        for(auto i:adj){
            cout<<i.first<<"->";
            for(auto j:i.second){
                cout<<j<<", ";
            }
            cout<<endl;
        }
    }
};
int main() {
    int n;
    cout<<"Enter the no of nodes";
    cin>>n;
    int m;
    cout<<"Enter the no of edges";
    cin>>m;
    
    Graph g;
    
    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        //creating undirected graph
        g.addEdge(u,v,0);
    }
    g.printList();

    return 0;
}
